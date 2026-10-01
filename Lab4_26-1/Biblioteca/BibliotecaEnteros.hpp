//
// Created by renat on 26/9/2026.
//

#ifndef LAB4_26_1_BIBLIOTECAENTEROS_HPP
#define LAB4_26_1_BIBLIOTECAENTEROS_HPP
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace  std;
void * leenum(ifstream &input);
int comparanum (const void *a, const void *b);
void imprimenum(ofstream &output, void *dato);
bool verificanum(void * a, void*b);
#endif //LAB4_26_1_BIBLIOTECAENTEROS_HPP