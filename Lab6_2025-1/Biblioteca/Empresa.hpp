//
// Created by renat on 3/10/2026.
//

#ifndef LAB6_2025_1_EMPRESA_HPP
#define LAB6_2025_1_EMPRESA_HPP
#include "Multa.hpp"


class Empresa {
public:
    Empresa();
    ~Empresa();
    Empresa(const Empresa &empresa);
    void operator =(const Empresa &empresa);
    int get_dni() const;

    void set_dni(const int dni);

    int get_num_placas() const;

    void set_num_placas(const int num_placas);

    int get_num_multas() const;

    void set_num_multas(const int num_multas);

    void getPlacaI(char *placa, int i) const;

    void setPlacaI(char *placa, int i);

    void get_nombre(char *nombre) const;

    void set_nombre(char *nombre);

    void leer(ifstream &input);
    void imprimir(ofstream &output);
    void operator +=(Multa &multa);
private:
    int dni;
    char *nombre;
    char *placas[10];
    int numPlacas;
    Multa multas[100];
    int numMultas;
};
void operator >>(ifstream &input, Empresa &empresa);
void operator <<(ofstream &output, Empresa &empresa);
#endif //LAB6_2025_1_EMPRESA_HPP