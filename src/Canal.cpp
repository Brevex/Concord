#include "../include/Canal.h"

// Construtor da classe Canal, cria objeto usando lista de inicialização
Canal::Canal(std::string nome_m) : nome(nome_m) {}

// Getters - nome
std::string Canal::getNome()
{
    return nome;
}

// Setters - nome
void Canal::setNome(std::string nome_m)
{
    nome = nome_m;
}
