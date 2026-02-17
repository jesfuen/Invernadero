// Clase sensor de temperatura, mide la temperatura del interior del invernadero
#ifndef SENSOR_TEMPERATURA_H
#define SENSOR_TEMPERATURA_H

// Directivas de preprocesador
#include "Sensor.h"

// Namespace
using namespace std;

// Definicion de la clase SensorTemperatura, hereda de Sensor
class SensorTemperatura : public Sensor {
    public:
        // Constructor de la clase SensorTemperatura
        SensorTemperatura(int id, float temperatura = 20.0f);
        
        // Destructor de la clase SensorTemperatura
        ~SensorTemperatura();

        // Metodos de la clase SensorTemperatura
        void mostrarDatos() const override; // Mostrar los datos del sensor

        void actualizarDatos() override; // Actualizar los datos del sensor

        void setTemperatura(float temp); // Establecer la temperatura medida por el sensor
        
    private:
        float temperatura; // Temperatura medida por el sensor
};

#endif // SENSOR_TEMPERATURA_H