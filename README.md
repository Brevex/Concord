<h1 align = "center"> Concord </h1>

<br>

<h2> &#128269; About the project </h2>

<br>

<p> Project carried out during the Bachelor of Information Technology (BTI)
for the subject Programming Language I. This is a program made in C++ that simulates a chat via terminal. The program works by receiving commands
that perform a certain function, such as creating users, sending messages, creating
servers, create channels, etc.</p>

<br>

<h2> &#128296; Dependencies and Execution </h2>

<br>

<p>To compile and run this program on your machine, you will need CMake and
the code compiler for C/C++, which can be gcc or g++. To create the executable
go to the "build" folder, right click and open the terminal
inside that folder. With the terminal open, type "cmake.." and press enter, then
type "make" and hit enter again. Finally, type "./concord" to run
the program.</p>

<br>

<h2> &#128302; Technologies Used </h2>

<br>

<div style="display: inline_block" align="center">
  <img align="center" alt="C++" height="50" width="60" src="https://github.com/isocpp/logos/blob/master/cpp_logo.svg" />
  <img align="center" alt="CSS" height="50" width="60" src="https://github.com/vscode-icons/vscode-icons/blob/master/icons/file_type_cmake.svg" />    
</div>

<br>

<h2> &#128161; Program Functions </h2>

<br>

<p>As mentioned before, the program works based on terminal commands
created exclusively for Concord. Below are the commands and their functions:</p>

<h3>A1 - If you are not logged in (As soon as you enter the system)</h3>

<details>
	<summary>create-user</summary>
	<br>
	Creates a new user in the system, receiving email, password and name as parameters. 
	Each user is unique, try to create a user with the same email/password as another 
	will result in an error, as will the lack of any of these parameters.<br><br>
	
	create-user julio.melo@imd.ufrn.br 12ab34cd Julio Melo
	User created
 
	create-user julio.melo@imd.ufrn.br 12ab34cd Julio Silva
	User already exists!
</details>

<details>
	<summary>login</summary>
	<br>
	This procedure checks if there is already a user in the general register with that email and 
	password entered. If it exists, then the user has logged in successfully.<br><br>
	
	login julio.melo@imd.ufrn.br 12ab34cd
	Logged in as julio.melo@imd.ufrn.br
 
	login julio.melo@imd.ufrn.br 1326
	Invalid password or username!
</details>

<details>
	<summary>quit</summary>
	<br>
	Close the application, this command can be executed at any time by user.<br><br>
	
	quit
	Leaving Concord
</details>

<h3>A2 - Basic interactions with Servers (If logged in)</h3>

<details>
	<summary>disconnect</summary>
	<br>
	Disconnects the current user, that is, changes the variable that stores the 
	currently logged in user. The system continues to run, but it needs to be done 
	login again so that the rest of the commands (with the exception of create-user) are 
	performed correctly again.<br><br>
	
	disconnect
	Disconnecting user julio.melo@imd.ufrn.br
 
	disconnect
	Not connected
</details>

<details>
	<summary>create-server</summary>
	<br>
	Create a new server by passing its name. The create-server <server-name> command 
	creates a new server if it is not exist under that name.<br><br>
	
	create-server minha-casa
	Server created
 
	create-server minha-casa
	Server with that name already exists
</details>

<details>
	<summary>set-server-desc</summary>
	<br>
	Changes the description of an already created server. It must be verified that the server you are trying to change the description is yours.<br><br>
	
	set-server-desc minha-casa “This server serves as my home, I will always be on it”
	‘minha-casa’ server description modified!
 
	set-server-desc minha-casa2 “This server serves as my home, I will always be on it”
	Server ‘minha-casa2’ does not exist

 	set-server-desc minha-casa55 “Changing other people’s server descriptions”
  	You cannot change the description of a server that you did not create
</details>

<details>
	<summary>set-server-invite-code</summary>
	<br>
	Change a server's invite code. If you use the command without any code, then the server changes its code to "" and 
	It is free for anyone to enter. By default, servers do not have an invitation code. It must be verified that the server you are trying to change the invitation code is yours.<br><br>
	
	set-server-invite-code minha-casa 4567
	Modified 'minha-casa' server invitation code!
 
	set-server-invite-code minha-casa
	'minha-casa' server invitation code removed!
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
	Saindo do canal
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
