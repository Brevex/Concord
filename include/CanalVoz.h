#ifndef CANALVOZ_H
#define CANALVOZ_H

#include "Mensagem.h"
#include "Canal.h"

class CanalVoz : public Canal
{
    private:
        
        Mensagem ultimaMensagem;
    
    public:

        // Construtor
        CanalVoz(std::string nome_m);

        // Getters 
        Mensagem getUltimaMensagem();

        // Setters
        void setUltimaMensagem(Mensagem ultimaMensagem_m);
};

#endif
