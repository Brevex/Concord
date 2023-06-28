#include "../include/Mensagem.h"

// Construtor padrão da classe Mensagem
Mensagem::Mensagem() {}

// Construtor da classe Mensagem, cria objeto usando lista de inicialização
Mensagem::Mensagem(int enviadaPor_m, std::string dataHora_m, std::string conteudo_m) : enviadaPor(enviadaPor_m), dataHora(dataHora_m), conteudo(conteudo_m) {}

// Getters - enviadaPor
int Mensagem::getEnviadaPor()
{
    return enviadaPor;
}

// Getters - dataHora
std::string Mensagem::getDataHora()
{
    return dataHora;
}

// Getters - conteudo
std::string Mensagem::getConteudo()
{
    return conteudo;
}

// Setters - enviadaPor
void Mensagem::setEnviadaPor(int enviadaPor_m)
{
    enviadaPor = enviadaPor_m;
}

// Setters - dataHora
void Mensagem::setDataHora(std::string dataHora_m)
{
    dataHora = dataHora_m;
}

// Setters - conteudo
void Mensagem::setConteudo(std::string conteudo_m)
{
    conteudo = conteudo_m;
}
