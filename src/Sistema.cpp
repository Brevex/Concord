#include "../include/Sistema.h"

// Construtor da classe Sistema, cria objeto usando lista de inicialização
Sistema::Sistema() {}

// Executa o comando digitado pelo usuário conferindo se a primeira palavra é um comando válido
void Sistema::executar(std::string linhaComando)
{
    // Separa a linha de comando em palavras
    std::istringstream iss(linhaComando);
    std::vector<std::string> parametros(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());

    // Mapa de comandos que chama a função correspondente ao comando digitado
    std::unordered_map<std::string, std::function<void(std::vector<std::string>)>> comandos = {

        {"quit", [this](std::vector<std::string> params) { quit(); }},
        {"create-user", [this](std::vector<std::string> params) { criarUsuario(params); }},
        {"listar-usuarios", [this](std::vector<std::string> params) { listarUsuarios(); }},
        {"login", [this](std::vector<std::string> params) { login(params); }},
        {"disconnect", [this](std::vector<std::string> params) { desconectarUsuario(); }},
        {"create-server", [this](std::vector<std::string> params) { criarServidor(params); }},
        {"set-server-desc", [this](std::vector<std::string> params) { mudarDescricaoServidor(params); }},
        {"set-server-invite-code", [this](std::vector<std::string> params) { mudarCodigoConviteServidor(params); }},
        {"list-servers", [this](std::vector<std::string> params) { listarServidores(); }},
        {"remove-server", [this](std::vector<std::string> params) { removerServidor(params); }},
        {"enter-server", [this](std::vector<std::string> params) { entrarServidor(params); }},
        {"leave-server", [this](std::vector<std::string> params) { desconectarDoServidor(); }},
        {"list-participants", [this](std::vector<std::string> params) { listarParticipantes(); }},
        {"list-channels", [this](std::vector<std::string> params) { listarCanais(); }},
        {"create-channel", [this](std::vector<std::string> params) { criarCanal(params); }},
        {"enter-channel", [this](std::vector<std::string> params) { entrarCanal(params); }},
        {"leave-channel", [this](std::vector<std::string> params) { sairCanal(); }},
        {"send-message", [this](std::vector<std::string> params) { enviarMensagem(params); }}
    };

    // Verifica se o comando digitado é válido
    if (comandos.count(parametros[0]) > 0)
    {
        comandos[parametros[0]](std::vector<std::string>(parametros.begin() + 1, parametros.end()));
    }
}

// Comando para sair do sistema
void Sistema::quit()
{
    std::cout << std::endl;
    std::cout << " Saindo do Concord..." << std::endl;

    // Encerra o programa
    exit(0);
}

// Comando para criar um usuário
void Sistema::criarUsuario(std::vector<std::string> parametros)
{
    // Verifica se o número de parametros do comando foi digitado corretamente
    if (parametros.size() != 3)
    {
        std::cout << std::endl;
        std::cout << " Comando invalido" << std::endl;

        return;
    }

    // Distribui os parametros do comando em variáveis
    std::string email = parametros[0];
    std::string senha = parametros[1];
    std::string nome = parametros[2];

    // Percorre o vetor de usuários cadastrados
    for (Usuario& usuario : usuarios)
    {
        // Verifica se o email digitado já está sendo usado por algum usuário
        if (usuario.getEmail() == email)
        {
            std::cout << std::endl;
            std::cout << " Usuario " << usuario.getEmail() << " ja existe!" << std::endl;

            return;
        }
    }

    // Gera um id para o novo usuário
    int id = usuarios.size() + 1;

    // Cria um novo usuário e o adiciona ao vetor de usuários
    Usuario novoUsuario(id, email, senha, nome);
    usuarios.push_back(novoUsuario);

    // Exibe mensagem de sucesso
    std::cout << std::endl;
    std::cout << " Usuario " << novoUsuario.getEmail() << " criado com sucesso" << std::endl;
}

