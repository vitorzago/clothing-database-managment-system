cmake_minimum_required(VERSION 3.10)

project(clothingdatabase LANGUAGES CXX)

set(SOURCES
    ClothingManager.cpp
    main.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC mysqlcppconn)
