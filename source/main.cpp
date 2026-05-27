/*******************************************************************************
DATA:         <25/maio/2026>
PROPOSITO:    Arquivo Principal do Projeto
*******************************************************************************/

#include <clocale>
#include <format>
#include <iostream>
#include <string>

#include "cores.h"
#include "validadores.h"


std::string solicitarNomeProjeto(){
    std::cout << std::format("Digite o {}nome{} do projeto: ", Cores::RED, Cores::RESET);
    std::string nomeProjeto {};
    std::getline(std::cin, nomeProjeto);

    return nomeProjeto;
}


int main() {
    setlocale(LC_ALL, "pt-BR.UTF-8");

    std::string nome_projeto { solicitarNomeProjeto() };
    //std::cout << "Você digitou: " << nome_projeto << '\n';
    if (!validar_nomeProjeto(nome_projeto)) {
        return 1;
    }
    //std::cout << "nome do projeto: " << nome_projeto << '\n';

    
    std::cin.ignore();
}
