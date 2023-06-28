#include "../include/CanalTexto.h"
#include "../include/CanalVoz.h"
#include "../include/Sistema.h"

int main(int argc, char* argv[])
{
    Sistema sistema;

    while (true)
    {
        std::string linhaComando;

        std::cout << std::endl;
        std::cout << ">> ";
        
        std::getline(std::cin, linhaComando);

        sistema.executar(linhaComando);
    }

    return 0;
}
