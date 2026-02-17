// User.h
#ifndef USER_H
#define USER_H

// Directivas de preprocesador
#include <iostream>
#include <string>
#include "../Database.h"
#include "../sensors/SensorTemperatura.h"
#include "../sensors/SensorAire.h"
#include "../sensors/SensorRadiacion.h"
#include "../sensors/SensorHumedad.h"
#include "../sensors/CamaraTermica.h"
#include "../exceptions/SensorExceptions.h"
#include "../exceptions/UserExceptions.h"

class Guest; // Declaracion adelantada de la clase Guest

// Namespace
using namespace std;

// Definicion de la clase User
class User {// Obtener rango de permisos

    // Sobrecarga del operador << para imprimir el objeto User
    friend std::ostream& operator<<(std::ostream& os, const User& user);

    public:
        // Constructor por defecto para la clase User, util para almacenar en fichero
        User();
        // Constructor de la clase User, unicamente tiene userId, nif y esAdmin(false por defecto)
        User(int userId, const std::string& nif, Database& db)
            : userId(userId), nif(nif), db(db) {}
        
        // Destructor de la clase User
        ~User() {}

        // Getters
        // Obtener userId
        int getUserId() const;

        // Obtener nif
        std::string getNif() const;

        // Setters
        // Establecer userId
        void setUserId(int userId); // HECHO

        // Establecer nif
        void setNif(const std::string& nif); // HECHO

        virtual void showDashboard(); // Método virtual para mostrar el dashboard

        // Metodo virtual para mostrar el perfil del usuario
        virtual void showProfile(std::ostream& os) const {
            os << "User ID: " << getUserId() << endl;
            os << "NIF: " << getNif() << endl;
            os << "Role: User" << endl;
        }

        virtual void sensorsDashboard();

        virtual void save(std::ostream& out) const;
        virtual void load(std::istream& in);
        
    
    private:
        int userId;
        std::string nif;
    protected:
        Database& db; // Base de datos para gestionar usuarios y sensores
};

#endif // USER_H