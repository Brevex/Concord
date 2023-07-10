#ifndef SISTEMA_H
#define SISTEMA_H

#include <map>
#include <functional>
#include <iostream>
#include <iterator>
#include <sstream>
#include <chrono>
#include <iomanip>

#include "Usuario.h"
#include "Servidor.h"

class Sistema
{
    private:

        std::vector<Usuario> usuarios;
        std::vector<Servidor> servidores;
        std::map<std::string, std::function<void()>> comandos;
        Usuario usuarioLogado;

    public:

        // Construtor
        Sistema();

        // Getters 
        std::vector<Usuario> getUsuarios();
        std::vector<Servidor> getServidores();

        // Setters
        void setUsuarios(std::vector<Usuario> usuarios_m);
        void setServidores(std::vector<Servidor> servidores_m);

        // Gerenciador de comandos
        void executar(std::string linhaComando);

        // (A1) Comandos - Quando não estiver logado (Assim que entrar no sistema)
        void quit(); 
        void criarUsuario(std::vector<std::string> parametros);
        void login(std::vector<std::string> parametros);
        void listarUsuarios();

        // (A2) Comandos - Interações básicas com Servidores (Se estiver logado)
        void desconectarUsuario();
        void criarServidor(std::vector<std::string> parametros);
        void mudarDescricaoServidor(std::vector<std::string> parametros);
        void mudarCodigoConviteServidor(std::vector<std::string> parametros);
        void listarServidores();
        void removerServidor(std::vector<std::string> parametros);
        void entrarServidor(std::vector<std::string> parametros);
        void desconectarDoServidor();
        void listarParticipantes();

        // (B1) Comandos - Gestão de canais (Se tiver entrado no servidor)
        void listarCanais();
        void criarCanal(std::vector<std::string> parametros);
        void entrarCanal(std::vector<std::string> parametros);
        void sairCanal();

        // (B2) Comandos - Gestão de mensagens (se tiver entrado no servidor e em algum canal)
        void enviarMensagem(std::vector<std::string> parametros);
};

#endif
