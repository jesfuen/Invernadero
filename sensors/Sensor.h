// Clase base Sensor

#ifndef SENSOR_H
#define SENSOR_H

// Directivas de preprocesador
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

// Namespace
using namespace std;

// Definicion de la clase Sensor
class Sensor {
    public:
        //Constructor de la clase Sensor
        Sensor(int id);

        // Destructor de la clase Sensor
        ~Sensor();

        // Metodos de la clase Sensor
        int getSensorId() const; // Obtener el id del sensor

        void setSensorId(int id); // Establecer el id del sensor

        virtual void mostrarDatos() const = 0; // Mostrar los datos del sensor, metodo virtual

        virtual void actualizarDatos() = 0; // Actualizar los datos del sensor, metodo virtual

    private:
        int sensorId; // Id del sensor
};





#endif // SENSOR_H