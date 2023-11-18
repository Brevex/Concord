<h1 align = "center"> Concord </h1>

<br>

<h2> &#128269; About the project </h2>

<br>

<p>A simple C++ program that simulates a chat via terminal. The program works by receiving commands
that perform a certain function, such as creating users, sending messages, creating
servers, create channels, etc.</p>

<br>

<h2> &#128296; Dependencies and Execution </h2>

<ol>
   <li>Download a C/C++ compiler</li>
   <li>Download CMake</li>
   <li>Configure CMake and the compiler on your machine</li>
   <li>Download this project and open the terminal inside the <code>build</code> folder</li>
   <li>With the terminal open, run in sequence the following commands:</li>
</ol>

 	cmake..  
<br>

	make
<br>

	./concord

<h2> &#128302; Technologies Used </h2>

<br>

<p align="center">
  <a href="https://skillicons.dev">
    <img src="https://skillicons.dev/icons?i=cpp,cmake" />
  </a>
</p>

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
	Displays the names of servers in the system, one per line.<br><br>
	
	list-servers
 
	minha-casa
	minha-casa2
	RPG-galera
	Bate-papo
</details>

<details>
	<summary>remove-server</summary>
	<br>
	Removes a server (entering its name). Removal can only be successful if the server owner is the logged in user.<br><br>
	
	remove-server minha-casa
	‘minha-casa’ server removed
 
	remove-server minha-casa
	You are not the owner of the ‘minha-casa’ server

 	remove-server minha-casa3
	Server ‘minha-casa3’ not found
</details>

<details>
	<summary>enter-server</summary>
	<br>
	Join a server. If the server is open (does not have an invitation code), the user ID is inserted into the server's participant list automatically. If the server is not open, you should only add the server as a participant if you enter the correct code. If the logged-in user created the server, he can enter it without an invitation code, even if it is not opened.<br><br>
	
	enter-server dotalovers
	Successfully joined the server
 
	enter-server concordo-members
	Server requires invitation code

 	enter-server concordo-members 123456
	Successfully joined the server
</details>

<details>
	<summary>leave-server</summary>
	<br>
	Disconnects from the server the user is currently connected to. Notice that the user remains on the list of participants. The record of which server the user is currently viewing (in the System class) should change to a value that represents "none".<br><br>
	
	leave-server
	Leaving the ‘minha-casa’ server
 
	leave-server
	You are not viewing any servers
</details>

<details>
	<summary>list-participants</summary>
	<br>
	Displays all users that are on the server that the user is currently connected to (only the name of each).<br><br>
	
	list-participants
 
	Tomé
	Bebé
	Nana
	Jonas
</details>

<h3>B1 - Channel management (if you have logged into the server)</h3>

<details>
	<summary>list-channels</summary>
	<br>
	Displays all channels on the server, first showing the text channel names, then the voice channel names.<br><br>
	
	list-channels
 
	#text channels
	casa-de-mae-joana
	aqui-nós-faz-o-trabalho
 
	#audio channels
	Professor-Me-Ajude
	Revolta-dos-Alunos
</details>

<details>
	<summary>create-channel</summary>
	<br>
	Allows you to create a channel on the server by entering its name and type (voice or text).<br><br>
	
	create-channel casa-de-mae-joana texto
	Text channel ‘casa-de-mae-joana’ created
 
	create-channel casa-de-mae-joana2 voz
	Voice channel ‘casa-de-mae-joana’ created
 
	create-channel casa-de-mae-joana2 voz
	Voice channel ‘casa-de-mae-joana2’ already exists!
 
	create-channel casa-de-mae-joana texto
	Text channel ‘casa-de-mae-joana’ already exists!
</details>

<details>
	<summary>enter-channel</summary>
	<br>
	Join a channel in the server's channel list.<br><br>
	
	enter-channel casa-de-mae-joana
	Joined the channel ‘casa-de-mae-joana’
 
	enter-channel introspecção
	‘introspecção’ channel does not exist
</details>

<details>
	<summary>leave-channel</summary>
	<br>
	Leave the channel, that is, set the variable that stores the logged in user's current channel to "" (none).<br><br>
	
	leave-channel
	Leaving the channel
</details>

<h3>B2 - Message management (if you have entered the server and a channel)</h3>

<details>
	<summary>send-message</summary>
	<br>
	Create a message and add it to the current channel's message list.<br><br>
	
	send-message Hi guys, can anyone help me?
</details>

<details>
	<summary>list-messages</summary>
	<br>
	Lists all messages in the channel.<br><br>
	
	list-messages
 
	Julio<08/03/2021 - 11:53>: Assim não tem condições, como que a
	galera vai conseguir terminar isso tudo em 3 semanas?
 
	Isaac<08/03/2021 - 12:00>: Eles conseguem confio na galera
 
	Renan<08/03/2021 - 12:00>: Semestre passado fizemos assim e
	ninguém entregou :/

 	list-messages
	No messages to display
</details>

<br>

<h3 align = "center"> - By <a href = "https://www.linkedin.com/in/breno-barbosa-de-oliveira-810866275/" target = "_blank">Breno</a> - </h3>
