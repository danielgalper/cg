cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(simplify-example)

add_executable(simplify-example simplify.cpp)
target_link_libraries(simplify-example visualization)
