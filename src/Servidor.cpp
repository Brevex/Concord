#include "../include/Servidor.h"

// Construtor da classe Servidor, cria objeto usando lista de inicialização
Servidor::Servidor(int UsuarioDonoId_m, std::string nome_m) : UsuarioDonoId(UsuarioDonoId_m), nome(nome_m), descricao(), codigoConvite(), participantesIds(), canais() {}

// Getters - UsuarioDonoId
int Servidor::getUsuarioDonoId()
{
    return UsuarioDonoId;
}

// Getters - nome
std::string Servidor::getNome()
{
    return nome;
}

// Getters - descricao
std::string Servidor::getDescricao()
{
    return descricao;
}

// Getters - codigoConvite
std::string Servidor::getCodigoConvite()
{
    return codigoConvite;
}

// Getters - canaisTexto
std::vector<Canal*> Servidor::getCanais()
{
    return canais;
}

// Getters - participantesIds
std::vector<int> Servidor::getParticipantesIds()
{
    return participantesIds;
}

// Setters - UsuarioDonoId
void Servidor::setUsuarioDonoId(int UsuarioDonoId_m)
{
    UsuarioDonoId = UsuarioDonoId_m;
}

// Setters - nome
void Servidor::setNome(std::string nome_m)
{
    nome = nome_m;
}

// Setters - descricao
void Servidor::setDescricao(std::string descricao_m)
{
    descricao = descricao_m;
}

// Setters - codigoConvite
void Servidor::setCodigoConvite(std::string codigoConvite_m)
{
    codigoConvite = codigoConvite_m;
}

// Setters - canaisTexto
void Servidor::setCanais(std::vector<Canal*> canais_m)
{
    canais = canais_m;
}

// Setters - participantesIds
void Servidor::setParticipantesIds(std::vector<int> participantesIds_m)
{
    participantesIds = participantesIds_m;
}

// Métodos - adicionarParticipante
void Servidor::adicionarParticipante(int id)
{
    participantesIds.push_back(id);
}