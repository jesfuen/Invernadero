// Fichero cabecera de la clase Sensor de radiacion. Mide el valor de Radon

#ifndef SENSOR_RADIACION_H
#define SENSOR_RADIACION_H

// Directivas de preprocesador
#include "Sensor.h"

// Namespace
using namespace std;

// Definicion de la clase SensorRadiacion, hereda de Sensor
class SensorRadiacion : public Sensor {
    public:
        // Constructor de la clase SensorRadiacion
        SensorRadiacion(int id, float radonLevel = 900.0f);
        // Destructor de la clase SensorRadiacion
        ~SensorRadiacion();

        // Metodos de la clase SensorRadiacion
        void mostrarDatos() const override;

        void actualizarDatos() override;

        // Ventilar espacios si el nivel de Radon es elevado (disminuir el nivel de Radon)
        void ventilarEspacios();
    private:
        float radonLevel; // Nivel de Radon medido por el sensor
};


#endif // SENSOR_RADIACION_H