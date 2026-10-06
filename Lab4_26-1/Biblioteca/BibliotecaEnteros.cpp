//
//
//

#include "BibliotecaEnteros.hpp"

void * leenum(ifstream &input){
    int *numero = new int;
    input>>numero[0];
    if (input.eof()) return nullptr;
    return numero;
}

int comparanum (const void *a, const void *b) {
    void **a1 = (void **) a, **b1 = (void **) b;
    int *numA = (int *) a1[0], *numB = (int *) b1[0];
    return *numA - *numB;
}

void imprimenum(ofstream &output, void *dato){
    int *num = (int *) dato;
    output<<num[0]<<endl;
}

bool verificanum(void * a, void*b){
    int *numA = (int *) a, *numB = (int *) b;
    return numA[0] > numB[0];
}
