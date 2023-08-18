cmake_minimum_required(VERSION 3.10)

project(clothingdatabase LANGUAGES CXX)

add_subdirectory(3rd_party/catch2)

set(SOURCES
    ClothingManager.cpp
    main.cpp)

add_library(sqlvbz ${SOURCES})

add_executable(${PROJECT_NAME} ${SOURCES})
#add_executable(${PROJECT_NAME} unit_tests.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)       

target_link_libraries(${PROJECT_NAME} PUBLIC mysqlcppconn Catch2::Test sqlvbz)
