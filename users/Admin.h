// Clase derivada Admin. Tiene acceso a los datos de usuarios y gestiona el set de usuarios.
#ifndef ADMIN_H
#define ADMIN_H

// Directivas de preprocesador
#include <iostream>
#include <string>
#include "User.h"
#include "../Database.h"
#include "../exceptions/UserExceptions.h" // Excepciones de usuario

// Namespace
using namespace std;

// Definicion de la clase Admin, hereda de User
class Admin : public User {
    public:
        // Constructor de la clase Admin
        Admin(int userId, const string& nif, Database& db);

        // Destructor de la clase Admin
        ~Admin();

        // Dashboard para administrador, tiene acceso a todos los datos de usuarios y sensores
        void showDashboard() override;

        void manageDashboard();

        void showProfile(std::ostream& os) const override {
            os << "Admin ID: " << this->getUserId() << endl;
            os << "NIF: " << this->getNif() << endl;
            os << "Role: Admin" << endl;
        }

        void nifValidation(const string& nif);

};



#endif // ADMIN_H