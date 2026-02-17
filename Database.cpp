// Fichero de la clase Database.

// Directivas de preprocesador
#include <iostream>
#include <string>
#include <set>
#include "Database.h"
#include "users/User.h"
#include "users/Admin.h"
#include "users/SuperAdmin.h"
#include "exceptions/UserExceptions.h" 

// Namespace
using namespace std;
// Constructor de la clase Database
Database::Database() {
    // Constructor por defecto
}
// Destructor de la clase Database
Database::~Database() {
    // Destructor por defecto
    cout << "Destruyendo la base de datos..." << endl;
    users.clear(); // Limpiar el set de usuarios
    sensors.clear(); // Limpiar el vector de sensores
    cout << "Base de datos destruida." << endl;
}

// Añadir usuario
void Database::addUser(std::unique_ptr<User> user) {
    for (const auto& existingUser : users) {
        if (existingUser->getUserId() == user->getUserId() ||
            existingUser->getNif() == user->getNif()) {
            throw UsuarioYaExistenteException();
        }
    }

    users.insert(std::move(user));
    std::cout << "Usuario agregado correctamente." << std::endl;
}

void Database::removeUser() {
    int userId;
    string nif;

    cout << "Ingrese el ID del usuario a eliminar: ";
    cin >> userId;
    cout << "Ingrese el NIF del usuario a eliminar: ";
    cin >> nif;

    for (auto it = users.begin(); it != users.end(); ++it) {
        if ((*it)->getUserId() == userId && (*it)->getNif() == nif) {
            // Comprobar si es Admin o SuperAdmin
            if (dynamic_cast<Admin*>((*it).get()) || dynamic_cast<SuperAdmin*>((*it).get())) {
                throw UsuarioProtegidoException();
            }

            users.erase(it);
            cout << "Usuario eliminado." << endl;
            return;
        }
    }

    cout << "Usuario no encontrado." << endl;
}


// Buscar usuario por ID y NIF
User* Database::findUser(int& userId, const string& nif) const {
    for (const auto& user : users) {
        if (user->getUserId() == userId && user->getNif() == nif) {
            cout << "Usuario encontrado: " << user->getNif() << endl;
            return user.get(); // devolvemos puntero crudo (no ownership)
        }
    }

    cout << "Usuario no encontrado." << endl;
    return nullptr;
}

// Mostrar listado de usuarios
void Database::showUsers() const {
    cout << "============== USERS LIST ================" << endl;
    for (const auto& user : users) {
        cout << *user << endl;
        cout << "=========================================" << endl;
    }
}

void Database::replaceUser(int userId, unique_ptr<User> newUser) {
    for (auto it = users.begin(); it != users.end(); ++it) {
        if ((*it)->getUserId() == userId) {
            users.erase(it);
            users.insert(std::move(newUser));
            cout << "Usuario reemplazado correctamente." << endl;
            return;
        }
    }
    cout << "Usuario no encontrado para reemplazar." << endl;
}

// Añadir sensor al vector de sensores
void Database::addSensor(unique_ptr<Sensor> sensor) {
    // Añadir el sensor al vector de sensores
    sensors.push_back(std::move(sensor));
    cout << "Sensor agregado correctamente." << endl;
}

// Método para obtener los sensores
const vector<shared_ptr<Sensor>>& Database::getSensors() const {
    return sensors; // Devolver el vector de sensores
}

// Comparador de usuarios para el set, ordena por userId
bool UserComparator::operator()(const unique_ptr<User>& a, const unique_ptr<User>& b) const {
    return a->getUserId() < b->getUserId();
}

// Método para guardar la base de datos en un fichero
void Database::saveUsersToFile(const string& filename) const {
    ofstream outFile(filename, ios::binary | ios::trunc);
    if (!outFile) {
        cerr << "Error al abrir el fichero para escribir.\n";
        return;
    }

    for (const auto& user : users) {
        char userType;
        if (dynamic_cast<const Admin*>(user.get())) userType = 'A';
        else if (dynamic_cast<const SuperAdmin*>(user.get())) userType = 'S';
        else userType = 'U';

        outFile.write(&userType, sizeof(userType));
        user->save(outFile);
    }

    outFile.close();
}

void Database::loadUsersFromFile(const std::string& filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cout << "No se encontró el fichero " << filename << ". Se creará uno nuevo al guardar.\n";
        return;
    }

    users.clear();

    while (inFile.peek() != EOF) {
        char userType;
        inFile.read(&userType, sizeof(userType));

        unique_ptr<User> user;
        if (userType == 'A') {
            user = make_unique<Admin>(0, "", *this); // Datos se sobrescribirán luego
        } else if (userType == 'S') {
            user = make_unique<SuperAdmin>(0, "", *this);
        } else {
            user = make_unique<User>(0, "", *this);
        }

        user->load(inFile); // << AQUÍ se lee id y nif
        users.insert(std::move(user));
    }

    inFile.close();
}