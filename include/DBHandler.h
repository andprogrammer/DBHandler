// Database Handler (Singleton)
#ifndef DBHANDLER_H
#define DBHANDLER_H
#include <pqxx/pqxx>
#include "Functions.h"


namespace DB
{

namespace SERVICES
{

class DBHandler
{
private:
  static DBHandler *m_instance;

public:
  static DBHandler& getInstance();
  static void deleteInstance();

protected:
  DB::FUNCTIONS::DBConfigData m_dbconfig;

private:
  DBHandler(DB::FUNCTIONS::DBConfigData l_dbconfig);
  DBHandler(std::string p_db_name,
            std::string p_db_username,
            std::string p_db_password,
            std::string p_db_hostname,
            std::string p_db_port);
  DBHandler(const DBHandler &p_dbHandler) = delete;
  DBHandler(DBHandler &&p_dbHandler) = delete;
  DBHandler& operator=(const DBHandler &p_dbHandler) = delete;
  DBHandler& operator=(DBHandler &&p_dbHandler) = delete;

public:
  virtual ~DBHandler();

protected:
  std::string m_db_name;
  std::string m_db_username;
  std::string m_db_password;
  std::string m_db_hostname;
  std::string m_db_port;
  
  pqxx::connection m_connection;
  pqxx::work m_work;

public:
  virtual int disconnect();
  virtual pqxx::result querry(std::string p_sqlQuerry);
  virtual size_t count(std::string p_sqlQuerry);
  virtual void commit();

  const char* dbName() throw (std::string);
  const char* username() throw (std::string);
  const char* hostname() throw (std::string);
  const char* port() throw (std::string);

  void showDBConfigData() const;
};

} // namespace SERVICES

} // namespace DB

#endif // DBHANDLER_H
