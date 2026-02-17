// Clase derivada SuperAdmin. Tiene acceso a todos los datos de usuarios, sensores y camaras. Puede modificar los roles de Admin y User.

#ifndef SUPER_ADMIN_H
#define SUPER_ADMIN_H

// Directivas de preprocesador
#include <iostream>
#include <string>
#include "User.h"
#include "Admin.h"
#include "Guest.h"
#include "../Database.h"



// Namespace
using namespace std;

// Definicion de la clase SuperAdmin, hereda de User
class SuperAdmin : public User {

    public:
        // Constructor de la clase SuperAdmin
        SuperAdmin(int userId, const string& nif, Database& db);

        // Destructor de la clase SuperAdmin
        ~SuperAdmin();

        

        // Dashboard para super administrador, tiene acceso a todos los datos de usuarios, sensores y camaras
        void showDashboard() override;

        // Promote de user a admin
        void promoteUserToAdmin(User& user);
        // Demote de admin a user
        void demoteAdminToUser(User& user);

        void roleChangeDashboard();

        void showProfile(std::ostream& os) const override {
            os << "Super Admin ID: " << getUserId() << endl;
            os << "NIF: " << getNif() << endl;
            os << "Role: Super Admin" << endl;
        }
};

#endif // SUPER_ADMIN_H