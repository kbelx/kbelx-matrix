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
    std::setlocale(LC_ALL, "pt-BR.UTF-8");

    // 1 Solicita nome do projeto 
    std::string nome_projeto { solicitarNomeProjeto() };

    // 2 - Valida nome do projeto
    if (!validar_nomeProjeto(nome_projeto)){
        return 1;
        
    } else {

        // 3 - Cria diretório raiz e Subpastas
        if (!criarDiretorioRaiz(nome_projeto)) {
            return 1;
        } else {
            //std::cout << std::format("{}SUCESSO{}", Cores::GREEN, Cores::RESET) << '\n';
            InterfaceSucesso::exibir_sucesso(std::format("Pasta \"{}\" criada com sucesso.", nome_projeto));
            return 0;
        }
        

        // 4 - Cria subpastas
        

        // 5 - gera "metadados.txt"
        

    }        

    
    
    std::cin.ignore();
}

