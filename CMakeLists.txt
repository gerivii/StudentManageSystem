cmake_minimum_required(VERSION 3.20)
project(StudentManageSystem C)

set(CMAKE_C_STANDARD 99)

add_executable(StudentManageSystem main.c head/SQL.h source/SQL.c)
