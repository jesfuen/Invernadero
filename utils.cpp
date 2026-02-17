// Fichero de utilidades comunes para el sistema

#include "Database.h"
#include "users/User.h"
#include "users/Guest.h"

// Funcion de login
void login(Database& db) {
    bool exitProgram = false;

    while (!exitProgram) {
        int option = -1;  // Inicializar aquí
        cout << "======= LOGIN =======" << endl;
        cout << "1. Iniciar sesión\n";
        cout << "2. Acceder como invitado\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> option;

        switch (option) {
            case 1: {
                int userId;
                string nif;

                cout << "ID de usuario: ";
                cin >> userId;
                cout << "NIF: ";
                cin >> nif;

                try {
                    User* user = db.findUser(userId, nif);
                    if (!user) throw CredencialesInvalidasException();

                    cout << "\nLogin exitoso.\n";
                    user->showDashboard();
                } catch (const CredencialesInvalidasException& e) {
                    cout << "[ERROR] " << e.what() << endl;
                }
                break;
            }
            case 2: {
                Guest guest(db);
                guest.showDashboard();
                break;
            }
            case 0:
                exitProgram = true;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }

        if (!exitProgram) {
            cout << "\n¿Desea cerrar el programa? (s/n): ";
            char choice;
            cin >> choice;
            if (choice == 's' || choice == 'S') {
                exitProgram = true;
            }
            system("clear");  // Limpieza visual antes de volver a mostrar el menú
        }
    }
}


