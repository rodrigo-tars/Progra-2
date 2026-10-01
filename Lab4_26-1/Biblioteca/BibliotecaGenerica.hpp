//
// Created by renat on 26/9/2026.
//

#ifndef LAB4_26_1_BIBLIOTECAGENERICA_HPP
#define LAB4_26_1_BIBLIOTECAGENERICA_HPP
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace  std;
enum {DATO, SIGUIENTE};
enum {PRIMERNODO, LONGITUD};
void procesaArreglo(void *arreglo[],void *(*lee)(ifstream &), const char*
    nomArch);
void creaLista(void *arreglo[], void*&lista, int (*compara)(const void *, const void *));
void generaLista(void *&lista);
bool listaEsVacia(void *lista);
void insertarLista(void *lista,void *dato);
void *buscarUltimoNodo(void *lista);
void imprimeLista(void *lista,void (*imprime)(ofstream &output, void *dato),
    const char *nomArch);
void fusionaListas(void *&lista1, void *lista2,bool(*verifica)(void *, void*));
#endif //LAB4_26_1_BIBLIOTECAGENERICA_HPP