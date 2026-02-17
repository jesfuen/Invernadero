// Clase derivada Guest. Esta clase no usa ni id ni nif, ya que es un invitado y no tiene acceso a los datos de usuario.

#ifndef GUEST_H
#define GUEST_H

// Directivas de preprocesador
#include <iostream>
#include <string>
#include "User.h"
#include "../Database.h"

// Namespace
using namespace std;

// Definicion de la clase Guest, hereda de User
class Guest: public User {
    public:
        // Constructor de la clase Guest
        Guest(Database& db);

        // Destructor de la clase Guest
        ~Guest();

        // Dashboard para invitado, solo tiene acceso a sensores pero no a camaras
        void showDashboard() override;

};
        

#endif // GUEST_H