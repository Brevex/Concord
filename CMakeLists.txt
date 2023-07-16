cmake_minimum_required(VERSION 3.0)

# Nome do seu projeto
project(concord)

# Arquivos de origem
set(SOURCES
src/Usuario.cpp
src/Mensagem.cpp
src/Canal.cpp
src/CanalTexto.cpp
src/CanalVoz.cpp
src/Servidor.cpp
src/Sistema.cpp
src/Concord.cpp)

# Diretorios de inclusão
include_directories(include)

# Adiciona a flag de depuração "-g" ao compilar com o GCC ou Clang
if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
endif()

# Adiciona a flag de depuração "/DEBUG" ao compilar com o MSVC
if(MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /DEBUG")
endif()

# Cria executavel
add_executable(concord ${SOURCES})


