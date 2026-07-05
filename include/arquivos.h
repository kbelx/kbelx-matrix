/***********************************************************************************************************************
- AUTOR:        Bruno Costa ( aka Kbelx_ ) 
- DATA:         30/maio/2026>
***********************************************************************************************************************/

#ifndef ARQUIVOS_H
#define ARQUIVOS_H

    #include <filesystem>

    bool criarDiretorioRaiz(const std::filesystem::path& nome_diretorio);
    bool criarAudioFiles(const std::filesystem::path& nome_pasta);
    bool criarSessionFiles(const std::filesystem::path& nome_pasta);
    bool criarBouncedFiles(const std::filesystem::path& nome_pasta);
    bool criarMetadados(const std::filesystem::path& nome_pasta);

#endif
