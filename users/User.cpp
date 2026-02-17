
// Directivas de preprocesador
#include "User.h" // Include de la cabecera de la clase User
#include <iostream>
#include <string>
#include "Guest.h"

// Sobrecarga del operador << para imprimir el objeto User
std::ostream& operator<<(std::ostream& os, const User& user) {
    user.showProfile(os);
    return os;
}

// Getters
// Obtener userId
int User::getUserId() const {
    return userId;
}

// Obtener nif
std::string User::getNif() const {
    return nif;
}

// Setters
// Establecer userId
void User::setUserId(int userId) {
    this->userId = userId;
}

// Establecer nif
void User::setNif(const std::string& nif) {
    this->nif = nif;
}

void User::showDashboard() {
        system("clear"); // Limpiar la consola al mostrar el dashboard   
        // Dashboard de usuario
        cout << "Interfaz del Usuario" << endl;
        cout << "Bienvenido, " << this->getNif() << "!" << endl;
        cout << "Presione enter para continuar..." << endl;
        cin.ignore();
        cin.get();
        system("clear");
    
        // Menu de opciones para el usuario
        int option = -1;
        while (option != 0) {
            cout << "1. Ver perfil" << endl;
            cout << "2. Ver datos de sensores" << endl;
            cout << "3. Modificar configuracion de sensores" << endl;
            cout << "0. Salir" << endl;
            cout << "Seleccione una opcion: ";
            cin >> option;
            cin.ignore(); // Limpiar el buffer de entrada
            system("clear");
            switch (option) {
                case 1:
                    cout << "Perfil de Usuario:" << endl;
                    cout << *this << endl; // Utilizando la sobrecarga del operador <<
                    break;
                case 2:
                    sensorsDashboard(); // Llamada al dashboard de sensores
                    break;
                case 3:
                    cout << "Modificar configuracion de sensores:" << endl;
                    // Aqui se modificaria la configuracion de los sensores
                    break;
                case 0:
                    cout << "Saliendo del dashboard..." << endl;
                    break;
                default:
                    cout << "Opcion no valida, intente de nuevo." << endl;
            }
            if (option != 0) {
                cout << "Presione Enter para continuar..." << endl;
                cin.ignore();
                cin.get(); // Espera a que el usuario presione Enter
            }
            system("clear");
        }
    }

void User::sensorsDashboard() {
    cout << "Interfaz de Sensores" << endl;
    cout << "Bienvenido, " << this->getNif() << "!" << endl;
    cout << "Presione enter para continuar..." << endl;
    cin.ignore();
    cin.get();
    system("clear");
    // Menu de opciones para el usuario
    int option = -1;
    while (option != 0) {
        cout << "1. Ver sensor temperatura" << endl;
        cout << "2. Ver sensor radiacion" << endl;
        cout << "3. Ver sensor humedad" << endl;
        cout << "4. Ver sensor calidad de aire" << endl;
        cout << "5. Ver camara termica" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> option;
        cin.ignore(); // Limpiar el buffer de entrada
        system("clear");

        const auto& sensores = db.getSensors(); // Obtener los sensores de la base de datos

        switch (option) {
            case 1:
                cout << "Sensor de Temperatura:" << endl;
                for (const auto& s : sensores) {
                    if (auto temp = dynamic_cast<SensorTemperatura*>(s.get())) {
                        temp->actualizarDatos(); // Actualizar los datos del sensor de temperatura
                        temp->mostrarDatos();
                        cout << "-----------------------------" << endl;
                    }
                }
                break;
            case 2:
                cout << "Sensor de Radiación:" << endl;
                for (const auto& s : sensores) {
                    if (auto rad = dynamic_cast<SensorRadiacion*>(s.get())) {
                        rad->actualizarDatos(); // Actualizar los datos del sensor
            
                        try {
                            rad->mostrarDatos(); // Puede lanzar excepción
                        } catch (const VeryHighRadonException& e) {
                            cout << "[CRÍTICO] " << e.what() << endl;
            
                            // Preguntar si se desea activar la ventilación
                            char opcion;
                            cout << "¿Desea activar la ventilación de emergencia? (s/n): ";
                            cin >> opcion;
                            cin.ignore();
            
                            if (opcion == 's' || opcion == 'S') {
                                rad->ventilarEspacios(); // Reducir nivel de radón
                            }
            
                        } catch (const HighRadonException& e) {
                            cout << "[ALERTA] " << e.what() << endl;
                        }
            
                        cout << "-----------------------------" << endl;
                    }
                }
                break;
            case 3:
                cout << "Sensor de Humedad:" << endl;
                for (const auto& s : sensores) {
                    if (auto hum = dynamic_cast<SensorHumedad*>(s.get())) {
                        hum->actualizarDatos(); // Actualizar los datos del sensor de humedad
                        hum->mostrarDatos();
                        cout << "-----------------------------" << endl;
                    }
                }
                break;
            case 4:
                cout << "Sensor de Calidad de Aire:" << endl;
                // Aqui se mostrarian los datos del sensor de calidad de aire
                for (const auto& s : sensores) {
                    if (auto aire = dynamic_cast<SensorAire*>(s.get())) {
                        aire->actualizarDatos(); // Actualizar los datos del sensor de calidad de aire
                        aire->mostrarDatos();
                        cout << "-----------------------------" << endl;
                    }
                }
                break;
            case 5:
                cout << "Camara Termica:" << endl;
                for (const auto& s : sensores) {
                    if (auto cam = dynamic_cast<CamaraTermica*>(s.get())) {
                        try {
                            if (dynamic_cast<Guest*>(this)) {
                                throw AccesoDenegadoException();
                            }
                
                            cam->actualizarDatos();
                            cam->mostrarDatos();
                            cout << "-----------------------------" << endl;
                
                        } catch (const AccesoDenegadoException& e) {
                            cout << "[ERROR] " << e.what() << endl;
                        }
                    }
                }
                break;
            case 0:
                cout << "Saliendo del dashboard..." << endl;
                break;
            default:
                cout << "Opcion no valida, intente de nuevo." << endl;
        }
        if (option != 0) {
            cout << "Presione Enter para continuar..." << endl;
            cin.ignore();
            cin.get(); // Espera a que el usuario presione Enter
        }
        system("clear");
    }
}

// Metodo save
void User::save(std::ostream& out) const {
    out.write(reinterpret_cast<const char*>(&userId), sizeof(userId));
    size_t size = nif.size();
    out.write(reinterpret_cast<const char*>(&size), sizeof(size));
    out.write(nif.c_str(), size);
}

void User::load(std::istream& in) {
    in.read(reinterpret_cast<char*>(&userId), sizeof(userId));
    size_t size;
    in.read(reinterpret_cast<char*>(&size), sizeof(size));
    nif.resize(size);
    in.read(&nif[0], size);
}






