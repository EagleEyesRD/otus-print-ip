cmake_minimum_required(VERSION 3.5)

project(print-ip)

add_executable(print-ip main.cpp)
set_target_properties(print-ip PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)


