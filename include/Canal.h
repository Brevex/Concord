#pragma once

#include <string>

class Canal
{
    private:

        std::string nome;

    public:

        // Construtor
        Canal(std::string nome_m);

        // Getters 
        std::string getNome();

        // Setters
        void setNome(std::string nome_m);
};
