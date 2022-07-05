cmake_minimum_required(VERSION 3.18)

project(glad VERSION 4.5.0)

add_library(${PROJECT_NAME} src/glad.c include/glad/glad.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)