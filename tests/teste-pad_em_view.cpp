#include <cstddef>
#include <iostream>
#include <string>

int main() {
    std::cout << "Digite um nome: ";
    std::string nome {};
    std::getline(std::cin >> std::ws, nome);

    for(std::size_t i{}; i < nome.length(); ++i) {
        std::cout << "-";
    }
    
    std::cout << '\n' << nome << '\n';
    
    for(std::size_t i{}; i < nome.length(); ++i) {
        std::cout << "-";
    }

}