// Fichero de manejo de excepciones de Users
#ifndef USER_EXCEPTIONS_H
#define USER_EXCEPTIONS_H

// Directivas de preprocesador
#include <exception>
#include <string>
#include <iostream>
// Namespace
using namespace std;
// Excepción base para errores de usuario

class UsuarioProtegidoException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "No se puede eliminar un usuario de tipo Admin o SuperAdmin.";
        }
    };

class UsuarioYaExistenteException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Ya existe un usuario con el mismo ID o NIF.";
        }
};
        
class CredencialesInvalidasException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Credenciales incorrectas. Intente de nuevo.";
        }
    };
        
class AccesoDenegadoException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Acceso denegado: no tiene permisos para realizar esta acción.";
        }
    };

class nifInvalidoException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "El NIF proporcionado no es válido.";
        }
    };

#endif // USER_EXCEPTIONS_H