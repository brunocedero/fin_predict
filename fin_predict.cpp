#include <iostream>
#include "carga_datos.h"
#include "CruceMediasMoviles.h"

int main() {
    // Cargar datos
    std::string archivo = "precios.csv";
    std::vector<Precio> datos = cargarDatosDesdeCSV(archivo);

    if (datos.empty()) {
        std::cerr << "No se pudieron cargar datos." << std::endl;
        return 1;
    }

    // Configurar estrategia de cruce de medias móviles (ej., 5 y 20 días)
    CruceMediasMoviles estrategia(5, 20);

    // Ejecutar la estrategia
    double resultado = estrategia.ejecutar(datos);

    // Mostrar el resultado final
    std::cout << "Capital final tras la simulación: " << resultado << std::endl;

    return 0;
}