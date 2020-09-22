cmake_minimum_required (VERSION 3.15)

project (cpp-project-template)

add_subdirectory(SimpleLibrary)

add_executable(app)

target_sources(app PRIVATE source/app.cpp)

target_link_libraries(app PRIVATE SimpleLibrary)

target_compile_features(app PUBLIC cxx_std_17)
