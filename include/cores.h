/***********************************************************************************************************************
- AUTOR:        Bruno Costa ( aka Kbelx_ ) 
- DATA:         30/maio/2026>
- PROPOSITO:    Arquivo contendo cores em ASCII
***********************************************************************************************************************/

#ifndef CORES_H
#define CORES_H

#include <string_view>

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

namespace Cores {
    
    using std::string_view;
    
    inline constexpr string_view RESET {"\033[m"};
    inline constexpr string_view RED {"\033[1;49;31m"};
    inline constexpr string_view GREEN {"\033[1;49;32m"};
    inline constexpr string_view YELLOW {"\033[1;49;33m"};
    inline constexpr string_view BLUE {"\033[1;49;34m"};
    inline constexpr string_view CYAN {"\033[1;49;35m"};
    inline constexpr string_view GRAY {"\033[1;49;90m"};
}

#endif