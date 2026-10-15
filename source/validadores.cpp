/***********************************************************************************************************************
- AUTOR:        Bruno Costa ( aka Kbelx_ )
- DATA:         <26/maio/2026>
- PROPOSITO:    Arquivo para validações
***********************************************************************************************************************/

#include <cstddef>
#include <iostream>
#include <string>
#include <string_view>
#include <array>
#include <cctype>
#include <format>

#ifdef _WIN32
    #include <windows.h>
#endif

#include "constantes.h"
#include "validadores.h"

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

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
            return true;
        }
    }
            
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


void exibirMensagemValidacao(std::string_view SO, bool sucesso){
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif
    
    std::string linha1_pura { std::format("Sistema Operacional: {}", SO) };
    std::string linha1_colorida { std::format("Sistema Operacional: {}{}{}", Cores::CYAN, SO, Cores::RESET) };
    
    std::string str_status = (sucesso ? "Status: SUCESSO" : "Status: ERRO");

    std::string str_status_colorido = (sucesso ? 
        std::format("Status: {}SUCESSO{}", Cores::GREEN, Cores::RESET) : 
        std::format("Status: {}ERRO{}", Cores::RED, Cores::RESET));
    
    
    // formatação da moldura, baseada na formula: 
    size_t tamanho = linha1_pura.length();
    size_t espacos = ((tamanho > str_status.length()) ? (tamanho - str_status.length()) : 0);
    std::string padding(espacos, ' ');
    std::string linha2_colorida { str_status_colorido + padding };

    // 1. Topo da moldura: Canto esquerdo + linhas + Canto direito
    std::cout << "╭"; for(size_t i{}; i < tamanho; ++i) { std::cout << "─"; }std::cout << "╮\n";
    
    // 2. Meio (duas linhas agora):
    std::cout << "│" << linha1_colorida << "│\n";
    std::cout << "│" << linha2_colorida << "│\n";
    
    // 3. Base da moldura: Canto esquerdo + linhas + Canto direito
    std::cout << "╰"; for(size_t i{}; i < tamanho; ++i) { std::cout << "─"; }std::cout << "╯\n";
}


bool validar_nomeProjeto(std::string_view nome) {
    bool nome_valido { true };
    
    /*
    AUTOR: Bruno Costa
    DATA: 22 de Julho de 2026
    DESCRIÇÃO: EXPLICAÇÃO SOBRE O PORQUE DAS VALIDAÇÕES ESTAREM "DUPLICADAS"

    Fiz uma função onde exibe uma moldura, indicando o status do:
    - Sistema Operacionald o User;
    - Se a operação foi um sucesso.

    Como eu queria definir o status da moldura, eu tive que validar silenciosa
    -mente primeiro.

    Talvez, no futuro, eu deixe isso mais legível...
    ( tenho andado meio atarefado)
    */
    
    #if 1
    if (validar_nomeVazio(nome)) {
        nome_valido = false;

    } else {
        if constexpr (SistemaOperacional::WINDOWS) {
            if (validar_CharsProibidosWindows(nome)) nome_valido = false;
            if (validar_finalInvalidoWindows(nome)) nome_valido = false;
            if (validar_nomeReservadoWindows(nome)) nome_valido = false;

        } else {
            if (validar_CharsProibidosPosix(nome)) nome_valido = false;
        }

        if (nome_valido && contem_caractere_controle(nome)) {
            nome_valido = false;
        }
    }
    # endif
    
    exibirMensagemValidacao(SistemaOperacional::NOME, nome_valido);

    if (validar_nomeVazio(nome)) {
        InterfaceErro::exibir_erro("Nome do projeto NÃO PODE estar vazio!");
        return false;
    }
    
    if constexpr (SistemaOperacional::WINDOWS) {
        if (validar_CharsProibidosWindows(nome)) {
            InterfaceErro::exibir_erro(std::format(
                "Nome do projeto NÃO PODE conter estes caracteres no Windows: {}\n\n"
                "DICA: Use letras, numeros, espacos, '_' ou '-'.",
                Proibidos::CARACTERES_WINDOWS
            ));
        }
        
        if (validar_finalInvalidoWindows(nome)) {
            InterfaceErro::exibir_erro("Nome do projeto NÃO PODE começar ou terminar com espaço ou ponto no Windows.");
        }
        
        if (validar_nomeReservadoWindows(nome)) {
            InterfaceErro::exibir_erro(
                "Nome do projeto NÃO PODE usar nome reservado do Windows.\n\n"
                "DICA: Evite nomes como CON, PRN, AUX, NUL, COM1 e LPT1."
            );
        }
    } else {
        if (validar_CharsProibidosPosix(nome)) {
            InterfaceErro::exibir_erro("Nome do projeto NÃO PODE conter '/' ou caractere nulo neste sistema.");
        }
    }
    
    if (nome_valido && contem_caractere_controle(nome)) {
        InterfaceErro::exibir_erro("Nome do projeto NÃO PODE conter caracteres de controle.");
    }
    
    return nome_valido;
}
