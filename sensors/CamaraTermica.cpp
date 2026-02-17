// Clase de camara termica
#include "CamaraTermica.h"

// Namespace
using namespace std;

// Constructor de la clase CamaraTermica
CamaraTermica::CamaraTermica(int id, float temperaturaMaxima, float temperaturaMinima)
    : Sensor(id), temperaturaMaxima(temperaturaMaxima), temperaturaMinima(temperaturaMinima) {
    // Inicialización de la cámara térmica con el ID, temperatura máxima y mínima proporcionados
}
// Destructor de la clase CamaraTermica
CamaraTermica::~CamaraTermica() {
    // Destructor por defecto
}
// Mostrar los datos de la cámara térmica
void CamaraTermica::mostrarDatos() const {
    cout << "Interfaz de Camara Termica" << endl;
    cout << "ID del Sensor: " << getSensorId() << endl;
    cout << "Temperatura Máxima: " << temperaturaMaxima << " °C" << endl;
    cout << "Temperatura Mínima: " << temperaturaMinima << " °C" << endl;
}

// Actualizar los datos de la cámara térmica
void CamaraTermica::actualizarDatos() {
    // Simulación, la temperatura máxima y mínima deben estar entre 0 y 50 grados Celsius.
    // Estos valores van creciendo y disminuyendo paulatinamente, simulando un sensor real.
    temperaturaMaxima += static_cast<float>(rand() % 10 - 5) / 10.0f; // Cambia la temperatura máxima en un rango de -0.5 a +0.5 grados Celsius
    temperaturaMinima += static_cast<float>(rand() % 10 - 5) / 10.0f; // Cambia la temperatura mínima en un rango de -0.5 a +0.5 grados Celsius

    if (temperaturaMaxima < 0.0f) {
        temperaturaMaxima = 0.0f; // Asegurarse de que la temperatura máxima no sea negativa
    } else if (temperaturaMaxima > 50.0f) {
        temperaturaMaxima = 50.0f; // Asegurarse de que la temperatura máxima no supere el máximo
    }

    if (temperaturaMinima < 0.0f) {
        temperaturaMinima = 0.0f; // Asegurarse de que la temperatura mínima no sea negativa
    } else if (temperaturaMinima > 50.0f) {
        temperaturaMinima = 50.0f; // Asegurarse de que la temperatura mínima no supere el máximo
    }
}