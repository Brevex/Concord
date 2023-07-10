#ifndef USUARIO_H
#define USUARIO_H

#include <string>

#include "Servidor.h"

class Usuario
{
    private:

        int id;
        std::string email;
        std::string senha;
        std::string nome;
        std::string servidorAtual;
        std::string canalAtual;

    public:

        // Construtor
        Usuario(int id_m, std::string email_m, std::string senha_m, std::string nome_m);
        Usuario();

        // Getters 
        int getId();
        std::string getNome();
        std::string getEmail();
        std::string getSenha();
        std::string getServidorAtual();
        std::string getCanalAtual();

        // Setters
        void setId(int id_m);
        void setNome(std::string nome_m);
        void setEmail(std::string email_m);
        void setSenha(std::string senha_m);
        void setServidorAtual(std::string servidorAtual_m);
        void setCanalAtual(std::string canalAtual_m);
};

#endif
