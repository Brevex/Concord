#include "../include/Usuario.h"

// Construtor da classe Usuario, cria objeto usando lista de inicialização
Usuario::Usuario(int id_m, std::string email_m, std::string senha_m, std::string nome_m) : id(id_m),  email(email_m), senha(senha_m), nome(nome_m) {}
Usuario::Usuario() {};

// Getters - id
int Usuario::getId()
{
    return id;
}

// Getters - nome
std::string Usuario::getNome()
{
    return nome;
}

// Getters - email
std::string Usuario::getEmail()
{
    return email;
}

// Getters - senha
std::string Usuario::getSenha()
{
    return senha;
}

// Getters - servidorAtual
std::string Usuario::getServidorAtual()
{
    return servidorAtual;
}

// Getters - canalAtual
std::string Usuario::getCanalAtual()
{
    return canalAtual;
}

// Setters - id
void Usuario::setId(int id_m)
{
    id = id_m;
}

// Setters - nome
void Usuario::setNome(std::string nome_m)
{
    nome = nome_m;
}

// Setters - email
void Usuario::setEmail(std::string email_m)
{
    email = email_m;
}

// Setters - senha
void Usuario::setSenha(std::string senha_m)
{
    senha = senha_m;
}

// Setters - servidorAtual
void Usuario::setServidorAtual(std::string servidorAtual_m)
{
    servidorAtual = servidorAtual_m;
}

// Setters - canalAtual
void Usuario::setCanalAtual(std::string canalAtual_m)
{
    canalAtual = canalAtual_m;
}
