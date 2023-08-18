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

typedef std::shared_ptr<sql::ResultSet> sqlResult;

class ClothingManager {
public:
  ClothingManager() {
    driver = get_driver_instance();
    std::string pwd = read_password();
    connection = driver->connect("tcp://127.0.0.1:3306", "root", pwd);
    connection->setSchema("clothing");
    stmt = connection->createStatement();
  };

  ~ClothingManager(){
	  delete stmt;
	  delete connection;
  };

  void insert_value(std::string value){
    std::string cmd = "INSERT INTO clothes VALUES('" + value + "','white')";
    stmt->execute(cmd);
  }

  void display_table(){
  	sqlResult result(stmt->executeQuery("SELECT * FROM clothes")); 
  	while (result->next()) {
    		std::cout << result->getString(1) << std::endl;
  	}
   }

  void delete_value(std::string value){
    	std::string cmd = "DELETE FROM clothes WHERE name='" + value + "'";
    	stmt->execute(cmd);
  }


  private:
  sql::Driver* driver;
  sql::Statement* stmt;
  sql::Connection* connection;
};


int main(void)
{
try {
	auto myClothingManager = ClothingManager();
	myClothingManager.insert_value("shorts");
	myClothingManager.insert_value("pants");
	myClothingManager.delete_value("shorts");
	myClothingManager.display_table();
} catch (sql::SQLException &e) {
	std::cout << "# ERR: " << e.what();
}

std::cout << std::endl;

return EXIT_SUCCESS;
} 
