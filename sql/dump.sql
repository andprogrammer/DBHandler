*********************************************************************
CREATE TABLE player
(
   id INT PRIMARY KEY NOT NULL,
   login CHAR(50) NOT NULL,
   password CHAR(50) NOT NULL
);
*********************************************************************
INSERT INTO player VALUES(1, 'Jack', 'J2');
INSERT INTO player VALUES(2, 'Bob', 'O45T');
*********************************************************************
SELECT 
    player.id AS player_id, 
    player.login AS player_login, 
    player.password AS player_password
FROM player;
*********************************************************************
CREATE OR REPLACE FUNCTION get_player_data_function()
RETURNS TABLE
(
  player_id INT,
  player_login CHAR(255),
  player_password CHAR(255)
) AS
$BODY$
BEGIN
  FOR player_id, player_login, player_password IN
    SELECT 
      player.id AS player_id, 
      player.login AS player_login, 
      player.password AS player_password
    FROM player
  LOOP
    RETURN NEXT;
  END LOOP;
END
$BODY$ LANGUAGE plpgsql STABLE;
*********************************************************************
SELECT * FROM get_player_data_function();
*********************************************************************
drop function get_player_data_function();
*********************************************************************
drop table player;
*********************************************************************
