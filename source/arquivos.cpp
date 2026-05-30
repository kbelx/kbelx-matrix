/***********************************************************************************************************************
- AUTOR:        Bruno Costa ( aka Kbelx_ ) 
- DATA:         30/maio/2026>
- PROPOSITO:    Arquivo que cria diretórios e seus subdiretórios
***********************************************************************************************************************/

#include <filesystem>
#include <system_error>

#include "arquivos.h"

namespace fs = std::filesystem;

bool criarDiretorioRaiz(const fs::path& nome_diretorio) {
    std::error_code erro {};

    if (fs::exists(nome_diretorio, erro)) {
        if (erro) {
            return false;
        }

        return fs::is_directory(nome_diretorio, erro) && !erro;
    }

    if (erro) {
        return false;
    }

    return fs::create_directories(nome_diretorio, erro) && !erro;
}

