/***********************************************************************************************************************
- AUTOR:        Bruno Costa ( aka Kbelx_ ) 
- DATA:         27/maio/2026>
- PROPOSITO:    Arquivo de Utilidades para todo o projeto
***********************************************************************************************************************/

#include <iostream>
#include <string>
#include <string_view>

#if defined(_WIN32)
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
#endif

#include "utils.h"

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

namespace Cores {
    const std::string_view RESET {"\033[m"};
    const std::string_view RED {"\033[1;49;31m"};
    const std::string_view GREEN {"\033[1;49;32m"};
    const std::string_view YELLOW {"\033[1;49;33m"};
    const std::string_view BLUE {"\033[1;49;34m"};
    const std::string_view CYAN {"\033[1;49;35m"};
    const std::string_view GRAY {"\033[1;49;90m"};
}

namespace InterfaceErro {
#if defined(_WIN32)
    std::wstring utf8_para_wide(std::string_view texto) {
        if (texto.empty()) {
            return {};
        }

        const auto tamanho_texto { static_cast<int>(texto.size()) };
        const int tamanho_convertido {
            MultiByteToWideChar(CP_UTF8, 0, texto.data(), tamanho_texto, nullptr, 0)
        };

        if (tamanho_convertido == 0) {
            return L"Erro de validação.";
        }

        std::wstring resultado(static_cast<std::size_t>(tamanho_convertido), L'\0');
        MultiByteToWideChar(CP_UTF8, 0, texto.data(), tamanho_texto, resultado.data(), tamanho_convertido);

        return resultado;
    }

    void exibir_erro(std::string_view mensagem) {
        const std::wstring mensagem_wide { utf8_para_wide(mensagem) };
        MessageBoxW(nullptr, mensagem_wide.c_str(), L"ERRO DE VALIDAÇÃO", MB_OK | MB_ICONERROR);
    }
#else
    void exibir_erro(std::string_view mensagem) {
        std::cout << "[!!!]" << Cores::RED << " ERRO " << Cores::RESET << "[!!!]" << '\n';
        std::cout << mensagem << '\n';
    }
#endif
}
