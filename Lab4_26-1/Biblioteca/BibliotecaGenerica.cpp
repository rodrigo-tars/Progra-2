//
// Created by renat on 26/9/2026.
//

#include "BibliotecaGenerica.hpp"

void procesaArreglo(void *arreglo[],void *(*lee)(ifstream &), const char*
    nomArch) {
    int i=0;
    ifstream input(nomArch, ios::in);
    while (true) {
        void *dato = lee(input);
        if (input.eof()) break;
        arreglo[i] = dato;
        i++;
    }
}

void creaLista(void *arreglo[], void*&lista, int (*compara)(const void *, const void *)) {
    int i=0;
    while (arreglo[i]) i++;
    qsort(arreglo,i, sizeof(void *), compara);
    generaLista(lista);
    i = 0;
    while (arreglo[i]) {
        insertarLista(lista, arreglo[i]);
        i++;
    }
}

void generaLista(void *&lista) {
    void ** listaAbierta = new void*[2]{};
    int * ptr_long = new int;
    ptr_long[0] = 0;
    listaAbierta[LONGITUD] = ptr_long;
    lista = listaAbierta;
}

void insertarLista(void *lista,void *dato) {
    void **listaAbierta = (void **) lista;
    void **nuevo = new void*[2]{};
    nuevo[DATO] = dato;
    if (listaEsVacia(lista)) {
        listaAbierta[PRIMERNODO] = nuevo;
    }
    else {
        void **ultimo = (void **) buscarUltimoNodo(lista);
        nuevo[SIGUIENTE] = ultimo[SIGUIENTE];
        //nuevo[SIGUIENTE] = ultimo[SIGUIENTE];
        ultimo[SIGUIENTE] = nuevo;
    }
    // int ptr_long;
    // *(int *) listaAbierta[LONGITUD] = ptr_long;
    // ptr_long++;

    int *ptr_long = (int *) listaAbierta[LONGITUD];
    ptr_long[0]++;
}

bool listaEsVacia(void *lista) {
    void **listaAbierta = (void **) lista;
    int *ptr_long =(int *) listaAbierta[LONGITUD];
    if (ptr_long[0] == 0) return true;
    return false;
}

void *buscarUltimoNodo(void *lista) {
    void **listaAbierta = (void **) lista;
    void **recorrido = (void **) listaAbierta[PRIMERNODO];
    void **anterior = nullptr;
    while (recorrido!=nullptr) {
        anterior = recorrido;
        recorrido = (void **) recorrido[SIGUIENTE];
    }
    return anterior;
}

void imprimeLista(void *lista,void (*imprime)(ofstream &output, void *dato),
    const char *nomArch) {
    ofstream output(nomArch, ios::out);
    void **listaAbierta = (void **) lista;
    void **recorrido = (void **) listaAbierta[PRIMERNODO];
    while (recorrido!=nullptr) {
        imprime(output, recorrido[DATO]);
        recorrido = (void **) recorrido[SIGUIENTE];
    }
}

void fusionaListas(void *&lista1, void *lista2,bool(*verifica)(void *, void*)) {
    void **listaAbierta1 = (void **) lista1;
    void **listaAbierta2 = (void **) lista2;
    void **recorrido1 = (void **) listaAbierta1[PRIMERNODO];
    void **recorrido2 = (void **) listaAbierta2[PRIMERNODO];
    void **anterior1 = nullptr;
    void **anterior2 = nullptr;
    anterior2 = recorrido2;
    recorrido2 = (void **) recorrido2[SIGUIENTE];
    while (recorrido1!=nullptr) {
        if (recorrido2==nullptr) break;
        if (verifica(recorrido1[DATO], anterior2[DATO])) {
            anterior1[SIGUIENTE] = anterior2;
            anterior2[SIGUIENTE] = recorrido1;
            anterior2 = recorrido2;
            recorrido2 = (void **) recorrido2[SIGUIENTE];
        }
        else {
            anterior1 = recorrido1;
            recorrido1 = (void **) recorrido1[SIGUIENTE];
        }
    }
    insertarLista(lista1, anterior2[DATO]);
    while (recorrido2!=nullptr) {
        insertarLista(lista2, recorrido2[DATO]);
        recorrido2 = (void **) recorrido2[SIGUIENTE];
    }
}