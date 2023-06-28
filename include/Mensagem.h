#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>

class Mensagem
{
    private:

        int enviadaPor;
        std::string dataHora;
        std::string conteudo;

    public:

        // Construtor
        Mensagem();
        Mensagem(int enviadaPor_m, std::string dataHora_m, std::string conteudo_m);

        // Getters 
        int getEnviadaPor();
        std::string getDataHora();
        std::string getConteudo();

        // Setters
        void setEnviadaPor(int enviadaPor_m);
        void setDataHora(std::string dataHora_m);
        void setConteudo(std::string conteudo_m);
};

#endif
