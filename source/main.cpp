/***********************************************************************************************************************
- AUTOR:        Bruno Costa ( aka Kbelx_ ) 
- DATA:         <25/maio/2026>
- PROPOSITO:    Arquivo Principal do Projeto
***********************************************************************************************************************/

#include <clocale>
#include <format>
#include <iostream>
#include <string>

#include "constantes.h"
#include "validadores.h"
#include "arquivos.h"

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

inline std::string solicitarNomeProjeto(){
    std::cout << std::format("Digite o {}nome{} do projeto: ", Cores::RED, Cores::RESET);
    std::string nomeProjeto {};
    std::getline(std::cin, nomeProjeto);

    return nomeProjeto;
}


int main() {
    std::setlocale(LC_ALL, "pt-BR.UTF-8");

    // 1 - Solicita nome do projeto 
    std::string nome_projeto { solicitarNomeProjeto() };

    // 2 - Valida nome do projeto
    if (!validar_nomeProjeto(nome_projeto)) {
        std::cin.ignore();
        return 1;
    }

    // 3 - Cria diretório raiz
    if (!criarDiretorioRaiz(nome_projeto)) {
        std::cin.ignore();
        return 1;
    }

    // 4 - Cria subpastas
    if (!criarAudioFiles(nome_projeto) ||
        !criarSessionFiles(nome_projeto) ||
        !criarBouncedFiles(nome_projeto)) {
        std::cin.ignore();
        return 1;
    }

    // 5 - Gera "metadados.txt"
    if (!criarMetadados(nome_projeto)) {
        std::cin.ignore();
        return 1;
    }

    // 6 - Exibe mensagem de sucesso
    InterfaceSucesso::exibir_sucesso(std::format("Pasta \"{}\" criada com sucesso.", nome_projeto));
    
    std::cin.ignore();
    return 0;
}

