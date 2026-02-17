// Fichero de manejo de excepciones de sensores

#ifndef SENSOR_EXCEPTIONS_H
#define SENSOR_EXCEPTIONS_H

// Directivas de preprocesador
#include <exception>
#include <string>
#include <iostream>



// Excepción para niveles elevados de radón (600 < x ≤ 1000)
class HighRadonException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Nivel de Radón elevado. Se recomienda ventilar los espacios cerrados.";
        }
};
    
    // Excepción para niveles críticos de radón (x > 1000)
class VeryHighRadonException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Nivel de Radón extremadamente alto. Se recomienda evacuar el espacio inmediatamente.";
        }
};


class CriticalTemperatureException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Temperatura crítica detectada. Se recomienda evacuar el espacio inmediatamente.";
        }
};
    
class SensorInitializationException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Error al inicializar el sensor. Revisa los parámetros de entrada.";
        }
};





#endif // SENSOR_EXCEPTIONS_H
    