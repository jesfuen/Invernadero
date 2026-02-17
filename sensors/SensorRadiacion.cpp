// Directivas de preprocesador
#include "SensorRadiacion.h"
#include "../exceptions/SensorExceptions.h" // Include de las excepciones de sensores

// Namespace
using namespace std;
// Constructor de la clase SensorRadiacion
SensorRadiacion::SensorRadiacion(int id, float radonLevel) 
    : Sensor(id), radonLevel(radonLevel) {
    // Inicialización del sensor de radiación con el ID y nivel de Radon proporcionados
}
// Destructor de la clase SensorRadiacion
SensorRadiacion::~SensorRadiacion() {
    // Destructor por defecto
}

void SensorRadiacion::mostrarDatos() const {
    cout << "Interfaz de Sensor de Radiacion" << endl;
    cout << "ID del Sensor: " << getSensorId() << endl;
    cout << "Nivel de Radon: " << radonLevel << " Bq/m^3" << endl;
    if (radonLevel <= 600.0f) {
        cout << "Nivel de Radon: Bajo. No es necesario control" << endl;
    } else if (radonLevel <= 1000.0f) {
        throw HighRadonException();
    } else if (radonLevel <= 1200.0f) {
        throw VeryHighRadonException();
    } else {
        cout << "Nivel de Radon: Crítico. Se recomienda evacuar el espacio inmediatamente y ventilar" << endl;
        cout << "Para ventilar acceda al menu principal y seleccione la opcion de ventilar espacios." << endl;
    }
}

void SensorRadiacion::actualizarDatos() {
    // Simulacion, el nivel de radon debe estar entre 0 y 1200 Bq/m^3.
    // Este valor va creciendo y disminuyendo paulatinamente, simulando un sensor real.
    radonLevel += static_cast<float>(rand() % 100 - 50); // Cambia el nivel de Radon en un rango de -5 a +5 Bq/m^3
    if (radonLevel < 0.0f) {
        radonLevel = 0.0f; // Asegurarse de que el nivel de Radon no sea negativo
    } else if (radonLevel > 1200.0f) {
        radonLevel = 1200.0f; // Asegurarse de que el nivel de Radon no supere el máximo
    }
}

void SensorRadiacion::ventilarEspacios() {
    if (radonLevel >= 1000.0f) {
        radonLevel-= 600.0f; // Disminuir el nivel de Radon en 600 Bq/m^3 al ventilar
    }
}