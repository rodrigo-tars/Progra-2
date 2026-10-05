//
// Created by renat on 3/10/2026.
//

#include "Infraccion.hpp"

#include <cstring>

Infraccion::Infraccion() {
    descripcion = nullptr;
    gravedad = nullptr;
    multa = 0.0;
}

Infraccion::~Infraccion() {
    if (descripcion != nullptr) delete[] descripcion;
    if (gravedad != nullptr) delete[] gravedad;
}

Infraccion::Infraccion(const Infraccion &infraccion):Infraccion() {
    *this = infraccion;
}

void Infraccion::operator=(const Infraccion &infraccion) {
    this->codigo = infraccion.codigo;
    this->multa = infraccion.multa;
    set_descripcion(infraccion.descripcion);
    set_gravedad(infraccion.gravedad);
}

int Infraccion::get_codigo() const {
    return codigo;
}

void Infraccion::set_codigo(const int codigo) {
    this->codigo = codigo;
}

double Infraccion::get_multa() const {
    return multa;
}

void Infraccion::set_multa(const double multa) {
    this->multa = multa;
}

void Infraccion::get_descripcion(char *descripcion) const {
    if (this->descripcion != nullptr) {
        strcpy(descripcion, this->descripcion);
    }
    else {
        descripcion[0] = '\0';
    }
}

void Infraccion::set_descripcion(const char *descripcion) {
    if (this->descripcion != nullptr) {
        delete[] this->descripcion;
    }
    this->descripcion = new char[strlen(descripcion) + 1]{};
    strcpy(this->descripcion, descripcion);
}

void Infraccion::get_gravedad(char *gravedad) const {
    if (this->gravedad != nullptr) {
        strcpy(gravedad, this->gravedad);
    }
    else {
        gravedad[0] = '\0';
    }
}

void Infraccion::set_gravedad(const char *gravedad) {
    if (this->gravedad != nullptr) {
        delete[] this->gravedad;
    }
    this->gravedad = new char[strlen(gravedad) + 1]{};
    strcpy(this->gravedad, gravedad);
}

void operator >> (ifstream &input, Infraccion &infraccion) {
    infraccion.leer(input);
}
//2065,378.40,Grave,
//Utilizar senales audibles o visibles iguales o similares a las
//que utilizan los vehiculos de emergencia o vehiculos oficiales.
void Infraccion::leer(ifstream &input) {
    char ignorar;
    input>>codigo>>ignorar;
    if (input.eof()) return;
    input>>multa>>ignorar;
    gravedad = leerConDelimitador(input, ',');
    descripcion = leerConDelimitador(input, '\n');
}


void operator <<(ofstream &output, Infraccion &infraccion) {
    infraccion.imprimir(output);
}

void Infraccion::imprimir(ofstream &output) {
    output<<codigo<<setw(10)<<multa<<setw(10)<<" "
    <<gravedad<<setw(20-strlen(gravedad))<<" "<<descripcion<<endl;
}
