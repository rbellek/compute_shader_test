cmake_minimum_required(VERSION 3.18)

project(ComputeShaderSample VERSION 1.0.0)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

target_link_libraries(${PROJECT_NAME} ComputeShaderLib glad glfw)