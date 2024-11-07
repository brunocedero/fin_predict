#include "CruceMediasMoviles.h"

double CruceMediasMoviles::calcularMedia(const std::vector<Precio>& datos, int inicio, int periodo) {
    double suma = 0.0;
    for (int i = inicio; i < inicio + periodo; ++i) {
        suma += datos[i].valor;
    }
    return suma / periodo;
}

double CruceMediasMoviles::ejecutar(const std::vector<Precio>& datos) {
    double capital = 10000.0; // Capital inicial
    double posicion = 0.0;    // Valor de la posición actual
    bool tienePosicion = false;

    for (size_t i = periodoLargo; i < datos.size(); ++i) {
        double mediaCorta = calcularMedia(datos, i - periodoCorto, periodoCorto);
        double mediaLarga = calcularMedia(datos, i - periodoLargo, periodoLargo);

        // Compra: cruce de media corta por encima de media larga
        if (!tienePosicion && mediaCorta > mediaLarga) {
            posicion = capital / datos[i].valor;
            capital = 0.0;
            tienePosicion = true;
        }
        // Venta: cruce de media corta por debajo de media larga
        else if (tienePosicion && mediaCorta < mediaLarga) {
            capital = posicion * datos[i].valor;
            posicion = 0.0;
            tienePosicion = false;
        }
    }

    // Si queda alguna posición abierta, la cerramos al final
    if (tienePosicion) {
        capital = posicion * datos.back().valor;
    }

    return capital; // Retorno final del capital
}
