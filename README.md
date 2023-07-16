<h1 align = "center"> Concord </h1>

<br>

<h2> &#128269; Sobre o Projeto </h2>

<br>

<p> Projeto realizado durante o Bacharelado em Tecnologia da Informação (BTI) 
para a matéria Linguagem de Programação I. Se trata de um programa feito em 
C++ que simula um chat via terminal. O programa funciona recebendo comandos
que executam uma determinada função, como criar usuários, enviar mensagens, criar
servidores, criar canais de etc.</p>

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

<br>

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