// Comando para fazer login com um usuário existente
void Sistema::login(std::vector<std::string> parametros)
{
    // Verifica se o número de parametros do comando foi digitado corretamente
    if (parametros.size() != 2)
    {
        std::cout << std::endl;
        std::cout << " Comando invalido" << std::endl;

        return;
    }

    // Distribui os parametros do comando em variáveis
    std::string email = parametros[0];
    std::string senha = parametros[1];

    // Percorre o vetor de usuários cadastrados
    for (Usuario& usuario : usuarios)
    {
        // Verifica se o email e a senha digitados são iguais aos de algum usuário já cadastrado
        if (usuario.getEmail() == email && usuario.getSenha() == senha)
        {
            usuarioLogado = usuario;

            std::cout << std::endl;
            std::cout << " Logado como " << usuario.getEmail() << std::endl;

            return;
        }
    }

    // Exibe mensagem de erro caso o email ou a senha estejam incorretos / não existam
    std::cout << std::endl;
    std::cout << " Email ou senha incorretos" << std::endl;
}

// Comando para listar os usuários
void Sistema::listarUsuarios()
{
    std::cout << std::endl;
    std::cout << " Lista de usuarios cadastrados:" << std::endl;
    std::cout << std::endl;

    // Verifica se existem usuários cadastrados
    if (usuarios.size() == 0)
    {
        std::cout << " Nenhum usuario cadastrado" << std::endl;

        return;
    }

    // Imprime os usuários cadastrados e seus dados
    for (Usuario& usuario : usuarios)
    {
        std::cout << " Nome: " << usuario.getNome() << std::endl;
        std::cout << " Email: " << usuario.getEmail() << std::endl;
        std::cout << " Senha: " << usuario.getSenha() << std::endl;
        std::cout << " ID: " << usuario.getId() << std::endl;
        std::cout << std::endl;
    }
}

// Comando para desconectar o usuário logado
void Sistema::desconectarUsuario()
{
    // Verifica se existe algum usuário logado
    if (usuarioLogado.getEmail() == "")
    {
        std::cout << std::endl;
        std::cout << " Nenhum usuario conectado" << std::endl;

        return;
    }

    std::cout << std::endl;
    std::cout << " Desconectando usuario " << usuarioLogado.getEmail() << std::endl;

    // Desconecta o usuário logado
    usuarioLogado = Usuario();
}

// Comando para criar um servidor
void Sistema::criarServidor(std::vector<std::string> parametros)
{
    // Verifica se o número de parametros do comando foi digitado corretamente
    if (parametros.size() != 1)
    {
        std::cout << std::endl;
        std::cout << " Comando invalido" << std::endl;

        return;
    }

    // Verifica se existe algum usuário logado
    if (usuarioLogado.getEmail() == "")
    {
        std::cout << std::endl;
        std::cout << " Nenhum usuario logado" << std::endl;

        return;
    }

    std::string nomeServidor = parametros[0];

    // Percorre o vetor de servidores cadastrados
    for (Servidor& servidor : servidores)
    {
        // Verifica se o nome do servidor já está sendo usado
        if (servidor.getNome() == nomeServidor)
        {
            std::cout << std::endl;
            std::cout << " Servidor '" << servidor.getNome() << "' ja existe!" << std::endl;

            return;
        }
    }

    // Cria um novo servidor e o adiciona ao vetor de servidores
    Servidor novoServidor(usuarioLogado.getId(), nomeServidor);
    servidores.push_back(novoServidor);

    std::cout << std::endl;
    std::cout << " Servidor '" << novoServidor.getNome() << "' criado com sucesso" << std::endl;
}

