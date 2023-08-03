/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>


#include <mysql/mysql.h>

#include <mysql-cppconn-8/jdbc/mysql_connection.h>
#include <mysql-cppconn-8/jdbc/cppconn/driver.h>
#include <mysql-cppconn-8/jdbc/cppconn/exception.h>
#include <mysql-cppconn-8/jdbc/cppconn/resultset.h>
#include <mysql-cppconn-8/jdbc/cppconn/statement.h>

using namespace std;

int main(void)
{
cout << endl;
cout << "Running 'SELECT 'Hello World!' AS _message'..." << endl;

try {

  /* Create a connection */
  sql::Driver *driver;
  driver = get_driver_instance();
  std::shared_ptr<sql::Connection> con(driver->connect("tcp://127.0.0.1:3306", "root", "7448724q9jyy5rn"));

  /* Connect to the MySQL test database */
  con->setSchema("clothing");

  std::shared_ptr<sql::Statement> stmt(con->createStatement());

  std::shared_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT 'Hello World!' AS _message")); // replace with your statement

  while (res->next()) {
    cout << "\t... MySQL replies: ";
    /* Access column data by alias or column name */
    cout << res->getString("_message") << endl;
    cout << "\t... MySQL says it again: ";
    /* Access column fata by numeric offset, 1 is the first column */
    cout << res->getString(1) << endl;
  }

} catch (sql::SQLException &e) {
  cout << "# ERR: " << e.what();
}

cout << endl;

return EXIT_SUCCESS;
} 
