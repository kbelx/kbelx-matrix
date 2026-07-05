/***********************************************************************************************************************
- AUTOR:        Bruno Costa ( aka Kbelx_ ) 
- DATA:         30/maio/2026>
- PROPOSITO:    Arquivo que cria diretórios e seus subdiretórios
***********************************************************************************************************************/

#include <filesystem>
#include <string_view>
#include <system_error>
#include <fstream>

#include "arquivos.h"

namespace fs = std::filesystem;

namespace AF {
    constexpr std::string_view nome_principal {"01_AUDIO_FILES"};
    constexpr std::string_view pasta_1 {"RECORD"};
    constexpr std::string_view pasta_2 {"SAMPLES"};
}

namespace SF {
    constexpr std::string_view nome_principal {"02_SESSION_FILES"};
    constexpr std::string_view pasta_1 {"PRODUCER_SESSION"};
    constexpr std::string_view pasta_2 {"MIX_SESSION"};
    constexpr std::string_view pasta_3 {"MASTER_SESSION"};
}

namespace BF {
    constexpr std::string_view nome_principal {"03_BOUNCED_FILES"};
    constexpr std::string_view pasta_1 {"STEMS"};
    constexpr std::string_view pasta_2 {"MIXING_EXPORTS"};
    constexpr std::string_view pasta_3 {"MASTERING_EXPORTS"};
    constexpr std::string_view pasta_4 {"INSTRUMENTAL"};
    constexpr std::string_view pasta_5 {"OBSOLETE"};
}


bool criarDiretorioRaiz(const fs::path& nome_diretorio) {
    std::error_code erro {};
    fs::create_directories(nome_diretorio, erro);

    // Se houve erro e não é porque a pasta já existe
    if (erro) return false;
        
    // Confirma que é um diretório (e não um arquivo com o mesmo nome)
    return fs::is_directory(nome_diretorio);
}


// cria a pasta AUDIO FILES e seus subgrupos
bool criarAudioFiles(const fs::path& nome_pasta){

    std::error_code erro {};

    fs::create_directories(nome_pasta / AF::nome_principal / AF::pasta_1, erro);
    fs::create_directories(nome_pasta / AF::nome_principal / AF::pasta_2, erro);

    return !erro;
}


// cria a pasta SESSION FILES e seus subgrupos
bool criarSessionFiles(const fs::path& nome_pasta){

    std::error_code erro {};

    fs::create_directories(nome_pasta / SF::nome_principal / SF::pasta_1, erro);
    fs::create_directories(nome_pasta / SF::nome_principal / SF::pasta_2, erro);
    fs::create_directories(nome_pasta / SF::nome_principal / SF::pasta_3, erro);

    return !erro;
}


// cria a pasta BOUNCED FILES e seus subgrupos
bool criarBouncedFiles(const fs::path& nome_pasta){

    std::error_code erro {};

    fs::create_directories(nome_pasta / BF::nome_principal / BF::pasta_1, erro);
    fs::create_directories(nome_pasta / BF::nome_principal / BF::pasta_2, erro);
    fs::create_directories(nome_pasta / BF::nome_principal / BF::pasta_3, erro);
    fs::create_directories(nome_pasta / BF::nome_principal / BF::pasta_4, erro);
    fs::create_directories(nome_pasta / BF::nome_principal / BF::pasta_5, erro);

    return !erro;
}


bool criarMetadados(const fs::path& nome_pasta) {
    fs::path caminho = nome_pasta / "metadados.txt";
    std::ofstream arquivo(caminho);
    if (!arquivo.is_open()) return false;
    
    arquivo << "============================================================\n"
            << "\t\t\t\t\tMETADADOS DO PROJETO \n"
            << "============================================================\n\n"
            << "TÍTULO:      [Nome da Obra / Álbum / Single]\n"
            << "AUTOR(ES):   [Compositor, Produtor, Artistas]\n"
            << "GÊNERO:      [Estilo Musical]\n"
            << "DATA:        [DD/MM/AAAA]\n\n"
            << "------------------------------------------------------------\n"
            << "COMENTÁRIOS E NOTAS:\n"
            << "> \n"
            << "> \n"
            << "> \n\n"
            << "------------------------------------------------------------\n"
            << "SPECS TÉCNICAS:\n"
            << "   Sample Rate: [ex: 48kHz] | Bit Depth: [ex: 24-bit]\n"
            << "   BPM: [000]               | Key: [ex: Am]\n"
            << "============================================================\n";
    return true;
}
