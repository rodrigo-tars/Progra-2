//
// Created by renat on 26/9/2026.
//

#ifndef LAB4_26_1_BIBLIOTECAREGISTROS_HPP
#define LAB4_26_1_BIBLIOTECAREGISTROS_HPP
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace  std;
void * leereg(ifstream &input);
int leerFecha(ifstream &input);
char *leerConDelimitador(ifstream &input, char delimitador);
int leerHora(ifstream &input);
int comparareg (const void *a, const void *b);
void imprimereg(ofstream &output, void *dato);
bool verificareg(void * a, void*b);
#endif //LAB4_26_1_BIBLIOTECAREGISTROS_HPP