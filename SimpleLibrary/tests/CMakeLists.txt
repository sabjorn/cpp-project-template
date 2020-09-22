include(GoogleTest)

if (NOT TARGET gtest)
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../../googletest googletest EXCLUDE_FROM_ALL)
endif ()

add_executable(simpleTestHost
        source/SimpleClassTestCase.cpp
        source/SimpleStructTestCase.cpp
        source/Main.cpp)

target_compile_features(simpleTestHost PRIVATE cxx_std_17)

target_link_libraries(simpleTestHost
    PRIVATE
        SimpleLibrary
        gtest
        gmock
        )

gtest_add_tests(simpleTestHost "" AUTO)
