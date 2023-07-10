#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "Mensagem.h"

class Canal
{
    private:

        std::string nome;
        int tipo;
        std::vector<Mensagem> mensagens;

    public:

        // Construtor
        Canal(std::string nome_m);

        // Getters 
        std::string getNome();
        int getTipo();

        // Setters
        void setNome(std::string nome_m);

        // Métodos
        void adicionarMensagem(Mensagem mensagem_m);
};
