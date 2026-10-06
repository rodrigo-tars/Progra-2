//
//

#include "GestorStreamers.hpp"

GestorStreamers::GestorStreamers() {
    cantidad_datos_vista = 0;
    cantidad_datos = 0;
    data = nullptr;
    dataVista = nullptr;
}

int GestorStreamers::get_cantidad_datos() const {
    return cantidad_datos;
}

void GestorStreamers::set_cantidad_datos(const int cantidad_datos) {
    this->cantidad_datos = cantidad_datos;
}

int GestorStreamers::get_cantidad_datos_vista() const {
    return cantidad_datos_vista;
}

void GestorStreamers::set_cantidad_datos_vista(const int cantidad_datos_vista) {
    this->cantidad_datos_vista = cantidad_datos_vista;
}

void GestorStreamers::cargar_datos(const char *nomArch) {
    ifstream input(nomArch, ios::in);
    Streamer buffer_streamer[250]{}, *buffer_exacto;
    int cant_streamers = 0;
    while (true) {
        buffer_streamer[cant_streamers].leer_streamer(input);
        if (input.eof()) break;
        cant_streamers++;
    }
    buffer_exacto = new Streamer[cant_streamers]{};
    for (int i = 0; i < cant_streamers; i++) {
        buffer_exacto[i].copiar(buffer_streamer[i]);
    }
    data = buffer_exacto;
    cantidad_datos = cant_streamers;
}

void GestorStreamers::mostrar_menu1() {
    cout<<"Menu de Streamers"<<endl<<"Elija una opcion"<<endl;
    cout<<"a)Cargar Datos"<<endl<<"b)Mostrar Reporte"<<endl
    <<"c)Generar Reporte"<<endl<<"d)Generar Todos los Reportes"
    <<endl<<"e)Terminar"<<endl;
}

void GestorStreamers::mostrar_menu() {
    char opcion1, opcion2;
    bool datos_cargados = false;
    while (true) {
        mostrar_menu1();
        cin >>opcion1;
        if (opcion1 == 'e') break;
        else if (opcion1 == 'a') {
            if (!datos_cargados) {
                cargar_datos("streamers.csv");
                datos_cargados = true;
                cout<<"Los datos fueron cargados correctamente"<<endl;
            }
            else {
                cout<<"Los datos ya estan cargados"<<endl;
            }
        }else if (opcion1 == 'b') {
            if (datos_cargados) {
                copiar_datos();
                cout<<setw(5)<<" "<<"1)Reporte Top10 Streamers por numeros de seguidores"<<endl;
                cout<<setw(5)<<" "<<"2)Reporte Bottom10 Streamers por tiempo total transmitido"<<endl;
                cout<<setw(5)<<" "<<"3)Reporte Top5 Categorias con mayor promedio de espectadores"<<endl;
                cout<<setw(5)<<" "<<"4)Reporte de Categoria"<<endl;
                cout<<setw(5)<<" "<<"5)Reporte de Influencia"<<endl;
                cin>>opcion2;
                if (opcion2=='1') {
                    qsort(dataVista, cantidad_datos_vista, sizeof(dataVista[0]), cmpnumeroseguidores);
                    cortar_datos(10);
                    mostrar_streamers();
                }
                else if (opcion2=='2') {
                    qsort(dataVista, cantidad_datos_vista, sizeof(dataVista[0]), cmptiempo);
                    cortar_datos(10);
                    mostrar_streamers();
                }
                else if (opcion2=='3') {
                    qsort(dataVista, cantidad_datos_vista, sizeof(dataVista[0]), cmppromespc);
                    cortar_datos(5);
                    mostrar_streamers();
                }
                else if (opcion2=='4') {
                    qsort(dataVista, cantidad_datos_vista, sizeof(dataVista[0]), cmpcategoria);
                    mostrar_streamers();
                }
                else if (opcion2=='5') {
                    qsort(dataVista, cantidad_datos_vista, sizeof(dataVista[0]), cmpinfluencia);
                    mostrar_streamers();
                }
                else {
                    cout<<"Seleccione una opcion valida"<<endl;
                }
            }
            else {
                cout<<"Primero cargue los datos"<<endl;
            }
        }else if (opcion1 == 'c') {
            if (datos_cargados) {
                cout<<setw(5)<<" "<<"1)Reporte Top10 Streamers por numeros de seguidores"<<endl;
                cout<<setw(5)<<" "<<"2)Reporte Bottom10 Streamers por tiempo total transmitido"<<endl;
                cout<<setw(5)<<" "<<"3)Reporte Top5 Categorias con mayor promedio de espectadores"<<endl;
                cout<<setw(5)<<" "<<"4)Reporte de Categoria"<<endl;
                cout<<setw(5)<<" "<<"5)Reporte de Influencia"<<endl;
                cin>>opcion2;
                if (opcion2=='1') {
                    generarReporte1();
                }
                else if (opcion2=='2') {
                    generarReporte2();
                }
                else if (opcion2=='3') {
                    generarReporte3();
                }
                else if (opcion2=='4') {
                    generarReporte4();
                }
                else if (opcion2=='5') {
                    generarReporte5();
                }
                else {
                    cout<<"Seleccione una opcion valida"<<endl;
                }
            }
            else {
                cout<<"Primero cargue los datos"<<endl;
            }
        }else if (opcion1 == 'd') {
            generarReporte1();
            generarReporte2();
            generarReporte3();
            generarReporte4();
            generarReporte5();
        }
        else {
            cout<<"Seleccione una opcion valida"<<endl;
        }
        cout<<endl<<endl;
    }

}

