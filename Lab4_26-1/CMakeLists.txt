cmake_minimum_required(VERSION 4.1)
project(Lab4_26_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab4_26_1 main.cpp
        Biblioteca/BibliotecaGenerica.hpp
        Biblioteca/BibliotecaGenerica.cpp
        Biblioteca/BibliotecaEnteros.cpp
        Biblioteca/BibliotecaRegistros.hpp
        Biblioteca/BibliotecaRegistros.cpp)
