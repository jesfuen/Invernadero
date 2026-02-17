// Clase base sensor
#include "Sensor.h"

// Constructor de la clase Sensor
Sensor::Sensor(int id) : sensorId(id) {
    // Inicialización del sensor con el ID proporcionado
}

// Destructor de la clase Sensor
Sensor::~Sensor() {
}

// Obtener el id del sensor
int Sensor::getSensorId() const {
    return sensorId;
}

// Establecer el id del sensor
void Sensor::setSensorId(int id) {
    sensorId = id;
}