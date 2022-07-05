cmake_minimum_required(VERSION 3.18)

project(ComputeShaderLib VERSION 1.0.0)

add_library(${PROJECT_NAME} src/cs.cpp include/cs.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} glad)


