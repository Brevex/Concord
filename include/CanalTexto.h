#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include "Canal.h"
#include "Mensagem.h"

class CanalTexto : public Canal
{
    private:

        std::vector<Mensagem> mensagens;
        int tipo;

    public:

        // Construtor
        CanalTexto(std::string nome_m);

        // Getters 
        std::vector<Mensagem> getMensagens();

        // Setters
        void setMensagens(std::vector<Mensagem> mensagens_m);
};

#endif
