cmake_minimum_required (VERSION 2.6.0)
project (cpp-project-template)

## App 
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
file(GLOB APP_SRC
    "${SRC_DIR}/*.h"
    "${SRC_DIR}/*.cpp"
)
add_executable(app ${APP_SRC})

## Test
enable_testing()
include_directories(
    ${GTEST_INCLUDE_DIRS}
    ${GMOCK_INCLUDE_DIRS}
)

# Adds project files (e.g. classes) to be used by gtest
add_library(project_libraries STATIC ${APP_SRC})

include_directories(${COMMON_INCLUDES})

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
set(GTEST_DIR "/googletest/googletest")
add_subdirectory(${GTEST_DIR}
                 ${GTEST_DIR}/build
                 EXCLUDE_FROM_ALL)

set(TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test)
file(GLOB TEST_SRC_FILES ${TEST_SRC_FILES}/*.cpp)
# from list of files we'll create tests test_name.cpp -> test_name
foreach(_test_file ${TEST_SRC_FILES})
    get_filename_component(_test_name ${_test_file} NAME_WE)
    add_executable(${_test_name} ${_test_file})
    add_dependencies(${_test_name} gtest)
    
    target_link_libraries(${_test_name} gtest gtest_main ${CMAKE_THREAD_LIBS_INIT} project_libraries)
    add_test(${_test_name} ${_test_name})
    set_tests_properties(${_test_name} PROPERTIES TIMEOUT 5)
endforeach()