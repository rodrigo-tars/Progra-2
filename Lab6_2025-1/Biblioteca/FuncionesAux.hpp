//
// Created by renat on 3/10/2026.
//

#ifndef LAB6_2025_1_FUNCIONESAUX_HPP
#define LAB6_2025_1_FUNCIONESAUX_HPP
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
char *leerConDelimitador(ifstream &input, char delimitador);
int leerFecha(ifstream &input);
void imprimirCaracter(ofstream &output, char c);
#endif //LAB6_2025_1_FUNCIONESAUX_HPP