cmake_minimum_required(VERSION 4.1)
project(Lab6_2025_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab6_2025_1 main.cpp
        Biblioteca/Empresa.cpp
        Biblioteca/Infraccion.cpp
        Biblioteca/MinisterioDeTransporte.cpp
        Biblioteca/Multa.cpp
        Biblioteca/FuncionesAux.cpp)