// Comando para mudar descrição do servidor
void Sistema::mudarDescricaoServidor(std::vector<std::string> parametros)
{
    // Verifica se o número de parametros do comando foi digitado corretamente
    if (parametros.size() < 2)
    {
        std::cout << std::endl;
        std::cout << " Comando invalido" << std::endl;

        return;
    }

    // Verifica se existe algum usuário logado
    if (usuarioLogado.getEmail() == "")
    {
        std::cout << std::endl;
        std::cout << " Nenhum usuario logado" << std::endl;

        return;
    }

    // Distribui os parametros do comando em variáveis
    std::string nomeServidor = parametros[0];
    std::string novaDescricao = parametros[1];

    // Percorre o vetor de servidores cadastrados
    for (Servidor& servidor : servidores)
    {
        // Verifica se o servidor existe
        if (servidor.getNome() == nomeServidor)
        {
            // Verifica se o usuário logado é o dono do servidor
            if (servidor.getUsuarioDonoId() != usuarioLogado.getId())
            {
                std::cout << std::endl;
                std::cout << " Voce nao e o dono deste servidor" << std::endl;

                return;
            }

            // Altera a descrição do servidor
            servidor.setDescricao(novaDescricao);

            std::cout << std::endl;
            std::cout << " Descricao do servidor '" << nomeServidor << "' modificada!" << std::endl;

            return;
        }
    }

    std::cout << std::endl;
    std::cout << " Servidor nao encontrado" << std::endl;
}

// Comando para mudar código de convite do servidor
void Sistema::mudarCodigoConviteServidor(std::vector<std::string> parametros)
{
    // Verifica se o número de parametros do comando foi digitado corretamente
    if (parametros.size() < 1 || parametros.size() > 2)
    {
        std::cout << std::endl;
        std::cout << " Comando invalido" << std::endl;

        return;
    }

    // Verifica se existe algum usuário logado
    if (usuarioLogado.getEmail() == "")
    {
        std::cout << std::endl;
        std::cout << " Nenhum usuario logado" << std::endl;

        return;
    }

    // Distribui os parametros do comando em variáveis
    std::string nomeServidor = parametros[0];
    std::string novoCodigoConvite = "";

    // Verifica se o código de convite foi passado como parametro
    if (parametros.size() == 2)
    {
        novoCodigoConvite = parametros[1];
    }

    // Percorre o vetor de servidores cadastrados
    for (Servidor& servidor : servidores)
    {
        // Verifica se o servidor existe
        if (servidor.getNome() == nomeServidor)
        {
            // Verifica se o usuário logado é o dono do servidor
            if (servidor.getUsuarioDonoId() != usuarioLogado.getId())
            {
                std::cout << std::endl;
                std::cout << " Voce nao e o dono deste servidor" << std::endl;

                return;
            }

            // Altera o código de convite do servidor
            servidor.setCodigoConvite(novoCodigoConvite);

            // Verifica se o código de convite foi removido ou modificado
            if (novoCodigoConvite == "")
            {
                std::cout << std::endl;
                std::cout << " Codigo de convite do servidor '" << nomeServidor << "' removido!" << std::endl;
            }
            else
            {
                std::cout << std::endl;
                std::cout << " Codigo de convite do servidor '" << nomeServidor << "' modificado!" << std::endl;
            }

            return;
        }
    }

    std::cout << std::endl;
    std::cout << " Servidor nao encontrado" << std::endl;
}

// Comando para listar servidores
void Sistema::listarServidores()
{
    std::cout << std::endl;
    std::cout << " Servidores:" << std::endl;
    std::cout << std::endl;

    // Verifica se existe algum servidor cadastrado
    if (servidores.size() == 0)
    {
        std::cout << " Nenhum servidor cadastrado" << std::endl;

        return;
    }

    // Percorre o vetor de servidores cadastrados
    for (Servidor& servidor : servidores)
    {
        std::cout << " - " << servidor.getNome() << std::endl;
    }
}

