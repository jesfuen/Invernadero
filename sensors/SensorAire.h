// Clase de sensor de calidad de aire. Mide la calidad del aire en el interior del invernadero
#ifndef SENSOR_AIRE_H
#define SENSOR_AIRE_H

// Directivas de preprocesador
#include "Sensor.h"
// Namespace
using namespace std;
// Definición de la clase SensorAire, hereda de Sensor
class SensorAire : public Sensor {
    public:
        // Constructor de la clase SensorAire
        SensorAire(int id, float calidadAire = 100.0f);
        
        // Destructor de la clase SensorAire
        ~SensorAire();

        // Métodos de la clase SensorAire
        void mostrarDatos() const override; // Mostrar los datos del sensor

        void actualizarDatos() override; // Actualizar los datos del sensor

        void setCalidadAire(float calidad); // Establecer la calidad del aire medida por el sensor
        
    private:
        float calidadAire; // Calidad del aire medida por el sensor
};


#endif // SENSOR_AIRE_H