//
// Created by renat on 3/10/2026.
//

#include "Empresa.hpp"

Empresa::Empresa() {
   for (int i=0;i<10;i++) placas[i] = nullptr;
    nombre = nullptr;
    numPlacas = 0;
    numMultas = 0;
}

Empresa::~Empresa() {
    for (int i=0;i<10;i++)
        if (placas[i] != nullptr)
            delete[] placas[i];
    if (nombre != nullptr) delete[] nombre;
}

Empresa::Empresa(const Empresa &empresa) {
    *this = empresa;
}

void Empresa::operator=(const Empresa &empresa) {
    set_nombre(empresa.nombre);
    dni = empresa.dni;
    numPlacas = empresa.numPlacas;
    numMultas = empresa.numMultas;
    for (int i=0;i<numPlacas;i++) {
        setPlacaI(empresa.placas[i],i);
    }
}

int Empresa::get_dni() const {
    return dni;
}

void Empresa::set_dni(const int dni) {
    this->dni = dni;
}

int Empresa::get_num_placas() const {
    return numPlacas;
}

void Empresa::set_num_placas(const int num_placas) {
    numPlacas = num_placas;
}

int Empresa::get_num_multas() const {
    return numMultas;
}

void Empresa::set_num_multas(const int num_multas) {
    numMultas = num_multas;
}

void Empresa::getPlacaI(char *placa, int i) const {
    if (this->placas[i] != nullptr) {
        strcpy(placa, this->placas[i]);
    }
    else {
        placa[0] = '\0';
    }
}

void Empresa::setPlacaI(char *placa, int i) {
    if (this->placas[i] != nullptr) {
        delete[] this->placas[i];
    }
    this->placas[i] = new char[strlen(placa) + 1]{};
    strcpy(this->placas[i], placa);
}

void Empresa::get_nombre(char *nombre) const {
    if (this->nombre != nullptr) {
        strcpy(nombre, this->nombre);
    }
    else {
        nombre[0] = '\0';
    }
}

void Empresa::set_nombre(char *nombre) {
    if (this->nombre != nullptr) {
        delete[] this->nombre;
    }
    this->nombre = new char[strlen(nombre) + 1]{};
    strcpy(this->nombre, nombre);
}


void operator >>(ifstream &input, Empresa &empresa) {
    empresa.leer(input);
}
//13219606,Rodriguez Moreno Blanca Ofelia,
//P201-291,M312-270,M312-270

void Empresa::leer(ifstream &input) {
    char ignorar;
    input>>dni>>ignorar;
    if (input.eof()) return;
    nombre = leerConDelimitador(input,',');
    int j=0;
    while (true) {
        char placa[9]{};
        for (int i=0;i<8;i++) placa[i] = input.get();
        placa[8] = '\0';
        char comprobar;
        comprobar = input.peek();
        setPlacaI(placa,j);
        j++;
        numPlacas++;
        if (comprobar!=',') break;
        input.get();
    }
    input.get();
}

void Empresa::operator+=(Multa &multa) {
    multas[numMultas] = multa;
    numMultas++;
}

void operator <<(ofstream &output, Empresa &empresa) {
    empresa.imprimir(output);
}

void Empresa::imprimir(ofstream &output) {
    output<<dni<<setw(10)<<" "<<nombre<<setw(50-strlen(nombre))
    <<" ";
    for (int i=0;i<numPlacas;i++) {
        output<<placas[i]<<" ";
    }
    output<<endl;
    for (int i=0;i<numMultas;i++) {
        output<<setw(5)<<" ";
        multas[i].imprimir(output);
    }
}
