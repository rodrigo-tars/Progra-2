//
// Created by renat on 26/9/2026.
//

#include "BibliotecaRegistros.hpp"
//101,7/4/2025,CONTROL,11:00,PROGRAMADA,Luna,Labrador,Negro,CANINO
void * leereg(ifstream &input){
    void **registro = new void *[9]{};
    int *codigo = new int, *fecha = new int, *hora=new int;
    char *motivo, *estado, *nombre, *raza, *color, *especie, ignorar;
    input>>codigo[0]>>ignorar;
    if (input.eof()) return nullptr;
    fecha[0] = leerFecha(input);
    motivo = leerConDelimitador(input,',');
    hora[0] = leerHora(input);
    estado = leerConDelimitador(input,',');
    nombre = leerConDelimitador(input,',');
    raza = leerConDelimitador(input,',');
    color = leerConDelimitador(input,',');
    especie = leerConDelimitador(input,'\n');
    registro[0] = codigo;
    registro[1] = fecha;
    registro[2] = hora;
    registro[3] = motivo;
    registro[4] = estado;
    registro[5] = nombre;
    registro[6] = raza;
    registro[7] = color;
    registro[8] = especie;
    return registro;
}

int comparareg (const void *a, const void *b) {
    void **a1 = (void **) a, **b1 = (void **) b;
    void **a11 = (void **)a1[0], **b11 = (void **)b1[0];
    int *fechaA = (int *) a11[1], *fechaB = (int *) b11[1];
    int *horaA = (int *) a11[3], *horaB = (int *) b11[3];
    if (fechaA[0] == fechaB[0]) {
        return *horaA - *horaB;
    }
    return *fechaA - *fechaB;
}
//101,7/4/2025,CONTROL,11:00,PROGRAMADA,Luna,Labrador,Negro,CANINO
void imprimereg(ofstream &output, void *dato){
    void **registro = (void **) dato;
    int *codigo = (int *) registro[0];
    int *fecha = (int *) registro[1];
    int *hora = (int *) registro[2];
    char *motivo = (char *) registro[3];
    char *estado = (char *) registro[4];
    char *nombre = (char *) registro[5];
    char *raza = (char *) registro[6];
    char *color = (char *) registro[7];
    char *especie = (char *) registro[8];
    output<<*codigo<<" "<<*fecha<<" "<<*hora<<" "<<motivo<<setw(20-strlen(motivo))
    <<" "<<estado<<setw(20-strlen(estado))<<" "<<nombre<<setw(30-strlen(nombre))
    <<" "<<raza<<setw(20-strlen(raza))<<" "<<color<<setw(20-strlen(color))<<" "<<especie<<endl;

}

bool verificareg(void * a, void*b){
    void **registroa = (void **) a, **registrob =(void **) b;
    int *fechaA = (int *)registroa[1], *fechaB = (int *)registrob[1];
    int *horaA = (int *) registroa[2], *horaB = (int *)registrob[2];
    if (*fechaA == *fechaB) return *horaA > *horaB;
    return *fechaA > *fechaB;
}

int leerFecha(ifstream &input) {
    int dia, mes, anio;
    char slash;
    input>>dia>>slash>>mes>>slash>>anio;
    input.get();
    return dia + mes *100 + anio*10000;
}

char *leerConDelimitador(ifstream &input, char delimitador) {
    char *cadena, cad[200]{};
    input.getline(cad, 200, delimitador);
    cadena = new char[strlen(cad)+1]{};
    strcpy(cadena, cad);
    return cadena;
}

int leerHora(ifstream &input) {
    int hh, mm;
    char ignorar;
    input>>hh>>ignorar>>mm;
    input.get();
    return  mm + hh*100;
}