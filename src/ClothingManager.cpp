#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>

std::string read_password(){
	std::ifstream myfile("password.txt");
	std::string pwd;
	if( myfile.is_open() ){
		myfile >> pwd;
	}
	return pwd;
};