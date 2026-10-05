//
// Created by renat on 3/10/2026.
//

#include "MinisterioDeTransporte.hpp"

MinisterioDeTransporte::MinisterioDeTransporte() {
    infracciones = nullptr;
    numEmp = 0;
    numInf = 0;
}

MinisterioDeTransporte::~MinisterioDeTransporte() {
    if (infracciones != nullptr) delete[] infracciones;
}

int MinisterioDeTransporte::get_num_inf() const {
    return numInf;
}

void MinisterioDeTransporte::set_num_inf(const int num_inf) {
    numInf = num_inf;
}

int MinisterioDeTransporte::get_num_emp() const {
    return numEmp;
}

void MinisterioDeTransporte::set_num_emp(const int num_emp) {
    numEmp = num_emp;
}

void MinisterioDeTransporte::operator<(const char *nomArch) {
    ifstream input(nomArch, ios::in);
    int numDat = 0, cap = 0;
    int i=0;
    while (true) {
        Infraccion infraccion;
        input >> infraccion;
        if (input.eof()) break;
        if (numDat == cap) incrementarMemoria(numDat, cap);
        infracciones[numDat] = infraccion;
        numDat++;

        i++;
    }
    numInf = numDat;
}

void MinisterioDeTransporte::incrementarMemoria(int &numDat, int &cap) {
    Infraccion *auxInfraccion;
    cap+=5;
    if (infracciones == nullptr) {
        infracciones = new Infraccion[cap]{};
    }
    else {
        auxInfraccion = new Infraccion[cap]{};
        for (int i=0;i<numDat;i++) auxInfraccion[i] = infracciones[i];
        delete [] infracciones;
        infracciones = auxInfraccion;
    }
}

void MinisterioDeTransporte::operator<=(const char *nomArch) {
    ifstream input(nomArch, ios::in);
    while (true) {
        Empresa empresa;
        input >> empresa;
        if (input.eof()) break;
        empresas[numEmp] = empresa;
        numEmp++;
    }
}

void MinisterioDeTransporte::operator<<=(const char *nomArch) {
    ifstream input(nomArch, ios::in);
    int cod_inf, indice_inf, indice_empresa;
    double monto;
    while (true) {
        Multa multa;
        input >> multa;
        if (input.eof()) break;
        cod_inf = multa.get_codigo_infraccion();
        indice_inf = buscarInfraccion(cod_inf);
        char placa[15];
        multa.get_placa(placa);
        indice_empresa = buscarEmpresa(placa);
        if (indice_inf != -1 and indice_empresa != -1) {
            monto = infracciones[indice_inf].get_multa();
            multa.set_multa(monto);
            empresas[indice_empresa] += multa;
        }
    }
}

int MinisterioDeTransporte::buscarInfraccion(int codigo_infraccion) {
    for (int i=0;i<numInf;i++)
        if (infracciones[i].get_codigo() == codigo_infraccion)
            return i;
    return -1;
}

int MinisterioDeTransporte::buscarEmpresa(char *placa) {
    for (int i=0;i<numEmp;i++) {
        int cant_placas = empresas[i].get_num_placas();
        for (int j=0;j<cant_placas;j++) {
            char placaXEmp[15];
            empresas[i].getPlacaI(placaXEmp, j);
            if (strcmp(placaXEmp, placa) == 0) return i;
        }
    }
    return -1;
}

void MinisterioDeTransporte::operator>>(const char *nomArch) {
    ofstream output(nomArch, ios::out);
    output<<"TABLA DE INFRACCIONES: "<<endl;
    imprimirCaracter(output, '=');
    for (int i=0;i<numInf;i++) output<<infracciones[i];
    imprimirCaracter(output, '=');
    output<<"EMPRESAS CON INFRACCIONES: "<<endl;
    imprimirCaracter(output, '=');
    for (int i=0;i<numEmp;i++) {
        output<<empresas[i];
        imprimirCaracter(output, '-');
    }
}
