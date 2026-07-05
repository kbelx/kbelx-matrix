/***********************************************************************************************************************
- AUTOR:        Bruno Costa ( aka Kbelx_ ) 
- DATA:         27/maio/2026>
- PROPOSITO:    Arquivo de Utilidades para todo o projeto
***********************************************************************************************************************/

// #include <iostream>
#include <string>
#include <string_view>

#ifdef _WIN32
    #include <windows.h>
#endif

#include "constantes.h"

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#ifdef _WIN32
    namespace {
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

        void exibir_caixa_mensagem(std::string_view mensagem, const wchar_t* titulo, UINT tipo) {
            const std::wstring mensagem_wide { utf8_para_wide(mensagem) };
            MessageBoxW(nullptr, mensagem_wide.c_str(), titulo, MB_OK | tipo);
        }
    }
#endif


namespace InterfaceErro {
    #ifdef _WIN32
        void exibir_erro(std::string_view mensagem) {
            exibir_caixa_mensagem(mensagem, L"ERRO DE VALIDAÇÃO", MB_ICONERROR);
        }
    #else
        void exibir_erro(std::string_view mensagem) {
            std::cout << mensagem << '\n';
        }
    #endif
}


namespace InterfaceSucesso {
    #ifdef _WIN32
        void exibir_sucesso(std::string_view mensagem) {
            exibir_caixa_mensagem(mensagem, L"MENSAGEM DE CONCLUSÃO", MB_ICONASTERISK);
        }
    #else
        void exibir_sucesso(std::string_view mensagem) {
            std::cout << mensagem << '\n';
        }
    #endif
}
