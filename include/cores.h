#ifndef CORES_H
#define CORES_H

#include <string_view>

namespace Cores {
    [[maybe_unused]] inline const std::string_view RESET {"\033[m"};
    [[maybe_unused]] inline const std::string_view RED {"\033[1;49;31m"};
    [[maybe_unused]] inline const std::string_view GREEN {"\033[1;49;32m"};
    [[maybe_unused]] inline const std::string_view YELLOW {"\033[1;49;33m"};
    [[maybe_unused]] inline const std::string_view BLUE {"\033[1;49;34m"};
    [[maybe_unused]] inline const std::string_view CYAN {"\033[1;49;35m"};
    [[maybe_unused]] inline const std::string_view GRAY {"\033[1;49;90m"};
}

#endif