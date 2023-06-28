#include "../include/CanalVoz.h"

// Construtor da classe CanalVoz, cria objeto usando lista de inicialização
CanalVoz::CanalVoz(std::string nome_m) : Canal(nome_m) {}

// Getters - Ultima Mensagem
Mensagem CanalVoz::getUltimaMensagem()
{
    return ultimaMensagem;
}

// Setters - Ultima Mensagem
void CanalVoz::setUltimaMensagem(Mensagem ultimaMensagem_m)
{
    ultimaMensagem = ultimaMensagem_m;
}
