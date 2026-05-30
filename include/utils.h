#ifndef UTILS_H
#define UTILS_H

#include <string_view>

namespace SistemaOperacional {
#if defined(_WIN32)
    inline constexpr bool WINDOWS { true };
    inline constexpr std::string_view NOME { "Windows" };
#else
    inline constexpr bool WINDOWS { false };
    inline constexpr std::string_view NOME { "Linux/macOS" };
#endif
}

namespace InterfaceErro {
    void exibir_erro(std::string_view mensagem);
}

#endif
