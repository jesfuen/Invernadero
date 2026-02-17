// Clase derivada Guest. Esta clase no usa ni id ni nif, ya que es un invitado y no tiene acceso a los datos de usuario.

// Directivas de preprocesador
#include "Guest.h"

// Namespace
using namespace std;

// Constructor de la clase Guest
Guest::Guest(Database& db) : User(0, "", db) { // Llamamos al constructor de User con userId 0 y nif vacio
    // Constructor por defecto
}

// Destructor de la clase Guest
Guest::~Guest() {
    // Destructor por defecto
}

void Guest::showDashboard() {
    system("clear"); // Limpiar la consola al mostrar el dashboard
    // Dashboard de invitado
    cout << "Interfaz del Invitado" << endl;
    cout << "Bienvenido, Invitado!" << endl;
    cout << "Presione enter para continuar..." << endl;
    cin.ignore();
    cin.get();
    system("clear");

    // Menu de opciones para el invitado
    int option = -1;
    while (option != 0) {
        cout << "1. Ver datos de sensores" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> option;
        cin.ignore(); // Limpiar el buffer de entrada
        system("clear");

        switch (option) {
            case 1:
                cout << "Datos de Sensores:" << endl;
                // Aqui se mostrarian los datos de los sensores
                sensorsDashboard();
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

