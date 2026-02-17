// Nuevo concepto de practica de invernadero con sensores y gestion de usuarios
// Unica clase para sensores con multiples funciones, unica clase para usuarios con
// distintos rangos de permisos.

// Directivas de preprocesador
#include <iostream>
#include "users/User.h" // Include de la cabecera de la clase User
#include "users/Admin.h" // Include de la cabecera de la clase Admin
#include "users/SuperAdmin.h" // Include de la cabecera de la clase SuperAdmin
#include "users/Guest.h" // Include de la cabecera de la clase Guest
#include "Database.h" // Include de la cabecera de la clase Database
#include "utils.h"
#include "sensors/SensorTemperatura.h" // Include de la cabecera de la clase SensorTemperatura
#include "sensors/SensorAire.h" // Include de la cabecera de la clase SensorAire
#include "sensors/SensorRadiacion.h" // Include de la cabecera de la clase SensorRadiacion
#include "sensors/SensorHumedad.h" // Include de la cabecera de la clase SensorHumedad
#include "sensors/CamaraTermica.h" // Include de la cabecera de la clase CamaraTermica
#include <cstdlib>

// Función principal
int main() {
    // Crear un objeto Admin y un objeto SuperAdmin
    Database db; // Crear la base de datos

    // Cargar usuarios desde el fichero
    db.loadUsersFromFile("users.dat"); // Cargar los usuarios desde el fichero

    // Crear admin y superadmin si la base de datos esta vacia
    if (db.getUsers().empty()) {
        cout << "No hay usuarios en la base de datos. Creando administrador y super administrador por defecto." << endl;
        
        db.addUser(make_unique<Admin>(1, "12345678A", db));        // directo
        db.addUser(make_unique<SuperAdmin>(2, "87654321B", db));   // directo
        cout << "Administrador y Super Administrador creados por defecto." << endl;
    } else {
        cout << "Base de datos cargada con usuarios existentes." << endl;
    }
    

    // Crear sensores
    auto sensorTemp = make_unique<SensorTemperatura>(1); // Crear un sensor de temperatura
    auto sensorAire = make_unique<SensorAire>(2); // Crear un sensor de calidad de aire
    auto sensorRadiacion = make_unique<SensorRadiacion>(3); // Crear un sensor de radiación
    auto sensorHumedad = make_unique<SensorHumedad>(4); // Crear un sensor de humedad
    auto camaraTermica = make_unique<CamaraTermica>(5); // Crear una cámara térmica
    db.addSensor(std::move(sensorTemp)); // Agregar el sensor de temperatura a la base de datos
    db.addSensor(std::move(sensorAire)); // Agregar el sensor de calidad de aire a la base de datos
    db.addSensor(std::move(sensorRadiacion)); // Agregar el sensor de radiación a la base de datos
    db.addSensor(std::move(sensorHumedad)); // Agregar el sensor de humedad a la base de datos
    db.addSensor(std::move(camaraTermica)); // Agregar la cámara térmica a la base de datos

    system("clear"); // Limpiar la consola al iniciar el programa

    // Mostrar el menú de inicio de sesión
    cout << "Bienvenido al sistema de gestión de invernaderos." << endl;
    cout << "Por favor, inicie sesión o acceda como invitado." << endl;
    login(db); // Llamar a la función de login

    // Guardar los usuarios en el fichero al salir
    db.saveUsersToFile("users.dat"); // Guardar los usuarios en el fichero

    cout << "Gracias por usar el sistema. ¡Hasta luego!" << endl;
    
    return 0;
}
