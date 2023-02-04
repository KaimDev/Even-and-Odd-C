cmake_minimum_required(VERSION 3.24)

project(Even_And_Odd_List C)

add_executable(program Main.c List.h)

target_compile_features(program PUBLIC c_std_17)