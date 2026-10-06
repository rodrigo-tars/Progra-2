//
//
//

#include "FuncionesAuxiliares.hpp"
char *LeerConDelimitador(ifstream &input, char delimitador) {
    char *cadena, cad[100];
    input.getline(cad, 100, delimitador);
    cadena = new char [strlen(cad) + 1]{};
    strcpy(cadena, cad);
    return cadena;
}
