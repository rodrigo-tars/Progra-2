//
// Created by renat on 3/10/2026.
//

#ifndef LAB6_2025_1_MINISTERIODETRANSPORTE_HPP
#define LAB6_2025_1_MINISTERIODETRANSPORTE_HPP
#include "Empresa.hpp"
#include "Infraccion.hpp"

class MinisterioDeTransporte {
public:
    MinisterioDeTransporte();
    ~MinisterioDeTransporte();

    int get_num_inf() const;

    void set_num_inf(const int num_inf);

    int get_num_emp() const;

    void set_num_emp(const int num_emp);

    void operator < (const char *nomArch);

    void operator <= (const char*nomArch);
    void operator <<= (const char*nomArch);
    void operator >> (const char*nomArch);
private:
    Infraccion *infracciones;
    int numInf;
    Empresa empresas[50];
    int numEmp;
    void incrementarMemoria(int &numDat,int& cap);
    int buscarInfraccion(int codigo_infraccion);
    int buscarEmpresa(char *placa);
};


#endif //LAB6_2025_1_MINISTERIODETRANSPORTE_HPP