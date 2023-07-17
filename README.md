<h1 align = "center"> Concord </h1>

<br>

<h2> &#128269; Sobre o Projeto </h2>

<br>

<p> Projeto realizado durante o Bacharelado em Tecnologia da Informação (BTI) 
para a matéria Linguagem de Programação I. Se trata de um programa feito em 
C++ que simula um chat via terminal. O programa funciona recebendo comandos
que executam uma determinada função, como criar usuários, enviar mensagens, criar
servidores, criar canais e etc.</p>

<br>

<h2> &#128296; Dependências e Execução </h2>

<br>

<p>Para compilar e rodar esse programa em sua máquina será necessário o CMake e
o compilador de código para C/C++, podendo ser o gcc ou g++. Para criar o executável
entre na pasta "build", clique com o botão direito do mouse e abra o terminal 
dentro dessa pasta. Com o terminal aberto digite "cmake.." e aperte enter, depois
digite "make" e aperte enter novamente. Por fim, digite "./concord" para executar
o programa.</p>

<br>

<h2> &#128302; Tecnologias usadas </h2>

<br>

<div style="display: inline_block" align="center">
  <img align="center" alt="C++" height="50" width="60" src="https://github.com/isocpp/logos/blob/master/cpp_logo.svg" />
  <img align="center" alt="CSS" height="50" width="60" src="https://github.com/vscode-icons/vscode-icons/blob/master/icons/file_type_cmake.svg" />        
</div>

<br>

<h2> &#128161; Funções do Programa </h2>

<br>

<p>Como mencionado antes, o programa funciona baseado em comandos de terminal
criados exclusivamente para o Concord. Segue abaixo os comandos e suas funções:</p>

<h3>A1 - Se não estiver logado (Assim que entra no sistema)</h3>

<details>
	<summary>create-user</summary>
	<br>
	Cria um novo usuário no sistema recebendo como parâmetro email, senha e nome. 
	Cada usuário é único, tentar criar um usuário com o mesmo email / senha de outro 
	resultará em erro, assim como a falta de algum desses parâmetros.<br><br>
	
	create-user julio.melo@imd.ufrn.br 12ab34cd Julio Melo
	Usuário criado
 
	create-user julio.melo@imd.ufrn.br 12ab34cd Julio Silva
	Usuário já existe!
</details>

<details>
	<summary>login</summary>
	<br>
	Esse procedimento verifica se já existe um usuário no cadastro geral com esse e-mail e
	senha digitados. Se existir, então o usuário efetuou o login com sucesso.<br><br>
	
	login julio.melo@imd.ufrn.br 12ab34cd
	Logado como julio.melo@imd.ufrn.br
 
	login julio.melo@imd.ufrn.br 1326
	Senha ou usuário inválidos!
</details>

<details>
	<summary>quit</summary>
	<br>
	Fecha a aplicação, este comando pode ser executado a qualquer momento pelo
	usuário.<br><br>
	
	quit
	Saindo do Concord
</details>

<h3>A2 - Interações básicas com Servidores (Se estiver logado)</h3>

<details>
	<summary>disconnect</summary>
	<br>
	Desconecta o usuário atual, ou seja, altera a variável que armazena o
	usuário atualmente logado. O sistema continua executando, mas é necessário que seja feito
	login novamente para que o restante dos comandos (com exceção de create-user) sejam
	executados corretamente novamente.<br><br>
	
	disconnect
	Desconectando usuário julio.melo@imd.ufrn.br
 
	disconnect
	Não está conectado
</details>

<details>
	<summary>create-server</summary>
	<br>
	Cria um novo servidor passando o nome dele.
	O comando create-server <nome-do-servidor> cria um novo servidor se ele não
	existir com esse nome.<br><br>
	
	create-server minha-casa
	Servidor criado
 
	create-server minha-casa
	Servidor com esse nome já existe
</details>

<details>
	<summary>set-server-desc</summary>
	<br>
	Muda a descrição de um servidor já criado. Deve ser verificado se o servidor que você está tentando mudar a descrição é seu.<br><br>
	
	set-server-desc minha-casa “Este servidor serve como minha casa, sempre estarei nele”
	Descrição do servidor ‘minha-casa’ modificada!
 
	set-server-desc minha-casa2 “Este servidor serve como minha casa, sempre estarei nele”
	Servidor ‘minha-casa2’ não existe

 	set-server-desc minha-casa55 “Trocando a descrição de servidor dos outros”
  	Você não pode alterar a descrição de um servidor que não foi criado por você
</details>

<details>
	<summary>set-server-invite-code</summary>
	<br>
	Muda o código de convite de um servidor. Se você utilizar o comando sem nenhum código, então o servidor muda seu código para "" e
	fica liberado para qualquer pessoa entrar. Por padrão os servers não tem código de convite. Deve ser verificado se o servidor que você está 	tentando mudar o código de convite é seu.<br><br>
	
	set-server-invite-code minha-casa 4567
	Código de convite do servidor 'minha-casa' modificado!
 
	set-server-invite-code minha-casa
	Código de convite do servidor 'minha-casa' removido!
