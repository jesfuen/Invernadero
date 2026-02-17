// Clase sensor de humedad, mide la humedad del interior del invernadero
#include "SensorHumedad.h"
// Namespace
using namespace std;
// Constructor de la clase SensorHumedad
SensorHumedad::SensorHumedad(int id, float humedad) 
    : Sensor(id), humedad(humedad) {
    // Inicialización del sensor de humedad con el ID y humedad proporcionados
}
// Destructor de la clase SensorHumedad
SensorHumedad::~SensorHumedad() {
    // Destructor por defecto
}
// Mostrar los datos del sensor de humedad
void SensorHumedad::mostrarDatos() const {
    cout << "Interfaz de Sensor de Humedad" << endl;
    cout << "ID del Sensor: " << getSensorId() << endl;
    cout << "Humedad: " << humedad << "%" << endl;
}

// Actualizar los datos del sensor de humedad
void SensorHumedad::actualizarDatos() {
    // Simulación, la humedad debe estar entre 0 y 100%.
    // Este valor va creciendo y disminuyendo paulatinamente, simulando un sensor real.
    humedad += static_cast<float>(rand() % 20 - 10) / 10.0f; // Cambia la humedad en un rango de -1 a +1%
    if (humedad < 0.0f) {
        humedad = 0.0f; // Asegurarse de que la humedad no sea negativa
    } else if (humedad > 100.0f) {
        humedad = 100.0f; // Asegurarse de que la humedad no supere el máximo
    }
}