# Especificações de Funcionalidades - KB_LAB

## Feature: Geração da Estrutura de Pastas
- **Input**: Um nome de projeto em formato de `std::string` obtido via `std::cin`.
- **Regras de Validação**:
  - Não pode ser vazio.
  - Não pode conter caracteres de controle ASCII (<32).
  - No **Windows**: Não pode conter `\ / : * ? " < > |`, não pode terminar com espaço ou ponto, e não pode usar palavras reservadas (`CON`, `PRN`, `AUX`, `NUL`, `COM1-9`, `LPT1-9`).
  - Em **POSIX**: Não pode conter `/` ou caractere nulo `\0`.
- **Saída de Erro**: O usuário deve receber feedback visual do erro (Message box no Windows ou output direto no terminal em POSIX). O programa termina ou pede novamente o input (atualmente retorna código de erro).
- **Processamento**:
  - Tenta criar a pasta raiz com o nome especificado via `std::filesystem::create_directories`.
  - Se a pasta for gerada com sucesso, procede com a geração das 3 pastas principais (`01_AUDIO_FILES`, `02_SESSION_FILES`, `03_BOUNCED_FILES`) e suas subpastas de contexto.
  - Gera um arquivo `metadados.txt` com as meta-informações padrão em UTF-8.
- **Saída de Sucesso**: O usuário recebe feedback visual e uma notificação de sucesso com o nome do projeto (via console ou Message Box dependendo do SO).
