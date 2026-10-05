//
// Created by renat on 3/10/2026.
//

#ifndef LAB6_2025_1_INFRACCION_HPP
#define LAB6_2025_1_INFRACCION_HPP
#include "FuncionesAux.hpp"

class Infraccion {
public:
    Infraccion();
    ~Infraccion();
    Infraccion(const Infraccion &);
    void operator=(const Infraccion &);
    int get_codigo() const;
    void set_codigo(const int codigo);
    double get_multa() const;
    void set_multa(const double multa);
    void get_descripcion(char *descripcion) const;
    void set_descripcion(const char *descripcion);
    void get_gravedad(char *gravedad) const;
    void set_gravedad(const char *gravedad);
    void leer(ifstream &input);
    void imprimir(ofstream &output);
private:
    int codigo;
    char *descripcion;
    char *gravedad;
    double multa;
};

void operator >> (ifstream &input, Infraccion &infraccion);
void operator <<(ofstream &output, Infraccion &infraccion);

#endif //LAB6_2025_1_INFRACCION_HPP
