#ifndef CRUCEMEDIASMOVILES_H
#define CRUCEMEDIASMOVILES_H

#include "Estrategia.h"

class CruceMediasMoviles : public Estrategia {
public:
    CruceMediasMoviles(int corto, int largo) : periodoCorto(corto), periodoLargo(largo) {}

    double ejecutar(const std::vector<Precio>& datos) override;

private:
    int periodoCorto;
    int periodoLargo;

    // Funci�n para calcular la media m�vil de una lista de precios
    double calcularMedia(const std::vector<Precio>& datos, int inicio, int periodo);
};

#endif // CRUCEMEDIASMOVILES_H
