cmake_minimum_required(VERSION 3.15)

project(SimpleLibrary)

add_library(SimpleLibrary STATIC
        source/SimpleClass.cpp)

target_include_directories(SimpleLibrary
    PUBLIC
        include
    PRIVATE
        include/SimpleLibrary)

target_compile_features(SimpleLibrary PUBLIC cxx_std_17)

add_subdirectory(tests)
