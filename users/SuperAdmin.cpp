// Directivas de preprocesador

# include "SuperAdmin.h"

// Namespace
using namespace std;

// Constructor de la clase SuperAdmin
SuperAdmin::SuperAdmin(int userId, const string& nif, Database& db) : User(userId, nif, db){
    // Constructor por defecto
}

// Destructor de la clase SuperAdmin
SuperAdmin::~SuperAdmin() {
    // Destructor por defecto
}

// Sobrecarga del operador << para imprimir el objeto SuperAdmin
ostream& operator<<(ostream& os, const SuperAdmin& superAdmin) {
    os << "Super Admin ID: " << superAdmin.getUserId() << endl;
    os << "NIF: " << superAdmin.getNif() << endl;
    os << "Role: Super Admin" << endl;
    return os;
}

// Dashboard para super administrador, tiene acceso a todos los datos de usuarios, sensores y camaras, Puede modificar los roles de Admin y User
void SuperAdmin::showDashboard() {
        system("clear"); // Limpiar la consola al mostrar el dashboard
        // Dashboard de super usuario
        cout << "Interfaz del Super Usuario" << endl;
        cout << "Bienvenido, " << this->getNif() << "!" << endl;
        cout << "Presione enter para continuar..." << endl;
        cin.ignore();
        cin.get();
        system("clear");
    
        // Menu de opciones para el super usuario
        int option = -1;
        while (option != 0) {
            cout << "1. Ver perfil" << endl;
            cout << "3. Ver datos de sensores" << endl;
            cout << "4. Configurar permisos de usuarios" << endl;
            cout << "5. Mostrar listado de usuarios" << endl;
            cout << "0. Salir" << endl;
            cout << "Seleccione una opcion: ";
            cin >> option;
            cin.ignore(); // Limpiar el buffer de entrada
            system("clear");
    
            switch (option) {
                case 1:
                    cout << "Perfil de Super Usuario:" << endl;
                    cout << "ID: " << this->getUserId() << endl;
                    cout << "NIF: " << this->getNif() << endl;
                    break;
                case 2:
                    cout << "Datos de Sensores:" << endl;
                    // Aqui se mostrarian los datos de los sensores
                    sensorsDashboard();
                    break;
                case 3:
                    // LLamada a dashboard de cambio de rol, esta llamara a promote o demote en funcion de la eleccion de usuario
                    roleChangeDashboard();
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


void SuperAdmin::roleChangeDashboard() {
        // Variables necesarias
        string nif;
        int userId;
    
        
        int option = -1;
        while (option != 0) {
            // Dashboard para cambiar de rol de usuario
            cout << "Interfaz de Cambio de Rol" << endl;
            cout << "Seleccione una opcion: " << endl;
            cout << "1. Promover a Administrador" << endl;
            cout << "2. Degradar a Usuario Normal" << endl;
            cout << "0. Salir" << endl;
            cout << "Seleccione una opcion: ";
            cin >> option;
            cin.ignore(); // Limpiar el buffer de entrada
            system("clear");
    
            switch (option) {
                case 1: {
                    cout << "Promoviendo a Administrador..." << endl;
                    // Pedir que usuario se quiere promover a administrador
                    // Pedir el NIF del usuario a promover
                    cout << "Ingrese el NIF del usuario a promover: ";
                    cout << "NIF: ";
                    cin >> nif;
                    cout << endl;
                    // Pedir el ID del usuario a promover
                    cout << "Ingrese el ID del usuario a promover: ";
                    cout << "USER ID: ";
                    cin >> userId;
    
                    cout << endl;
                    // Buscar en la base de datos y devolver el usuario
                    User* userToPromote = db.findUser(userId, nif);
                    if (userToPromote) {
                        // Promover al usuario a administrador
                        promoteUserToAdmin(*userToPromote);
                    } else {
                        cout << "Usuario no encontrado." << endl;
                    }

                    break;
                }
                case 2: {
                    cout << "Degradando a Usuario Normal..." << endl;
                    // Aqui se degradaria al usuario a usuario normal
                    // Pedir que usuario se quiere degradar a usuario normal
                    // Pedir el NIF del usuario a degradar
                    cout << "Ingrese el NIF del usuario a degradar: ";
                    cout << "NIF: ";
                    cin >> nif;
                    cout << endl;
                    // Pedir el ID del usuario a degradar
                    cout << "Ingrese el ID del usuario a degradar: ";
                    cout << "USER ID: ";
                    cin >> userId;
                    cout << endl;
                    // Buscar en la base de datos y devolver el usuario
                    User* userToDemote = db.findUser(userId, nif);
                    if (userToDemote) {
                        // Degradar al usuario a usuario normal
                        demoteAdminToUser(*userToDemote);
                    } else {
                        cout << "Usuario no encontrado." << endl;
                    }
                    
                    break;
                }
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

void SuperAdmin::promoteUserToAdmin(User& user) {
    // Verificar si el usuario es un Admin
    if (dynamic_cast<Admin*>(&user) || dynamic_cast<SuperAdmin*>(&user) || dynamic_cast<Guest*>(&user)) {
        cout << "El usuario ya es un administrador o no puede ser cambiado al rol de administrador." << endl;
        return;
    }
    else {
        // Crear un nuevo Admin con los datos del usuario
        unique_ptr<Admin> newAdmin = make_unique<Admin>(user.getUserId(), user.getNif(), db);
        // Reemplazar el usuario en la base de datos
        db.replaceUser(user.getUserId(), std::move(newAdmin));
        cout << "Usuario promovido a administrador correctamente." << endl;
    }
}

void SuperAdmin::demoteAdminToUser(User& user) {
    // Verificar si el usuario es un Admin
    if (dynamic_cast<Admin*>(&user)) {
        // Crear un nuevo User con los datos del usuario
        unique_ptr<User> newUser = make_unique<User>(user.getUserId(), user.getNif(), db);
        // Reemplazar el usuario en la base de datos
        db.replaceUser(user.getUserId(), std::move(newUser));
        cout << "Administrador degradado a usuario correctamente." << endl;
    } else {
        cout << "El usuario no es un administrador o no puede ser degradado a usuario." << endl;
    }
}
