#include "../include/Canal.h"

// Construtor da classe Canal, cria objeto usando lista de inicialização
Canal::Canal(std::string nome_m) : nome(nome_m) {}

// Getters - nome
std::string Canal::getNome()
{
    return nome;
}

// Getters - tipo
int Canal::getTipo()
{
    return tipo;
}

// Setters - nome
void Canal::setNome(std::string nome_m)
{
    nome = nome_m;
}

// Métodos - adicionarMensagem
void Canal::adicionarMensagem(Mensagem mensagem_m)
{
    mensagens.push_back(mensagem_m);
}
