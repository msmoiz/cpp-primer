cmake_minimum_required(VERSION 3.0)
project(cpp-primer)

include_directories("src")
add_executable(bookstore src/bookstore.cpp)
add_executable(primitives src/primitives.cpp)
add_executable(arraysplus src/arraysplus.cpp)
add_executable(expressions src/expressions.cpp)
add_executable(statements src/statements.cpp)
add_executable(func src/func.cpp)
add_executable(classes src/classes.cpp src/SalesData.cpp src/Person.cpp)
add_executable(io src/io.cpp)
add_executable(sequential src/sequential.cpp)
add_executable(algorithms src/algorithms.cpp)
add_executable(associative src/associative.cpp)
add_executable(dynamic src/dynamic.cpp)
add_executable(copycontrol src/copycontrol.cpp)
add_executable(overloadops src/overloadops.cpp)
add_executable(templates src/templates.cpp)
