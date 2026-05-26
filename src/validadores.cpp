#include <iostream>
#include <string_view>

namespace Proibidos {
    constexpr std::string_view CARACTERES {R"(\/:*?"<>|)"};

}

void validar_nomeProjeto(std::string_view nome) {

    // 1 - Encerra o programa caso NOME ESTEJA VAZIO.
    if (nome.empty()) {
        std::cout << "❌ Nome do projeto vazio!" << '\n';
    }

    // 2 - Encerra o programa caso o nome tenha CARACTERES PROIBIDOS.
    for (char letra : nome) {

        if (Proibidos::CARACTERES.contains(letra)) {
            std::cout << "❌ Nome inválido: " << nome << '\n';
            //std::cout << std::format("Caracteres proibidos: ")
            std::cout << "Use apenas letras, números, '_' e '-' (recomendado)." << '\n';
        }
    }

}