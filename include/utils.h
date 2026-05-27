#ifndef UTILS_H
#define UTILS_H

#include <string_view>

namespace Cores {
    extern const std::string_view RESET;
    extern const std::string_view RED;
    extern const std::string_view GREEN;
    extern const std::string_view YELLOW;
    extern const std::string_view BLUE;
    extern const std::string_view CYAN;
    extern const std::string_view GRAY;
}

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
