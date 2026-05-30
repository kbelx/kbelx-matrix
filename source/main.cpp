/***********************************************************************************************************************
- AUTOR:        Bruno Costa ( aka Kbelx_ ) 
- DATA:         <25/maio/2026>
- PROPOSITO:    Arquivo Principal do Projeto
***********************************************************************************************************************/

#include <clocale>
#include <format>
#include <iostream>
#include <string>

#include "cores.h"
#include "utils.h"
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
    setlocale(LC_ALL, "pt-BR.UTF-8");

    // 1 Solicita nome do projeto 
    std::string nome_projeto { solicitarNomeProjeto() };

    // 2 - Valida nome do projeto
    if (!validar_nomeProjeto(nome_projeto)){
        std::cout << std::format("{}ERRO{}: Falha ao validar nome.", Cores::RED, Cores::RESET) << '\n';
        return 1;
        
    } else {

        // 3 - Cria diretório raiz
        if (!criarDiretorioRaiz(nome_projeto)) {
            std::cout << std::format("{}ERRO{}: Falha ao criar a pasta {}.", Cores::RED, Cores::RESET, nome_projeto) << '\n';
            return 1;
        }

        InterfaceSucesso::exibir_sucesso(
            std::format("{}SUCESSO{}: Pasta {} esta pronta.", Cores::GREEN, Cores::RESET, nome_projeto)
        );

        // 4 - Cria subpastas
        

        // 5 - gera "metadados.txt"
        

    }        

    
    
    std::cin.ignore();
}