// Comando para remover servidor
void Sistema::removerServidor(std::vector<std::string> parametros)
{
    // Verifica se o número de parametros do comando foi digitado corretamente
    if (parametros.size() < 1)
    {
        std::cout << std::endl;
        std::cout << " Comando invalido" << std::endl;

        return;
    }

    // Verifica se existe algum usuário logado
    if (usuarioLogado.getEmail() == "")
    {
        std::cout << std::endl;
        std::cout << " Nenhum usuario logado" << std::endl;

        return;
    }

    // Distribui os parametros do comando em variáveis
    std::string nomeServidor = parametros[0];

    // Percorre o vetor de servidores cadastrados
    for (auto it = servidores.begin(); it != servidores.end(); ++it)
    {
        // Verifica se o servidor existe
        if (it -> getNome() == nomeServidor)
        {
            // Verifica se o usuário logado é o dono do servidor
            if (it -> getUsuarioDonoId() != usuarioLogado.getId())
            {
                std::cout << std::endl;
                std::cout << " Voce nao e o dono deste servidor" << std::endl;

                return;
            }

            // Remove o servidor
            servidores.erase(it);

            std::cout << std::endl;
            std::cout << " Servidor '" << nomeServidor << "' removido" << std::endl;

            return;
        }
    }

    std::cout << std::endl;
    std::cout << " Servidor '" << nomeServidor << "' nao encontrado" << std::endl;
}

// Comando para entrar em um servidor
void Sistema::entrarServidor(std::vector<std::string> parametros)
{
    // Verifica se o número de parametros do comando foi digitado corretamente
    if (parametros.size() < 1 || parametros.size() > 2)
    {
        std::cout << std::endl;
        std::cout << " Comando invalido" << std::endl;

        return;
    }

    // Verifica se existe algum usuário logado
    if (usuarioLogado.getEmail() == "")
    {
        std::cout << std::endl;
        std::cout << " Nenhum usuario logado" << std::endl;

        return;
    }

    // Distribui os parametros do comando em variáveis
    std::string nomeServidor = parametros[0];
    
    Servidor* servidor = nullptr;

    // Percorre o vetor de servidores cadastrados
    for (auto& s : servidores)
    {
        if (s.getNome() == nomeServidor)
        {
            servidor = &s;
            break;
        }
    }

    // Verifica se o servidor existe
    if (servidor == nullptr)
    {
        std::cout << std::endl;
        std::cout << " Servidor '" << nomeServidor << "' nao encontrado" << std::endl;

        return;
    }

    // Se código de convite do servidor for vazio, qualquer usuário pode entrar
    if (servidor -> getCodigoConvite() == "")
    {
        servidor -> adicionarParticipante(usuarioLogado.getId());

        usuarioLogado.setServidorAtual(nomeServidor);

        std::cout << std::endl;
        std::cout << " Entrou no servidor '" << nomeServidor << "' com sucesso" << std::endl;

        return;
    }

    // Verifica se o usuário logado é o dono do servidor, se for, ele pode entrar sem código de convite
    if (servidor -> getUsuarioDonoId() == usuarioLogado.getId())
    {
        servidor -> adicionarParticipante(usuarioLogado.getId());

        usuarioLogado.setServidorAtual(nomeServidor);

        std::cout << std::endl;
        std::cout << " Entrou no servidor '" << nomeServidor << "' com sucesso" << std::endl;

        return;
    }

    // Verifica se o código de convite foi digitado corretamente e se o usuário pode entrar no servidor
    if (parametros.size() == 2 && parametros[1] == servidor -> getCodigoConvite())
    {
        servidor -> adicionarParticipante(usuarioLogado.getId());

        usuarioLogado.setServidorAtual(nomeServidor);

        std::cout << std::endl;
        std::cout << " Entrou no servidor '" << nomeServidor << "' com sucesso" << std::endl;

        return;
    }

    std::cout << std::endl;
    std::cout << " Servidor '" << nomeServidor << "' requer codigo de convite" << std::endl;
}

