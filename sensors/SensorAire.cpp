// Clase sensor calidad de aire

// Directivas de preprocesador
#include "SensorAire.h"
// Namespace
using namespace std;

// Constructor de la clase SensorAire
SensorAire::SensorAire(int id, float calidadAire) 
    : Sensor(id), calidadAire(calidadAire) {
    // Inicialización del sensor de calidad de aire con el ID y calidad de aire proporcionados
}
// Destructor de la clase SensorAire
SensorAire::~SensorAire() {
    // Destructor por defecto
}
// Mostrar los datos del sensor de calidad de aire
void SensorAire::mostrarDatos() const {
    cout << "Interfaz de Sensor de Calidad de Aire" << endl;
    cout << "ID del Sensor: " << getSensorId() << endl;
    cout << "Calidad del Aire: " << calidadAire << "%" << endl;
    if (calidadAire >= 80.0f) {
        cout << "Calidad del Aire: Excelente. No es necesario tomar medidas." << endl;
    } else if (calidadAire >= 50.0f) {
        cout << "Calidad del Aire: Buena. Se recomienda ventilar el espacio." << endl;
    } else if (calidadAire >= 30.0f) {
        cout << "Calidad del Aire: Regular. Se recomienda ventilar el espacio y evitar actividades que generen contaminación." << endl;
    } else {
        cout << "Calidad del Aire: Mala. Se recomienda evacuar el espacio inmediatamente." << endl;
    }
}
// Actualizar los datos del sensor de calidad de aire
void SensorAire::actualizarDatos() {
    // Simulación, la calidad del aire debe estar entre 0 y 100%.
    // Este valor va creciendo y disminuyendo paulatinamente, simulando un sensor real.
    calidadAire += static_cast<float>(rand() % 20 - 10) / 10.0f; // Cambia la calidad del aire en un rango de -1 a +1%
    if (calidadAire < 0.0f) {
        calidadAire = 0.0f; // Asegurarse de que la calidad del aire no sea negativa
    } else if (calidadAire > 100.0f) {
        calidadAire = 100.0f; // Asegurarse de que la calidad del aire no supere el máximo
    }
}
// Establecer la calidad del aire medida por el sensor
void SensorAire::setCalidadAire(float calidad) {
    if (calidad < 0.0f) {
        calidadAire = 0.0f; // Asegurarse de que la calidad del aire no sea negativa
    } else if (calidad > 100.0f) {
        calidadAire = 100.0f; // Asegurarse de que la calidad del aire no supere el máximo
    } else {
        calidadAire = calidad; // Establecer la calidad del aire medida por el sensor
    }
}