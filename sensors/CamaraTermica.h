// Clase de camara termica.

#ifndef CAMARA_TERMICA_H
#define CAMARA_TERMICA_H

// Directivas de preprocesador
#include "Sensor.h"
#include <iostream>
#include <string>
// Namespace
using namespace std;
// Definición de la clase CamaraTermica, hereda de Sensor
class CamaraTermica : public Sensor {
    public:
        // Constructor de la clase CamaraTermica
        CamaraTermica(int id, float temperaturaMaxima = 30.0f, float temperaturaMinima = 15.0f);
        // Destructor de la clase CamaraTermica
        ~CamaraTermica();
        // Métodos de la clase CamaraTermica
        void mostrarDatos() const override; // Mostrar los datos de la cámara térmica
        void actualizarDatos() override; // Actualizar los datos de la cámara térmica

    private:
        float temperaturaMaxima; // Temperatura máxima medida por la cámara térmica
        float temperaturaMinima; // Temperatura mínima medida por la cámara térmica
};

#endif // CAMARA_TERMICA_H