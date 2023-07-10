#include "../include/CanalTexto.h"

// Construtor da classe CanalTexto, cria objeto usando lista de inicialização
CanalTexto::CanalTexto(std::string nome_m) : Canal(nome_m), tipo(1) {}

// Getters - mensagens
std::vector<Mensagem> CanalTexto::getMensagens()
{
    return mensagens;
}

// Setters - mensagens
void CanalTexto::setMensagens(std::vector<Mensagem> mensagens_m)
{
    mensagens = mensagens_m;
}
