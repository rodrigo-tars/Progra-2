#include "Biblioteca/BibliotecaGenerica.hpp"
#include "Biblioteca/BibliotecaEnteros.hpp"
#include "Biblioteca/BibliotecaRegistros.hpp"
#define  MAX 300
int main() {
    void *arreglo1[MAX]{}, *arreglo2[MAX]{};
    void *lista1, *lista2;
    // procesaArreglo(arreglo1, leenum, "ArchivosDeLectura/numeros1.txt");
    // creaLista(arreglo1,lista1,comparanum);
    // procesaArreglo(arreglo2, leenum, "ArchivosDeLectura/numeros2.txt");
    // creaLista(arreglo2,lista2,comparanum);
    // fusionaListas(lista1, lista2, verificanum);
    // imprimeLista(lista1, imprimenum, "ArchivosDeImpresion/Repnum.txt");

    procesaArreglo(arreglo1, leereg, "ArchivosDeLectura/Atenciones1.csv");
    creaLista(arreglo1,lista1,comparareg);
    procesaArreglo(arreglo2, leereg, "ArchivosDeLectura/Atenciones2.csv");
    creaLista(arreglo2,lista2,comparareg);
    fusionaListas(lista1, lista2, verificareg);
    imprimeLista(lista1, imprimereg, "ArchivosDeImpresion/Repreg.txt");
    return 0;
}