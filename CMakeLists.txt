cmake_minimum_required(VERSION 3.20)
project(StudentManageSystem C)

set(CMAKE_C_STANDARD 99)

add_executable(StudentManageSystem main.c head/SQL.h head/Class.h head/Course.h head/Score.h head/Statist.h head/System.h head/Student.h)
