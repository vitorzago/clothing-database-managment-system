cmake_minimum_required(VERSION 3.10)

project(clothingdatabase LANGUAGES CXX)

set(SOURCES
    src/ClothingManager.cpp
    src/main.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)       

target_link_libraries(${PROJECT_NAME} PUBLIC mysqlcppconn)
