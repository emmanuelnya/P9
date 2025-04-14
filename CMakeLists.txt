cmake_minimum_required(VERSION 3.30)
project(P9)

set(CMAKE_CXX_STANDARD 20)

add_executable(P9 main.cpp
        comptebancaire.cpp
        comptebancaire.h
        transaction.cpp
        transaction.h
        destinatario.cpp
        destinatario.h
)
enable_testing()
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include/gtest/gtest.h)
add_executable(P9_tests
        tests/tests.cpp
        comptebancaire.cpp
        transaction.cpp
        destinatario.cpp
)
target_link_libraries(P9_tests gtest gtest_main)
add_test(NAME UnitTests COMMAND P9_tests)