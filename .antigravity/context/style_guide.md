# Style Guide - kbelx-matrix

## 1. Padrão da Linguagem
- **C++23** (`CMAKE_CXX_STANDARD 23`).
- Sem extensões de compilador (`CMAKE_CXX_STANDARD_REQUIRED ON`).
- Compilação limpa com flags de aviso estritas (`/W4` no MSVC, `-Wall -Wextra -Wconversion -Wsign-conversion -pedantic-errors` no GCC/Clang).

## 2. Estrutura de Arquivos
- **include/**: Arquivos de cabeçalho (`.h`).
- **source/**: Arquivos de implementação (`.cpp`).
- Todos os cabeçalhos devem usar Header Guards tradicionais baseados no nome do arquivo (ex: `#ifndef ARQUIVOS_H`).

## 3. Nomenclatura
- **Variáveis Locais e Parâmetros**: `snake_case` (ex: `nome_projeto`, `nome_pasta`, `tamanho_convertido`).
- **Funções**: `camelCase` (ex: `solicitarNomeProjeto`, `criarDiretorioRaiz`, `validar_nomeProjeto`).
- **Namespaces**:
  - Gerais: PascalCase (ex: `SistemaOperacional`, `InterfaceErro`, `Cores`).
  - Siglas/Abreviados: ALL CAPS (ex: `AF`, `SF`, `BF`).
- **Constantes**: `ALL_CAPS` para arrays/caracteres especiais, ou `RESET`, `RED` dentro de namespaces de cores.

## 4. Codificação de Caracteres (Encoding)
- Arquivos de código-fonte salvos em **UTF-8**.
- Suporte nativo para UTF-8 no Windows usando conversão para UTF-16 (wide string / `MessageBoxW`) para exibição gráfica, e `SetConsoleOutputCP(CP_UTF8)` para o terminal.

## 5. Tratamento de Erros e Retorno
- Evitar uso de exceções (`try-catch`) para fluxos de validação e sistema de arquivos.
- Retornar `bool` para indicar sucesso ou fracasso (ex: `bool criarDiretorioRaiz`).
- Utilizar `std::error_code` da biblioteca `<system_error>` para validar chamadas de sistema (como criação de pastas no `std::filesystem`) sem lançar exceções.
