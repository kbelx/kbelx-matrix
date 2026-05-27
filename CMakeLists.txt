#═══════════════════════════════════════════════════════════════════════════════
# 🧱 CONFIGURAÇÃO MÍNIMA DO CMAKE
# ------------------------------------------------------------------------------
# Define a versão mínima do CMake necessária para gerar o projeto.
# Garante compatibilidade com comandos e recursos usados neste arquivo.
cmake_minimum_required(VERSION 3.20)

#═══════════════════════════════════════════════════════════════════════════════
# 📦 DEFINIÇÃO DO PROJETO
# ------------------------------------------------------------------------------
# Nome do projeto e linguagem utilizada.
# O nome do executável final será o mesmo do projeto.
project(KB_LAB LANGUAGES CXX)

#═══════════════════════════════════════════════════════════════════════════════
# 🔢 CONFIGURAÇÕES DA LINGUAGEM C++
# ------------------------------------------------------------------------------
# Define o padrão da linguagem C++ utilizado no projeto.
# Aqui usamos C++23.
set(CMAKE_CXX_STANDARD 23)

# Obriga o compilador a respeitar exatamente o padrão definido acima.
# Se o compilador não suportar C++23, a configuração falha.
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#═══════════════════════════════════════════════════════════════════════════════
# 🐞 TIPO DE BUILD
# ------------------------------------------------------------------------------
# Define o tipo de build padrão.
# "Debug" habilita símbolos de depuração e desativa otimizações.
# Obs: funciona bem com Ninja/Make (geradores single-config).
set(CMAKE_BUILD_TYPE Debug)

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp"
)

#═══════════════════════════════════════════════════════════════════════════════
# 🚀 CRIAÇÃO DO EXECUTÁVEL
# ------------------------------------------------------------------------------
# Cria o target do executável usando o nome do projeto (PROJECT_NAME).
add_executable(${PROJECT_NAME})

#═══════════════════════════════════════════════════════════════════════════════
# 📄 ARQUIVOS FONTE (.cpp)
# ------------------------------------------------------------------------------
# Associa os arquivos de implementação (.cpp) ao executável.
# O uso de target_sources melhora a organização e facilita a manutenção.
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})

#═══════════════════════════════════════════════════════════════════════════════
# 📁 DIRETÓRIOS DE HEADERS (.hpp)
# ------------------------------------------------------------------------------
# Informa ao compilador onde procurar arquivos de cabeçalho (.hpp).
# Boa prática: headers ficam separados na pasta "include/".
target_include_directories(${PROJECT_NAME} PRIVATE include)

if (WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE user32)
endif()

#═══════════════════════════════════════════════════════════════════════════════
# 🚨 FLAGS DE COMPILAÇÃO (QUALIDADE DE CÓDIGO)
# ------------------------------------------------------------------------------
# Conjunto de warnings agressivos para forçar boas práticas em C++.
# Ideal para aprendizado e para evitar comportamentos indefinidos.

if (MSVC)
    # Visual Studio / MSVC
    target_compile_options(${PROJECT_NAME} PRIVATE
        /W4            # warnings altos
        /permissive-   # modo mais "padrão"
        /EHsc          # exceções C++ padrão
    )

else()
    # GCC / Clang (MSYS2 g++, clang, Linux, etc.)
    target_compile_options(${PROJECT_NAME} PRIVATE 
        -Wall                       # Avisos básicos do compilador
        -Wextra                     # Avisos adicionais (mais rigor)
        -Wconversion                # Alerta sobre conversões implícitas perigosas
        -Wsign-conversion           # Alerta sobre conversões signed/unsigned
        -pedantic-errors            # Segue o padrão C++ à risca (modo hardcore 😈)
        -fdiagnostics-color=always  # Mensagens de erro coloridas no terminal 🌈
    )
endif()

#═══════════════════════════════════════════════════════════════════════════════
# ▶️ TARGET "run" (WINDOWS) com fallback
# ------------------------------------------------------------------------------
# Target auxiliar para executar o programa após a compilação.
#
# Comportamento:
# - Abre um CMD externo (fora do VS Code)
# - Executa o binário gerado (independente do nome/pasta/configuração)
# - Mantém a janela aberta após a execução (/k)
#
# Execução:
# cmake --build . --target run
#
# Implementação:
# - Usa o PowerShell para iniciar um novo processo (Start-Process)
# - O CMD é aberto com o parâmetro /k para não fechar automaticamente
#
if (WIN32)
    add_custom_target(run
        COMMAND powershell -NoProfile -ExecutionPolicy Bypass -Command
        " $exe = Join-Path '${CMAKE_CURRENT_BINARY_DIR}' '${PROJECT_NAME}.exe'; \
          if (Get-Command wt.exe -ErrorAction SilentlyContinue) { \
              wt.exe nt -d '${CMAKE_CURRENT_BINARY_DIR}' cmd.exe /k \"\"$exe\"\"; \
          } else { \
              cmd.exe /k \"\"$exe\"\"; \
          } "
        DEPENDS ${PROJECT_NAME}
        VERBATIM
    )
elseif (APPLE)
    add_custom_target(run
        COMMAND open -a Terminal "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}"
        DEPENDS ${PROJECT_NAME}
    )
else()
    add_custom_target(run
        COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}
        DEPENDS ${PROJECT_NAME}
    )
endif()
