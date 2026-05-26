/*******************************************************************************
DATA:         <25/maio/2026>
PROPOSITO:    Arquivo Principal do Projeto
*******************************************************************************/

#include <clocale>
#include <format>
#include <iostream>
#include <string>
#include <string_view>

#include "cores.h"


std::string solicitarNomeProjeto(){
    std::cout << std::format("Digite o {}nome{} do projeto: ", Cores::RED, Cores::RESET) ;
    std::string nomeProjeto {};
    std::cin >> nomeProjeto;

    return nomeProjeto;
}


int main() {
    setlocale(LC_ALL, "pt-BR.UTF-8");

    std::string_view nome { solicitarNomeProjeto() };
    std::cout << "nome do projeto: " << nome << '\n';
    
    std::cin.ignore();
}
