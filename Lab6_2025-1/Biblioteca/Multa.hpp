//
// Created by renat on 3/10/2026.
//

#ifndef LAB6_2025_1_MULTA_HPP
#define LAB6_2025_1_MULTA_HPP
#include "FuncionesAux.hpp"
class Multa {
public:
    Multa();
    ~Multa();
    Multa(const Multa &);
    void operator=(const Multa &);

    int get_fecha_de_infraccion() const;

    void set_fecha_de_infraccion(const int fecha_de_infraccion);

    int get_fecha_de_pago() const;

    void set_fecha_de_pago(const int fecha_de_pago);

    int get_codigo_infraccion() const;

    void set_codigo_infraccion(const int codigo_infraccion);

    double get_multa() const;

    void set_multa(const double multa);

    void get_placa(char *placa) const;

    void set_placa(char *placa);

    void leer(ifstream &input);

    void imprimir(ofstream &output);
private:
    char *placa;
    int fechaDeInfraccion;
    int fechaDePago;
    int codigoInfraccion;
    double multa;
};
void operator >>(ifstream &input, Multa &multa);
void operator <<(ofstream &output, Multa &multa);
#endif //LAB6_2025_1_MULTA_HPP