</details>

<details>
	<summary>list-servers</summary>
	<br>
	Exibe os nomes dos servidores no sistema, um por linha.<br><br>
	
	list-servers
 
	minha-casa
	minha-casa2
	RPG-galera
	Bate-papo
</details>

<details>
	<summary>remove-server</summary>
	<br>
	Remove um servidor (informando o seu nome). Só pode ter sucesso na remoção se o dono do servidor for o usuário logado.<br><br>
	
	remove-server minha-casa
	Servidor ‘minha-casa’ removido
 
	remove-server minha-casa
	Você não é o dono do servidor ‘minha-casa’

 	remove-server minha-casa3
	Servidor ‘minha-casa3’ não encontrado
</details>

<details>
	<summary>enter-server</summary>
	<br>
	Entra em um servidor. Se o servidor for aberto (não tiver código de convite), o ID do usuário é inserido na lista de participantes do 		servidor automaticamente. Se o servidor não for aberto, só deve adicionar como participante do servidor se o mesmo digitar o código 		correto. Se o usuário logado criou o servidor ele pode entrar nele sem código de convite, mesmo que o mesmo não seja aberto.<br><br>
	
	enter-server dotalovers
	Entrou no servidor com sucesso
 
	enter-server concordo-members
	Servidor requer código de convite

 	enter-server concordo-members 123456
	Entrou no servidor com sucesso
</details>

<details>
	<summary>leave-server</summary>
	<br>
	Desconecta do servidor que o usuário está atualmente conectado. Repare que o usuário se mantém na lista de participantes. O registro de qual 	servidor o usuário está visualizando no momento (na classe Sistema) deve mudar para um valor que represente "nenhum".<br><br>
	
	leave-server
	Saindo do servidor ‘minha-casa’
 
	leave-server
	Você não está visualizando nenhum servidor
</details>

<details>
	<summary>list-participants</summary>
	<br>
	Exibe todos os usuários que estão no servidor que o usuário está atualmente conectado (somente o nome de cada).<br><br>
	
	list-participants
 
	Tomé
	Bebé
	Nana
	Jonas
</details>

<h3>B1 - Gestão de canais (se tiver entrado no servidor)</h3>

<details>
	<summary>list-channels</summary>
	<br>
	Exibe todos os canais do servidor, mostrando primeiro os nomes dos canais de texto, em seguida os nomes dos canais de voz.<br><br>
	
	list-channels
 
	#canais de texto
	casa-de-mae-joana
	aqui-nós-faz-o-trabalho
 
	#canais de audio
	Professor-Me-Ajude
	Revolta-dos-Alunos
</details>

<details>
	<summary>create-channel</summary>
	<br>
	Permite criar um canal no servidor informando seu nome e seu tipo (voz ou texto).<br><br>
	
	create-channel casa-de-mae-joana texto
	Canal de texto ‘casa-de-mae-joana’ criado
 
	create-channel casa-de-mae-joana2 voz
	Canal de voz ‘casa-de-mae-joana2’ criado
 
	create-channel casa-de-mae-joana2 voz
	Canal de voz ‘casa-de-mae-joana2’ já existe!
 
	create-channel casa-de-mae-joana texto
	Canal de texto ‘casa-de-mae-joana’ já existe!
</details>

<details>
	<summary>enter-channel</summary>
	<br>
	Entra em um canal presente na lista de canais do servidor.<br><br>
	
	enter-channel casa-de-mae-joana
	Entrou no canal ‘casa-de-mae-joana’
 
	enter-channel introspecção
	Canal ‘introspecção’ não existe
</details>

<details>
	<summary>leave-channel</summary>
	<br>
	Sai do canal, ou seja, seta a variável que guarda o canal atual do usuário logado como "" (nenhum).<br><br>
	
	leave-channel
	“Saindo do canal”
</details>

<h3>B2 - Gestão de mensagens (se tiver entrado no servidor e em algum canal)</h3>

<details>
	<summary>send-message</summary>
	<br>
	Cria uma mensagem e adiciona na lista de mensagens do canal atual.<br><br>
	
	send-message Oi pessoal alguém pode me ajudar?
</details>

<details>
	<summary>list-messages</summary>
	<br>
	Lista todas as mensagens do canal.<br><br>
	
	list-messages
 
	Julio<08/03/2021 - 11:53>: Assim não tem condições, como que a
	galera vai conseguir terminar isso tudo em 3 semanas?
 
	Isaac<08/03/2021 - 12:00>: Eles conseguem confio na galera
 
	Renan<08/03/2021 - 12:00>: Semestre passado fizemos assim e
	ninguém entregou :/

 	list-messages
	Sem mensagens para exibir
</details>

<br>

<h3 align = "center"> - By <a href = "https://www.linkedin.com/in/breno-barbosa-de-oliveira-810866275/" target = "_blank">Breno</a> - </h3>
