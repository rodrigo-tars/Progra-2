//
//
//

#ifndef LAB_5___25_2_STREAMER_HPP
#define LAB_5___25_2_STREAMER_HPP
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
#include  "FuncionesAuxiliares.hpp"
using namespace std;
class Streamer {
public:
    Streamer();
    ~Streamer();
    Streamer(const Streamer &);
    void operator=(const Streamer &);
    long long get_tiempo_total() const;
    void set_tiempo_total(const long long tiempo_total);
    double get_promedio_espectadores() const;
    void set_promedio_espectadores(const double promedio_espectadores);
    int get_n_seguidores() const;
    void set_n_seguidores(const int n_seguidores);
    void getCuenta(char *_cuenta) const;
    void setCuenta(const char *_cuenta);
    void getCategoria(char *_categoria) const;
    void setCategoria(const char *_categoria);
    void mostrar_streamer();
    void mostrar_streamer_reporte(ofstream &output);
    void leer_streamer(ifstream &);
    void copiar(Streamer s);
private:
    char *cuenta;
    long long tiempo_total;
    double promedio_espectadores;
    int n_seguidores;
    char *categoria;
};
int cmpnumeroseguidores(const void *,const void *);
int cmptiempo(const void *,const void *);
int cmppromespc(const void *,const void *);
int cmpcategoria(const void *,const void *);
int cmpinfluencia(const void *,const void *);

#endif //LAB_5___25_2_STREAMER_HPP