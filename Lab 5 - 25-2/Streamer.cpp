//
//
//

#include "Streamer.hpp"

#include <complex>


Streamer::Streamer() {
    cuenta = nullptr;
    tiempo_total = 0.0;
    promedio_espectadores = 0.0;
    n_seguidores = 0;
    categoria = nullptr;
}

Streamer::Streamer(const Streamer &s) {
    categoria = nullptr;
    cuenta = nullptr;
    *this = s;
}

void Streamer::operator=(const Streamer &streamer) {
    setCuenta(streamer.cuenta);
    setCategoria(streamer.categoria);
    tiempo_total = streamer.tiempo_total;
    promedio_espectadores = streamer.promedio_espectadores;
    n_seguidores = streamer.n_seguidores;
}

Streamer::~Streamer() {
    if (categoria!=nullptr) delete [] categoria;
    if (cuenta!=nullptr) delete [] cuenta;
}

long long Streamer::get_tiempo_total() const {
    return tiempo_total;
}

void Streamer::set_tiempo_total(const long long tiempo_total) {
    this->tiempo_total = tiempo_total;
}

double Streamer::get_promedio_espectadores() const {
    return promedio_espectadores;
}

void Streamer::set_promedio_espectadores(const double promedio_espectadores) {
    this->promedio_espectadores = promedio_espectadores;
}

int Streamer::get_n_seguidores() const {
    return n_seguidores;
}

void Streamer::set_n_seguidores(const int n_seguidores) {
    this->n_seguidores = n_seguidores;
}
void Streamer::getCuenta(char *_cuenta) const {
    if (cuenta==nullptr) {
        _cuenta[0] = '\0';
    }
    else {
        strcpy(_cuenta, cuenta);
    }
}
void Streamer::setCuenta(const char *_cuenta) {
    if (cuenta!=nullptr) delete [] cuenta;
    cuenta = new char[strlen(_cuenta)+1];
    strcpy(cuenta, _cuenta);
}
void Streamer::getCategoria(char *_categoria) const {
    if (categoria==nullptr) {
        _categoria[0] = '\0';
    }
    else {
        strcpy(_categoria, categoria);
    }
}
void Streamer::setCategoria(const char *_categoria) {
    if (categoria!=nullptr) delete [] categoria;
    categoria = new char[strlen(_categoria)+1];
    strcpy(categoria, _categoria);
}

void Streamer::mostrar_streamer() {
    cout<<cuenta<<setw(20-strlen(cuenta))<<" "<<categoria
    <<setw(30-strlen(categoria))<<promedio_espectadores<<setw(20)
    <<n_seguidores<<setw(20)<<tiempo_total<<endl;
}

void Streamer::mostrar_streamer_reporte(ofstream &output) {
    output<<cuenta<<setw(20-strlen(cuenta))<<" "<<categoria
    <<setw(30-strlen(categoria))<<promedio_espectadores<<setw(20)
    <<n_seguidores<<setw(20)<<tiempo_total<<endl;
}

//XStormHD,5758257274,38932.69,4865726,PUBG
void Streamer::leer_streamer(ifstream &input) {
    char ignorar, *_cuenta, *_categoria;
    _cuenta = LeerConDelimitador(input, ',');
    if (input.eof()) return;
    input>>tiempo_total>>ignorar>>promedio_espectadores>>ignorar
    >>n_seguidores>>ignorar;
    _categoria = LeerConDelimitador(input, '\n');
    setCuenta(_cuenta);
    setCategoria(_categoria);
}

void Streamer::copiar(Streamer s) {
    *this = s;
}

int cmpnumeroseguidores(const void *dato1,const void *dato2) {
    Streamer *s1 = (Streamer *)dato1;
    Streamer *s2 = (Streamer *)dato2;

    return s2[0].get_n_seguidores() - s1[0].get_n_seguidores();
}

int cmptiempo(const void *dato1,const void *dato2) {
    Streamer *s1 = (Streamer *)dato1;
    Streamer *s2 = (Streamer *)dato2;
    if (s1[0].get_tiempo_total() > s2[0].get_tiempo_total()) return 1;
    if (s1[0].get_tiempo_total() == s2[0].get_tiempo_total()) return 0;
    return -1;

}


int cmppromespc(const void *dato1,const void *dato2) {
    Streamer *s1 = (Streamer *)dato1;
    Streamer *s2 = (Streamer *)dato2;

    if (s1[0].get_promedio_espectadores() < s2[0].get_promedio_espectadores()) return 1;
    if (s1[0].get_promedio_espectadores() == s2[0].get_promedio_espectadores()) return 0;
    return -1;

}

int cmpcategoria(const void *dato1,const void *dato2) {
    Streamer *s1 = (Streamer *)dato1;
    Streamer *s2 = (Streamer *)dato2;
    char *cat1, *cat2;
    cat1 = new char [50]{};
    cat2 = new char [50]{};
    s1[0].getCategoria(cat1);
    s2[0].getCategoria(cat2);
    return strcmp(cat1,cat2);

}

int cmpinfluencia(const void *dato1,const void *dato2) {
    Streamer *s1 = (Streamer *)dato1;
    Streamer *s2 = (Streamer *)dato2;
    double inf1, inf2;
    inf1 = ((s1[0].get_promedio_espectadores() * s1[0].get_tiempo_total())/log(s1[0].get_n_seguidores()+1));
    inf2 = ((s2[0].get_promedio_espectadores() * s2[0].get_tiempo_total())/log(s2[0].get_n_seguidores()+1));
    if (inf1 < inf2) return 1;
    if (inf1 == inf2) return 0;
    return -1;
}


