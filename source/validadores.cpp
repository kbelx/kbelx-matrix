#include <array>
#include <cctype>
#include <format>
#include <iostream>
#include <string>
#include <string_view>

#if defined(_WIN32)
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
#endif

#include "cores.h"
#include "validadores.h"

namespace SistemaOperacional {
#if defined(_WIN32)
    constexpr bool WINDOWS { true };
    constexpr std::string_view NOME { "Windows" };
#else
    constexpr bool WINDOWS { false };
    constexpr std::string_view NOME { "Linux/macOS" };
#endif
}

namespace Proibidos {
    // Regras de nomes de arquivos no Windows.
    constexpr std::string_view CARACTERES_WINDOWS {R"(\/:*?"<>|)"};

    constexpr std::array<std::string_view, 22> NOMES_WINDOWS {
        "CON", "PRN", "AUX", "NUL",
        "COM1", "COM2", "COM3", "COM4",
        "COM5", "COM6", "COM7", "COM8",
        "COM9", "LPT1", "LPT2", "LPT3",
        "LPT4", "LPT5", "LPT6", "LPT7",
        "LPT8", "LPT9"
    };
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

// Vê se o nome é vazio
bool validar_nomeVazio(std::string_view nome) {
    return nome.empty();
}


bool contem_caractere_controle(std::string_view nome) {
    for (char caractere : nome) {
        const auto codigo { static_cast<unsigned char>(caractere) };
        if (codigo < 32) {
            return true;
        }
    }

    return false;
}


// [WINDOWS] Vê se o nome contém caracteres especiais
bool validar_CharsProibidosWindows(std::string_view nome) {
    for (char caractere : nome) {
        if (Proibidos::CARACTERES_WINDOWS.contains(caractere)) {
            return true;}}
    
    return contem_caractere_controle(nome);
}

// [LINUX/APPLE] Vê se o nome contém caracteres especiais
bool validar_CharsProibidosPosix(std::string_view nome) {
    return nome.contains('/') || nome.contains('\0');
}

// [WINDOWS] Vê se o nome termina com espaço ou ponto
bool validar_finalInvalidoWindows(std::string_view nome) {
    return !nome.empty() && (nome.back() == ' ' || nome.back() == '.');
}


std::string nome_base_windows(std::string_view nome) {
    const std::size_t ponto { nome.find('.') };
    std::string base { nome.substr(0, ponto) };

    while (!base.empty() && (base.back() == ' ' || base.back() == '.')) {
        base.pop_back();
    }

    for (char& caractere : base) {
        caractere = static_cast<char>(std::toupper(static_cast<unsigned char>(caractere)));
    }

    return base;
}


bool validar_nomeReservadoWindows(std::string_view nome) {
    const std::string base { nome_base_windows(nome) };

    for (std::string_view reservado : Proibidos::NOMES_WINDOWS) {
        if (base == reservado) {
            return true;
        }
    }

    return false;
}

// =-=-=-=-=-=--=-=-=-=-=-=-=-= [MAIN DO ARQUIVO] =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

bool validar_nomeProjeto(std::string_view nome) {
    bool nome_valido { true };

    std::cout << std::format("Validando nome para {}{}{}...\n", Cores::CYAN, SistemaOperacional::NOME, Cores::RESET);

    // TESTE POP-UP
    if (validar_nomeVazio(nome)) {
        InterfaceErro::exibir_erro("Nome do projeto NÃO PODE estar vazio!");
        return false;
    }

    // Verificar erros no S.O. Windows
    if constexpr (SistemaOperacional::WINDOWS) {

        // 1 - Verificar se o nome TEM CARACTERES RESERVADOS 
        if (validar_CharsProibidosWindows(nome)) {
            InterfaceErro::exibir_erro(std::format(
                "Nome do projeto NÃO PODE conter estes caracteres no Windows: {}\n\n"
                "DICA: Use letras, numeros, espacos, '_' ou '-'.",
                Proibidos::CARACTERES_WINDOWS
            ));
            nome_valido = false;
        }

        // 2 - Verificar se o nome TEM INICIO/FINAL RESERVADOS
        if (validar_finalInvalidoWindows(nome)) {
            InterfaceErro::exibir_erro("Nome do projeto NÃO PODE começar ou terminar com espaço ou ponto no Windows.");
            nome_valido = false;
        }

        // 3 - Verificar se o nome TEM NOMES RESERVADOS
        if (validar_nomeReservadoWindows(nome)) {
            InterfaceErro::exibir_erro(
                "Nome do projeto NÃO PODE usar nome reservado do Windows.\n\n"
                "DICA: Evite nomes como CON, PRN, AUX, NUL, COM1 e LPT1."
            );
            nome_valido = false;
        }

    // Verificar erros no S.O. Linux/Apple
    } else {

        // 1 - Verificar se o nome TEM CARACTERES RESERVADOS 
        if (validar_CharsProibidosPosix(nome)) {
            InterfaceErro::exibir_erro("Nome do projeto NÃO PODE conter '/' ou caractere nulo neste sistema.");
            nome_valido = false;
        }
    }

    if (nome_valido && contem_caractere_controle(nome)) {
        InterfaceErro::exibir_erro("Nome do projeto NÃO PODE conter caracteres de controle.");
        nome_valido = false;
    }

    return nome_valido;
}
