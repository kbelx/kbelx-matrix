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
#include "validadores.h"


std::string solicitarNomeProjeto(){
    std::cout << std::format("Digite o {}nome{} do projeto: ", Cores::RED, Cores::RESET);
    std::string nomeProjeto {};
    std::getline(std::cin >> std::ws, nomeProjeto);

    return nomeProjeto;
}


int main() {
    setlocale(LC_ALL, "pt-BR.UTF-8");

    std::string nome_projeto { solicitarNomeProjeto() };
    validar_nomeProjeto(nome_projeto);
    //std::cout << "nome do projeto: " << nome_projeto << '\n';

    
    std::cin.ignore();
}
