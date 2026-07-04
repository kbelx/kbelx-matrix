/***********************************************************************************************************************
- AUTOR:        Bruno Costa ( aka Kbelx_ ) 
- DATA:         4/Julho/2026>
- PROPOSITO:    Arquivo contendo todas as constantes usadas no projeto

Envolve:
- Constantes de cores;
- de Arquivos;
- de utilidade;
- etc...

***********************************************************************************************************************/

#ifndef CONSTANTES_H
#define CONSTANTES_H

    #include <string_view>

    // Constantes de Cores ( em ASCII )
    namespace Cores {
        
        using std::string_view;
        
        inline constexpr string_view RESET {"\033[m"};
        inline constexpr string_view RED {"\033[1;49;31m"};
        inline constexpr string_view GREEN {"\033[1;49;32m"};
        inline constexpr string_view YELLOW {"\033[1;49;33m"};
        inline constexpr string_view BLUE {"\033[1;49;34m"};
        inline constexpr string_view CYAN {"\033[1;49;36m"};
        inline constexpr string_view GRAY {"\033[1;49;90m"};
    }


    namespace SistemaOperacional {

        // NT
        #ifdef _WIN32
            inline constexpr bool WINDOWS { true };
            inline constexpr std::string_view NOME { "Windows" };

        // Posix
        #else
            inline constexpr bool WINDOWS { false };
            inline constexpr std::string_view NOME { "Linux/macOS" };

        #endif
    }


    namespace InterfaceErro {
        void exibir_erro(std::string_view mensagem);
    }


    namespace InterfaceSucesso {
        void exibir_sucesso(std::string_view mensagem);
    }


#endif