void GestorStreamers::mostrar_streamers() {
    for (int i = 0; i < cantidad_datos_vista; i++) {
        dataVista[i].mostrar_streamer();
    }
}

void GestorStreamers::mostrar_streamers_reporte(ofstream &output) {
    for (int i = 0; i < cantidad_datos_vista; i++) {
        dataVista[i].mostrar_streamer_reporte(output);
    }
}

void GestorStreamers::copiar_datos() {
    if (dataVista != nullptr) delete[] dataVista;
    dataVista = new Streamer[cantidad_datos]{};
    for (int i = 0; i < cantidad_datos; i++) {
        dataVista[i].copiar(data[i]);
    }
    cantidad_datos_vista = cantidad_datos;
}

void GestorStreamers::cortar_datos(int n) {
    Streamer *aux = new Streamer[n]{};
    for (int i = 0; i < n; i++) {
        aux[i].copiar(dataVista[i]);
    }
    delete[] dataVista;
    dataVista = aux;
    cantidad_datos_vista = n;
}


void GestorStreamers::generarReporte1() {
    copiar_datos();
    ofstream reporte("ReporteTop10PorSeguidores.txt", ios::out);
    qsort(dataVista, cantidad_datos_vista, sizeof(dataVista[0]), cmpnumeroseguidores);
    cortar_datos(10);
    mostrar_streamers_reporte(reporte);
}
void GestorStreamers::generarReporte2() {
    copiar_datos();
    ofstream reporte("ReporteTop10PorTiempo.txt", ios::out);
    qsort(dataVista, cantidad_datos_vista, sizeof(dataVista[0]), cmptiempo);
    cortar_datos(10);
    mostrar_streamers_reporte(reporte);
}
void GestorStreamers::generarReporte3() {
    copiar_datos();
    ofstream reporte("ReporteTop5PorEspectadores.txt", ios::out);
    qsort(dataVista, cantidad_datos_vista, sizeof(dataVista[0]), cmppromespc);
    cortar_datos(5);
    mostrar_streamers_reporte(reporte);
}
void GestorStreamers::generarReporte4() {
    copiar_datos();
    ofstream reporte("ReportePorCategoria.txt", ios::out);
    qsort(dataVista, cantidad_datos_vista, sizeof(dataVista[0]), cmpcategoria);
    mostrar_streamers_reporte(reporte);
}
void GestorStreamers::generarReporte5() {
    copiar_datos();
    ofstream reporte("ReportePorInfluencia.txt", ios::out);
    qsort(dataVista, cantidad_datos_vista, sizeof(dataVista[0]), cmpinfluencia);
    mostrar_streamers_reporte(reporte);
}


