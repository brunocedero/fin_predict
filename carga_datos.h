#ifndef CARGA_DATOS_H
#define CARGA_DATOS_H

#include <vector>
#include <string>
#include "Precio.h"

std::vector<Precio> cargarDatosDesdeCSV(const std::string& nombreArchivo);

#endif // CARGA_DATOS_H
