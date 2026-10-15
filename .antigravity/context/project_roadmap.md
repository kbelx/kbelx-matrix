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

---

## 🏷️ Histórico de Versões e Tags (SemVer)

| Tag | Commit | Descrição / Marco |
| :---: | :---: | :--- |
| `v1.1.0` | `main` | Rebranding oficial para `kbelx-matrix`, atualização do CMake target (`kbelx-matrix.exe`), docs, badges e política obrigatória de tags. |
| `v1.0.1` | `41a3440` | Ajuste de validações (remoção de bloqueio no console em erros) e inclusão de diagramas de fluxo arquiteturais v1.0.0. |
| `v1.0.0` | `7552b59` | Primeira versão estável (geração de pastas `01_AUDIO_FILES`, `02_SESSION_FILES`, `03_BOUNCED_FILES` e `metadados.txt`). |
| `v0.1.0` | `356099e` | Protótipo funcional inicial de validação e criação da pasta raiz em C++. |

> [!IMPORTANT]
> **Regra Obrigatória de Versionamento:** Qualquer novo marco estável incorporado à branch `main` DEVE sempre receber uma tag de versão SemVer correspondente (`git tag -a vX.Y.Z -m "..."`) e ser sincronizada com `git push origin --tags`.

