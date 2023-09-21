cmake_minimum_required(VERSION 3.24)
project(cardtest)

set(CMAKE_CXX_STANDARD 17)

add_executable(cardtest main.cpp Card.cpp Card.h Zone.cpp Zone.h)
