cmake_minimum_required(VERSION 3.10)

project(clothingdatabase LANGUAGES CXX)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC mysqlcppconn)
