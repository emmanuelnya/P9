cmake_minimum_required(VERSION 3.30)
project(P9)

set(CMAKE_CXX_STANDARD 26)

add_executable(P9 main.cpp
        comptebancaire.cpp
        comptebancaire.h
        transaction.cpp
        transaction.h
        destinatario.cpp
        destinatario.h
)
