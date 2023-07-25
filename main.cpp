#include <iostream>
#include <mysql/mysql.h>
//#include <mysqlx/xdevapi.h>

//struct connection_details {
//	const char *server, *user, *passwor, *database;
//};
//
//MYSQL* mysql_connection_setup(struct connection_details my_details){
//	MYSQL *connection = mysql_init(NULL);
//	if (!mysql_real_connection(connection, my_details.server,
//						my_details.user,
//						my_details.passwor,
//						my_details.database, 0, NULL, 0)){
//			std::cout << "Connect Error" << std::endl;
//			exit(1);
//			} else {
//			std::cout << "It worked!" << std::endl;
//			}
//	return connection;
//
//}
//
//MYSQL_RES* mysql_execute_query(MYSQL *connection, const char *sql_query){
//
//}


int main(int argc, char const *argv[]){
	std::cout << "Hello, world!" << std::endl;
	return 0;
}
