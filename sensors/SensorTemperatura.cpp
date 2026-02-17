// Clase de sensor de temperatura
#include "SensorTemperatura.h"

// Constructor de la clase SensorTemperatura
SensorTemperatura::SensorTemperatura(int id, float temperatura) 
    : Sensor(id), temperatura(temperatura) {
    // Inicialización del sensor de temperatura con el ID y temperatura proporcionados
}
// Destructor de la clase SensorTemperatura
SensorTemperatura::~SensorTemperatura() {
    // Destructor por defecto
}
// Mostrar los datos del sensor de temperatura
void SensorTemperatura::mostrarDatos() const {
    cout << "Interfaz de Sensor de Temperatura" << endl;
    cout << "ID del Sensor: " << getSensorId() << endl;
    cout << "Temperatura: " << temperatura << " °C" << endl;
    if (temperatura < 15.0f) {
        cout << "Temperatura: Baja. Se recomienda calentar el invernadero." << endl;
    } else if (temperatura <= 25.0f) {
        cout << "Temperatura: Ideal para el crecimiento de plantas." << endl;
    } else if (temperatura <= 35.0f) {
        cout << "Temperatura: Alta. Se recomienda modificar la temperatura del termostato exterior." << endl;
    } else {
        cout << "Temperatura: Crítica. Se recomienda evacuar el espacio inmediatamente." << endl;
    }
}

// Actualizar los datos del sensor de temperatura
void SensorTemperatura::actualizarDatos() {
    // Simulación, la temperatura debe estar entre 0 y 50 grados Celsius.
    // Este valor va creciendo y disminuyendo paulatinamente, simulando un sensor real.
    temperatura += static_cast<float>(rand() % 10 - 5) / 10.0f; // Cambia la temperatura en un rango de -0.5 a +0.5 grados Celsius
    if (temperatura < 0.0f) {
        temperatura = 0.0f; // Asegurarse de que la temperatura no sea negativa
    } else if (temperatura > 50.0f) {
        temperatura = 50.0f; // Asegurarse de que la temperatura no supere el máximo
    }
}

// Establecer la temperatura medida por el sensor
void SensorTemperatura::setTemperatura(float temp) {
    if (temp < 0.0f) {
        temperatura = 0.0f; // Asegurarse de que la temperatura no sea negativa
    } else if (temp > 50.0f) {
        temperatura = 50.0f; // Asegurarse de que la temperatura no supere el máximo
    } else {
        temperatura = temp; // Establecer la temperatura medida por el sensor
    }
}