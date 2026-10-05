//
// Created by renat on 3/10/2026.
//

#include "Multa.hpp"

Multa::Multa() {
    placa = nullptr;
    multa = 0.0;
    fechaDePago = 0;
}

Multa::~Multa() {
    if (placa != nullptr) delete[] placa;
}

Multa::Multa(const Multa &m):Multa() {
    *this = m;
}

void Multa::operator=(const Multa &m) {
    set_placa(m.placa);
    multa = m.multa;
    fechaDePago = m.fechaDePago;
    codigoInfraccion = m.codigoInfraccion;
    fechaDeInfraccion = m.fechaDeInfraccion;
}

int Multa::get_fecha_de_infraccion() const {
    return fechaDeInfraccion;
}

void Multa::set_fecha_de_infraccion(const int fecha_de_infraccion) {
    fechaDeInfraccion = fecha_de_infraccion;
}

int Multa::get_fecha_de_pago() const {
    return fechaDePago;
}

void Multa::set_fecha_de_pago(const int fecha_de_pago) {
    fechaDePago = fecha_de_pago;
}

int Multa::get_codigo_infraccion() const {
    return codigoInfraccion;
}

void Multa::set_codigo_infraccion(const int codigo_infraccion) {
    codigoInfraccion = codigo_infraccion;
}

double Multa::get_multa() const {
    return multa;
}

void Multa::set_multa(const double multa) {
    this->multa = multa;
}

void Multa::get_placa(char *placa) const {
    if (this->placa != nullptr) {
        strcpy(placa, this->placa);
    }
    else {
        placa[0] = '\0';
    }
}

void Multa::set_placa(char *placa) {
    if (this->placa!=nullptr) {
        delete[] placa;
    }
    this->placa = new char[strlen(placa)+1]{};
    strcpy(this->placa, placa);
}

void operator >>(ifstream &input, Multa &multa) {
    multa.leer(input);
}
//23/7/2023,P474-593,2060,P,22/8/2023
//6/8/2021,P863-768,2025
void Multa::leer(ifstream &input) {
    char ignorar;
    fechaDeInfraccion = leerFecha(input);
    placa = leerConDelimitador(input,',');
    input>>codigoInfraccion;
    char comprobar = input.peek();
    if (comprobar==',') {
        input.get();
        input.get();
        input.get();
        fechaDePago = leerFecha(input);
    }
    else {
        input.get();
    }
}


void operator <<(ofstream &output, Multa &multa) {
    multa.imprimir(output);
}

void Multa::imprimir(ofstream &output) {
    output<<placa<<setw(15)<<fechaDeInfraccion<<setw(10)
    <<codigoInfraccion<<setw(10)<<multa;
    if (fechaDePago!=0) {
        output<<setw(15)<<fechaDePago;
    }
    output<<endl;
}
