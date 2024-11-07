#include "carga_datos.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Precio> cargarDatosDesdeCSV(const std::string& nombreArchivo) {
    std::vector<Precio> datos;
    std::ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
        return datos;
    }

    std::string linea;
    while (getline(archivo, linea)) {
        std::istringstream ss(linea);
        std::string fecha, valorStr;

        if (getline(ss, fecha, ',') && getline(ss, valorStr)) {
            Precio precio;
            precio.fecha = fecha;
            precio.valor = std::stod(valorStr);
            datos.push_back(precio);
        }
    }

    archivo.close();
    return datos;
}
