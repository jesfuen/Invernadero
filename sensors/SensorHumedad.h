// Clase de sensor de humedad

#ifndef SENSOR_HUMEDAD_H
#define SENSOR_HUMEDAD_H

// Directivas de preprocesador
#include "Sensor.h"
// Namespace
using namespace std;
// Definición de la clase SensorHumedad, hereda de Sensor
class SensorHumedad : public Sensor {
    public:
        // Constructor de la clase SensorHumedad
        SensorHumedad(int id, float humedad = 50.0f);
        
        // Destructor de la clase SensorHumedad
        ~SensorHumedad();

        // Métodos de la clase SensorHumedad
        void mostrarDatos() const override; // Mostrar los datos del sensor

        void actualizarDatos() override; // Actualizar los datos del sensor
        
    private:
        float humedad; // Humedad medida por el sensor
};

#endif // SENSOR_HUMEDAD_H