// Comando para sair de um servidor
void Sistema::desconectarDoServidor()
{
    // Verifica se existe algum usuário logado
    if (usuarioLogado.getEmail() == "")
    {
        std::cout << std::endl;
        std::cout << " Nenhum usuario logado" << std::endl;

        return;
    }

    // Verifica se o usuário está visualizando algum servidor
    if (usuarioLogado.getServidorAtual() == "")
    {
        std::cout << std::endl;
        std::cout << " Voce nao esta visualizando nenhum servidor" << std::endl;

        return;
    }

    // Disconnecta o usuário do servidor
    std::string nomeServidor = usuarioLogado.getServidorAtual();
    usuarioLogado.setServidorAtual("");

    std::cout << std::endl;
    std::cout << " Saindo do servidor '" << nomeServidor << "'" << std::endl;
}

// Comando para listar participantes do servidor
void Sistema::listarParticipantes()
{
    // Verifica se existe algum usuário logado
    if (usuarioLogado.getEmail() == "")
    {
        std::cout << std::endl;
        std::cout << " Nenhum usuario logado" << std::endl;

        return;
    }

    // Verifica se o usuário está visualizando algum servidor
    if (usuarioLogado.getServidorAtual() == "")
    {
        std::cout << std::endl;
        std::cout << " Voce nao esta visualizando nenhum servidor" << std::endl;

        return;
    }

    // Define o servidor atual do usuário logado
    std::string nomeServidor = usuarioLogado.getServidorAtual();
    Servidor* servidor = nullptr;

    // Percorre o vetor de servidores cadastrados
    for (auto& s : servidores)
    {
        if (s.getNome() == nomeServidor)
        {
            servidor = &s;
            break;
        }
    }

    // Verifica se o servidor existe
    if (servidor == nullptr)
    {
        std::cout << std::endl;
        std::cout << " Servidor '" << nomeServidor << "' nao encontrado" << std::endl;

        return;
    }

    std::cout << std::endl;
    std::cout << " Participantes do servidor '" << nomeServidor << "':" << std::endl;
    std::cout << std::endl;

    // Percorre o vetor de participantes do servidor e imprime seus nomes
    for (auto& id : servidor -> getParticipantesIds())
    {
        for (auto& u : usuarios)
        {
            if (u.getId() == id)
            {
                std::cout << " - " << u.getNome() << std::endl;
                break;
            }
        }
    }
}

// Comando para listar Canais do servidor atual
void Sistema::listarCanais()
{
    // Verifica se existe algum usuário logado
    if (usuarioLogado.getEmail() == "")
    {
        std::cout << std::endl;
        std::cout << " Nenhum usuario logado" << std::endl;

        return;
    }

    // Verifica se o usuário está visualizando algum servidor
    if (usuarioLogado.getServidorAtual() == "")
    {
        std::cout << std::endl;
        std::cout << " Voce nao esta visualizando nenhum servidor" << std::endl;

        return;
    }

    // Define o servidor atual do usuário logado
    std::string nomeServidor = usuarioLogado.getServidorAtual();
    Servidor* servidor = nullptr;

    // Percorre o vetor de servidores cadastrados
    for (auto& s : servidores)
    {
        if (s.getNome() == nomeServidor)
        {
            servidor = &s;
            break;
        }
    }

    // Verifica se o servidor existe
    if (servidor == nullptr)
    {
        std::cout << std::endl;
        std::cout << " Servidor '" << nomeServidor << "' nao encontrado" << std::endl;

        return;
    }

    std::cout << " #Canais de texto:" << std::endl;
    std::cout << std::endl;

    // Percorre o vetor de canais de texto do servidor e imprime seus nomes
    for (auto& c : servidor -> getCanaisTexto())
    {
        std::cout << " - " << c -> getNome() << std::endl;
    }

    std::cout << std::endl;
    std::cout << " #Canais de voz:" << std::endl;
    std::cout << std::endl;

    // Percorre o vetor de canais de voz do servidor e imprime seus nomes
    for (auto& c : servidor -> getCanaisVoz())
    {
        std::cout << " - " << c -> getNome() << std::endl;
    }

    std::cout << std::endl;
}

