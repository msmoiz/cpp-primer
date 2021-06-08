cmake_minimum_required(VERSION 3.0)
project(cpp-primer)

include_directories("src")
add_executable(bookstore src/bookstore.cpp)

add_executable(primitives src/primitives.cpp)
