// Global Functions
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <libconfig.h++>


namespace DB
{

namespace FUNCTIONS
{

struct DBConfigData
{
  std::string m_db_configFileName;
  std::string m_db_name;
  std::string m_db_username;
  std::string m_db_password;
  std::string m_db_hostname;
  std::string m_db_port;

  friend std::ostream& operator<<(std::ostream &p_stream, DBConfigData const &p_dbConfigData);
};

class DBConfigControler
{
public:
  static void readConfigFileAndFillDBConfigData(std::string p_configFileName, struct DBConfigData &p_dbConfigData);
};

} // namespace FUNCTIONS

} // namespace DB

#endif // FUNCTIONS_H