// Comando para criar um canal no servidor
void Sistema::criarCanal(std::vector<std::string> parametros)
{
    // Verifica se o número de parametros do comando foi digitado corretamente
    if (parametros.size() != 2)
    {
        std::cout << std::endl;
        std::cout << " Comando invalido" << std::endl;

        return;
    }

    // Distribui os parametros do comando em variáveis
    std::string nomeCanal = parametros[0];
    std::string tipoCanal = parametros[1];

    // Verifica se existe algum usuário logado
    if (usuarioLogado.getEmail() == "")
    {
        std::cout << std::endl;
        std::cout << " Nenhum usuario logado" << std::endl;

        return;
    }

    // Verifica se o usuário está visualizando algum servidor
    if (usuarioLogado.getServidorAtual() == "")
    {
        std::cout << std::endl;
        std::cout << " Voce nao esta visualizando nenhum servidor" << std::endl;

        return;
    }

    // Verifica se o nome do canal é válido
    if (nomeCanal == "")
    {
        std::cout << std::endl;
        std::cout << " Nome do canal nao pode ser vazio" << std::endl;

        return;
    }

    // Verifica se o tipo do canal é válido
    if (tipoCanal != "texto" && tipoCanal != "voz")
    {
        std::cout << std::endl;
        std::cout << " Tipo de canal invalido" << std::endl;

        return;
    }

    // Define o servidor atual do usuário logado
    std::string nomeServidor = usuarioLogado.getServidorAtual();

    // Percorre o vetor de servidores cadastrados
    for (auto& s : servidores)
    {
        if (s.getNome() == nomeServidor)
        {
            // Verifica se o canal já existe
            if (s.getCanal(nomeCanal) != nullptr)
            {
                std::cout << std::endl;
                std::cout << " Canal '" << nomeCanal << "' ja existe" << std::endl;

                return;
            }

            // Cria o canal de texto
            if (tipoCanal == "texto")
            {
                CanalTexto* canal = new CanalTexto(nomeCanal);
                s.adicionarCanalTexto(canal);

                std::cout << std::endl;
                std::cout << " Canal de texto '" << nomeCanal << "' criado com sucesso" << std::endl;

                return;
            }

            // Cria o canal de voz
            if (tipoCanal == "voz")
            {
                CanalVoz* canal = new CanalVoz(nomeCanal);
                s.adicionarCanalVoz(canal);

                std::cout << std::endl;
                std::cout << " Canal de voz '" << nomeCanal << "' criado com sucesso" << std::endl;

                return;
            }
        }
    }
}

// Comando para entrar em um canal do servidor
void Sistema::entrarCanal(std::vector<std::string> parametros)
{
    // Verifica se o número de parametros do comando foi digitado corretamente
    if (parametros.size() != 1)
    {
        std::cout << std::endl;
        std::cout << " Comando invalido" << std::endl;

        return;
    }

    // Verifica se existe algum usuário logado
    if (usuarioLogado.getEmail() == "")
    {
        std::cout << std::endl;
        std::cout << " Nenhum usuario logado" << std::endl;

        return;
    }

    // Verifica se o usuário está visualizando algum servidor
    if (usuarioLogado.getServidorAtual() == "")
    {
        std::cout << std::endl;
        std::cout << " Voce nao esta visualizando nenhum servidor" << std::endl;

        return;
    }

    // Distribui o parametro do comando em uma variável
    std::string nomeCanal = parametros[0];

    // Define o servidor atual do usuário logado
    std::string nomeServidor = usuarioLogado.getServidorAtual();

    // Percorre o vetor de servidores cadastrados
    for (auto& s : servidores)
    {
        if (s.getNome() == nomeServidor)
        {
            // Verifica se o canal existe
            if (s.getCanal(nomeCanal) == nullptr)
            {
                std::cout << std::endl;
                std::cout << " Canal '" << nomeCanal << "' nao encontrado" << std::endl;

                return;
            }

            // Define o canal atual do usuário logado
            usuarioLogado.setCanalAtual(nomeCanal);

            std::cout << std::endl;
            std::cout << " Entrou no canal '" << nomeCanal << "'" << std::endl;

            return;
        }
    }
}

