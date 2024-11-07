#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H

#include <vector>
#include "Precio.h"

class Estrategia {
public:
    // Funci�n virtual que cada estrategia espec�fica implementar�
    virtual double ejecutar(const std::vector<Precio>& datos) = 0;

    // Destructor virtual
    virtual ~Estrategia() = default;
};
    
#endif // ESTRATEGIA_H
