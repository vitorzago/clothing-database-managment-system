#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>

#include <mysql/mysql.h>

#include <mysql-cppconn-8/jdbc/mysql_connection.h>
#include <mysql-cppconn-8/jdbc/cppconn/driver.h>
#include <mysql-cppconn-8/jdbc/cppconn/exception.h>
#include <mysql-cppconn-8/jdbc/cppconn/resultset.h>
#include <mysql-cppconn-8/jdbc/cppconn/statement.h>

#include "ClothingManager.h"

class ClothingManager {
  ClothingManager() {
    driver = get_driver_instance();
  };

  sql::Driver *driver;
};


void insert_value(std::string value, sql::Statement* statement){
    std::string cmd = "INSERT INTO clothes VALUES('" + value + "','white')";
    statement->execute(cmd);
}

void delete_value(std::string value, sql::Statement* statement){
    std::string cmd = "DELETE FROM clothes WHERE name='" + value + "'";
    statement->execute(cmd);
}

void display_table(sql::Statement* statement){

  std::shared_ptr<sql::ResultSet> result(statement->executeQuery("SELECT * FROM clothes")); 
  while (result->next()) {
    std::cout << result->getString(1) << std::endl;
  }

}

using namespace std;

int main(void)
{
try {

  /* Create a connection */
  sql::Driver *driver;
  driver = get_driver_instance();
  std::string pwd = read_password();
  std::shared_ptr<sql::Connection> con(driver->connect("tcp://127.0.0.1:3306", "root", pwd));

  /* Connect to the MySQL test database */
  con->setSchema("clothing");

  std::shared_ptr<sql::Statement> stmt(con->createStatement());

  delete_value("new_shows", stmt.get());
  display_table(stmt.get());



  //while (res->next()) {
  //  cout << "\t... MySQL replies: ";
  //  /* Access column data by alias or column name */
  //  cout << res->getString("_message") << endl;
  //  cout << "\t... MySQL says it again: ";
  //  /* Access column fata by numeric offset, 1 is the first column */
  //  cout << res->getString(1) << endl;
  //}

} catch (sql::SQLException &e) {
  cout << "# ERR: " << e.what();
}

cout << endl;

return EXIT_SUCCESS;
} 
