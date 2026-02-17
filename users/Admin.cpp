// Directivas preprocesador
#include "Admin.h"
#include <memory>

// namespace
using namespace std;



// Constructor de la clase Admin
Admin::Admin(int userId, const string& nif, Database& db) : User(userId, nif, db) {
    // Constructor por defecto
}
// Destructor de la clase Admin
Admin::~Admin() {
    // Destructor por defecto
}

// Mostrar dashboard para administrador, tiene acceso a todos los datos de usuarios y sensores
void Admin::showDashboard() {
        system("clear"); // Limpiar la consola al mostrar el dashboard
        // Dashboard de administrador
        cout << "Interfaz del Administrador" << endl;
        cout << "Bienvenido, " << getNif() << "!" << endl;
        cout << "Presione enter para continuar..." << endl;
        cin.ignore();
        cin.get();
        system("clear");
    
        // Menu de opciones para el administrador
        int option = -1;
        while (option != 0) {
            cout << "1. Ver perfil" << endl;
            cout << "2. Gestionar usuarios" << endl;
            cout << "3. Ver datos de sensores" << endl;
            cout << "4. Mostrar listado de usuarios" << endl;
            cout << "0. Salir" << endl;
            cout << "Seleccione una opcion: ";
            cin >> option;
            cin.ignore(); // Limpiar el buffer de entrada
            system("clear");
    
            switch (option) {
                case 1:
                    cout << "Perfil de Administrador:" << endl;
                    cout <<  *this << endl; // Utilizando la sobrecarga del operador <<
                    break;
                case 2:{
                    cout << "Gestionar Usuarios:" << endl;
                    // Aqui se gestionarian los usuarios
                    // Se utilizan metodos de la clase Database para la gestion de usuarios, con un dashboard personalizado de gestion
                    manageDashboard();
                    break;
                }
                case 3:
                    cout << "Datos de Sensores:" << endl;
                    // Aqui se mostrarian los datos de los sensores
                    sensorsDashboard();
                    break;
                case 4:
                    db.showUsers();
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

void Admin::manageDashboard() {

    // Variables necesarias
        int newUserId;
        string newNif;
        // Dashboard de gestion de usuarios
        cout << "Interfaz de Gestion de Usuarios" << endl;
        cout << "Bienvenido, " << getNif() << "!" << endl;
        cout << "Presione enter para continuar..." << endl;
        cin.ignore();
        cin.get();
        system("clear");

        // Menu de opciones para la gestion de usuarios
        int option = -1;
        while (option != 0) {
            cout << "1. Agregar nuevo usuario al sistema" << endl;
            cout << "2. Eliminar usuario del sistema" << endl;
            cout << "0. Salir" << endl;
            cout << "Seleccione una opcion: ";
            cin >> option;
            cin.ignore(); // Limpiar el buffer de entrada
            system("clear");

            switch (option) {
                case 1: {
                    cout << "Introduzca los datos del nuevo usuario:" << endl;
                    cout << "USER ID: ";
                    cin >> newUserId;
                    cout << "NIF: ";
                    try {
                        cin >> newNif;
                        Admin::nifValidation(newNif);  // puede lanzar nifInvalidoException
                    } catch (const nifInvalidoException& e) {
                        cout << "[ERROR] " << e.what() << endl;
                        break;
                    }
    
                    try {
                        auto newUser = make_unique<User>(newUserId, newNif, db);
                        db.addUser(std::move(newUser));  // puede lanzar UsuarioYaExistenteException
                        cout << "Usuario creado correctamente." << endl;
                    } catch (const UsuarioYaExistenteException& e) {
                        cout << "[ERROR] " << e.what() << endl;
                    }
                    break;
                }
    
                case 2: {
                    cout << "Eliminar usuario del sistema:" << endl;
                    try {
                        db.removeUser();  // puede lanzar UsuarioProtegidoException
                    } catch (const UsuarioProtegidoException& e) {
                        cout << "[ERROR] " << e.what() << endl;
                    }
                    break;
                }
    
                case 0:
                    cout << "Saliendo del dashboard..." << endl;
                    break;
    
                default:
                    cout << "Opción no válida, intente de nuevo." << endl;
            }
    
            if (option != 0) {
                cout << "Presione Enter para continuar..." << endl;
                cin.ignore();
                cin.get();
                system("clear");
            }
        }
}

// Validación de NIF
void Admin::nifValidation(const string& nif) {
    if (nif.length() != 9 || !isalpha(nif[8]) || !isdigit(nif[0]) || !isdigit(nif[1]) || !isdigit(nif[2]) || !isdigit(nif[3]) || !isdigit(nif[4]) || !isdigit(nif[5]) || !isdigit(nif[6]) || !isdigit(nif[7])) {
        throw nifInvalidoException();
    }
}