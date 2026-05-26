#include <iostream>
#include <string>
#include <string_view>

#include "cores.h"
#include "validadores.h"

namespace Proibidos {

    // Caracteres Reservados
    constexpr std::string_view CARACTERES {R"(\/:*?"<>|)"};

    // Nomes reservados para Windows
    const char* nomes_reservados_windows[] { 
        "CON","PRN","AUX","NUL",
        "COM1","COM2","COM3","COM4",
        "COM5","COM6","COM7","COM8",
        "COM9","LPT1","LPT2","LPT3",
        "LPT4","LPT5","LPT6","LPT7",
        "LPT8","LPT9" };
}


// 1 - Encerra o programa caso NOME ESTEJA VAZIO.
void validar_nomeVazio(std::string_view nome) {
    if (nome.empty()) {
        std::cout << "❌ Nome do projeto vazio!" << "\n";
    }
}


// 2 - Encerra o programa caso o nome tenha CARACTERES PROIBIDOS.
void validar_CharsProibidos(std::string_view nome) {
    for (char letra : nome) {
        if (Proibidos::CARACTERES.contains(letra)) {
            std::cout << "❌ Nome inválido: " << nome << '\n';
            //std::cout << std::format("Caracteres proibidos: ")
            std::cout << "Use apenas letras, números, '_' e '-' (recomendado)." << '\n';
        }
    }
}




// =-=-=-=-=-=--=-=-=-=-=-=-=-= [MAIN DO ARQUIVO] =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

void validar_nomeProjeto(std::string_view nome) {

    validar_nomeVazio(nome);
    validar_CharsProibidos(nome);

}
