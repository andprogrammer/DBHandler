--
-- PostgreSQL database dump
--

-- Dumped from database version 9.6.3
-- Dumped by pg_dump version 9.6.3

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET search_path = public, pg_catalog;

--
-- Name: get_player_data_function(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION get_player_data_function() RETURNS TABLE(player_id integer, player_login character, player_password character)
    LANGUAGE plpgsql STABLE
    AS $$
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
$$;


ALTER FUNCTION public.get_player_data_function() OWNER TO postgres;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: player; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE player (
    id integer NOT NULL,
    login character(50) NOT NULL,
    password character(50) NOT NULL
);


ALTER TABLE player OWNER TO postgres;

--
-- Data for Name: player; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY player (id, login, password) FROM stdin;
1	Jack                                              	J2                                                
2	Bob                                               	O45T                                              
\.


--
-- Name: player player_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY player
    ADD CONSTRAINT player_pkey PRIMARY KEY (id);


--
-- PostgreSQL database dump complete
--

