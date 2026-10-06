//
//
//

#ifndef LAB_5___25_2_GESTORSTREAMERS_HPP
#define LAB_5___25_2_GESTORSTREAMERS_HPP
#include "Streamer.hpp"

class GestorStreamers {
public:
    GestorStreamers();
    int get_cantidad_datos() const;
    void set_cantidad_datos(const int cantidad_datos);
    int get_cantidad_datos_vista() const;
    void set_cantidad_datos_vista(const int cantidad_datos_vista);
    void cargar_datos(const char *nomArch);
    void mostrar_menu();
    void mostrar_streamers();
    void mostrar_streamers_reporte(ofstream &output);
    void copiar_datos();
    void cortar_datos(int );
    void generarReporte1();
    void generarReporte2();
    void generarReporte3();
    void generarReporte4();
    void generarReporte5();
    void mostrar_menu1();
private:
    Streamer *data;
    Streamer *dataVista;
    int cantidad_datos;
    int cantidad_datos_vista;
};


#endif //LAB_5___25_2_GESTORSTREAMERS_HPP