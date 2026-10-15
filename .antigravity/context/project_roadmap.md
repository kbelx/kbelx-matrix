# Project Roadmap - kbelx-matrix

## Fase Atual: 1.0 - Estrutura Base e Validações
- [x] Inicialização do repositório.
- [x] Criação da lógica C++ de geração de pastas (`01_AUDIO_FILES`, `02_SESSION_FILES`, `03_BOUNCED_FILES`).
- [x] Validação cross-platform de nomes de projetos (restrições do Windows e POSIX).
- [x] Geração automática do arquivo `metadados.txt`.
- [x] Configuração de Build com CMake (C++23) e target de execução customizado (`run`).
- [x] Documentação e especificações iniciais no contexto do Antigravity.

## Próximos Passos (To Do)
- [ ] Parametrização via CLI (ex: escolha de diferentes templates de projeto).
- [ ] Sistema de logs para salvar o histórico de criações de pastas.
- [ ] Cobertura completa de testes automatizados (unitários e e2e).
- [ ] Integração com templates de software (ex: cópia de templates nativos da DAW para a pasta).
