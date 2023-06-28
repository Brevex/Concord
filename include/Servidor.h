#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <vector>

#include "Canal.h"

class Servidor
{
    private:

        int UsuarioDonoId;
        std::string nome;
        std::string descricao;
        std::string codigoConvite;
        std::vector<Canal*> canais;
        std::vector<int> participantesIds;
    
    public:

        // Construtor
        Servidor(int UsuarioDonoId_m, std::string nome_m);

        // Getters 
        int getUsuarioDonoId();
        std::string getNome();
        std::string getDescricao();
        std::string getCodigoConvite();
        std::vector<Canal*> getCanais();
        std::vector<int> getParticipantesIds();

        // Setters
        void setUsuarioDonoId(int UsuarioDonoId_m);
        void setNome(std::string nome_m);
        void setDescricao(std::string descricao_m);
        void setCodigoConvite(std::string codigoConvite_m);
        void setCanais(std::vector<Canal*> canais_m);
        void setParticipantesIds(std::vector<int> participantesIds_m);

        // Métodos
        void adicionarParticipante(int id);
};

#endif
