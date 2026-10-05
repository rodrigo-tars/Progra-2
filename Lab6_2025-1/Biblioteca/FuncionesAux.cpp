//
// Created by renat on 3/10/2026.
//

#include "FuncionesAux.hpp"

char *leerConDelimitador(ifstream &input, char delimitador) {
    char *cadena, cad[200]{};
    input.getline(cad, 200, delimitador);
    cadena = new char[strlen(cad)+1]{};
    strcpy(cadena,cad);
    return cadena;
}

int leerFecha(ifstream &input) {
    int dd, mm, aaaa;
    char slash;
    input>>dd>>slash>>mm>>slash>>aaaa;
    input.get();
    return dd + mm*100 + aaaa*10000; //aaaammdd
}

void imprimirCaracter(ofstream &output, char c) {
    for (int i=0;i<190;i++) output.put(c);
    output<<endl;
}