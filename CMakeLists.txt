cmake_minimum_required(VERSION 3.14)
project(LinkedList)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)

add_executable(app main.cpp src/lista.cpp)            # MAIN
#add_executable(testes tests/test.cpp src/lista.cpp)    # TESTE