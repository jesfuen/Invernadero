// Fichero cabecera de la clase Database, donde se almacenan a los usuarios.

#ifndef DATABASE_H
#define DATABASE_H

// Directivas de preprocesador
#include <iostream>
#include <string>
#include <set>
#include <memory>
#include <vector>
#include <fstream>



class User; // Declaracion adelantada de la clase User
class Admin; // Declaracion adelantada de la clase Admin
class SuperAdmin; // Declaracion adelantada de la clase SuperAdmin
class Sensor; // Declaracion adelantada de la clase Sensor

// Namespace
using namespace std;

struct UserComparator {
    bool operator()(const unique_ptr<User>& a, const unique_ptr<User>& b) const;
};

// Definicion de la clase Database
class Database {
    public:
        // Constructor de la clase database
        Database();

        // Destructor de la clase database
        ~Database();

        // Metodos para la gestion de usuarios
        // Agregar a usuario al set
        void addUser(unique_ptr<User> user);

        // Eliminar al usuario del set
        void removeUser();

        // Buscar usuario por id y nif
        User* findUser(int& userId, const string& nif) const;

        // Mostrar listado de usuarios
        void showUsers() const;

        void replaceUser(int userId, unique_ptr<User> newUser);

        const set<unique_ptr<User>, UserComparator>& getUsers() const {
            return users; // Devolver el set de usuarios
        }
        // Añadir sensor al vector de sensores
        void addSensor(unique_ptr<Sensor> sensor);

        // Metodo para obtener los sensores
        const vector<shared_ptr<Sensor>>& getSensors() const;

        // Metodo para guardar la base de datos en un fichero
        void saveUsersToFile(const string& filename) const;
        // Metodo para cargar la base de datos desde un fichero
        void loadUsersFromFile(const string& filename);

    private:
        // Set de usuarios
        set<unique_ptr<User>,UserComparator> users; // se evitan objetos duplicado, no necesita comprobacion (Pero si hay que comprobar nif iguales y ids repetidos)
        // Vector de sensores
        vector<shared_ptr<Sensor>> sensors; // Vector de sensores, se pueden añadir sensores de distintos tipos

};


#endif // DATABASE_H