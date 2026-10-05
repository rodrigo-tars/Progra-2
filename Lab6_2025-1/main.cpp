#include "Biblioteca/MinisterioDeTransporte.hpp"

int main() {
    MinisterioDeTransporte ministerioDeTransporte;
    ministerioDeTransporte<"ArchivosDeLectura/TablaDeInfracciones.csv";
    ministerioDeTransporte<="ArchivosDeLectura/EmpresasRegistradas.csv";
    ministerioDeTransporte<<="ArchivosDeLectura/InfraccionesCometidas.csv";
    ministerioDeTransporte>>"ArchivosDeImpresion/Reporte.txt";
    return 0;
}