// Comando para sair de um canal do servidor
void Sistema::sairCanal()
{
    // Verifica se existe algum usuário logado
    if (usuarioLogado.getEmail() == "")
    {
        std::cout << std::endl;
        std::cout << " Nenhum usuario logado" << std::endl;

        return;
    }

    // Verifica se o usuário está visualizando algum servidor
    if (usuarioLogado.getServidorAtual() == "")
    {
        std::cout << std::endl;
        std::cout << " Voce nao esta visualizando nenhum servidor" << std::endl;

        return;
    }

    // Verifica se o usuário está em algum canal
    if (usuarioLogado.getCanalAtual() == "")
    {
        std::cout << std::endl;
        std::cout << " Voce nao esta em nenhum canal" << std::endl;

        return;
    }

    // Define o canal atual do usuário logado
    usuarioLogado.setCanalAtual("");

    std::cout << std::endl;
    std::cout << " Saindo do canal..." << std::endl;
}

// Comando para enviar uma mensagem no canal
void Sistema::enviarMensagem(std::vector<std::string> parametros)
{
    // Verifica se o número de parametros do comando foi digitado corretamente
    if (parametros.size() < 1)
    {
        std::cout << std::endl;
        std::cout << " Comando invalido" << std::endl;

        return;
    }

    // Distribui o parametro do comando em uma variável
    std::string mensagem = parametros[0];

    // Define o servidor atual do usuário logado
    std::string nomeServidor = usuarioLogado.getServidorAtual();

    // Verifica se existe algum usuário logado
    if (usuarioLogado.getEmail() == "")
    {
        std::cout << std::endl;
        std::cout << " Nenhum usuario logado" << std::endl;

        return;
    }

    // Verifica se o usuário está visualizando algum servidor
    if (usuarioLogado.getServidorAtual() == "")
    {
        std::cout << std::endl;
        std::cout << " Voce nao esta visualizando nenhum servidor" << std::endl;

        return;
    }

    // Verifica se o usuário está em algum canal
    if (usuarioLogado.getCanalAtual() == "")
    {
        std::cout << std::endl;
        std::cout << " Voce nao esta em nenhum canal" << std::endl;

        return;
    }

    // Obtém a data e hora atual
    auto agora = std::chrono::system_clock::now();
    std::time_t tempo = std::chrono::system_clock::to_time_t(agora);

    // Converte a data e hora para uma string
    std::stringstream ss;
    ss << std::put_time(std::localtime(&tempo), "%Y-%m-%d %H:%M:%S");
    std::string dataHora = ss.str();

    // Cria a mensagem com os dados obtidos
    Mensagem m(usuarioLogado.getId(), dataHora, mensagem);

    // Adiciona a mensagem na lista de mensagens do canal atual
    for (auto& s : servidores)
    {
        if (s.getNome() == nomeServidor)
        {
            Canal* c = s.getCanal(usuarioLogado.getCanalAtual());
            c -> adicionarMensagem(m);
        }
    }

    // Exibe mensagem de sucesso
    std::cout << std::endl;
    std::cout << " Mensagem enviada" << std::endl;
}

// Getters - usuarios
std::vector<Usuario> Sistema::getUsuarios()
{
    return usuarios;
}

// Getters - servidores
std::vector<Servidor> Sistema::getServidores()
{
    return servidores;
}

// Setters - usuarios
void Sistema::setUsuarios(std::vector<Usuario> usuarios_m)
{
    usuarios = usuarios_m;
}

// Setters - servidores
void Sistema::setServidores(std::vector<Servidor> servidores_m)
{
    servidores = servidores_m;
}
