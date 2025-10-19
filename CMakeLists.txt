cmake_minimum_required(VERSION 4.0)
project(EstudioEDD)

set(CMAKE_CXX_STANDARD 20)

add_executable(EstudioEDD main.cpp
        cmake-build-debug/LinkedList.h
        Nodo.cpp
        Nodo.h
        SparseMatrix.cpp
        SparseMatrix.h
)
