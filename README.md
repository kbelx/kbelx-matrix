# KB_LAB

## 1 - Funcionalidades
Script em **C++** para automatizar a criação da estrutura de pastas de novos projetos de Mixagem, Produção Musical e/ou Masterização.

- **Padronização:** Mantém todos os seus projetos com a mesma anatomia.
- **Rapidez:** Cria toda a hierarquia de diretórios em segundos.
- **Flexibilidade:** Fácil de adaptar para o seu workflow pessoal.

---
## 2 - Estrutura do Projeto
Atualmente, o repositório está organizado da seguinte forma:
```bash
KB_LAB/
│
├── doc/             # Documentação do projeto
│
├── include/         # Arquivos de cabeçalho ( .h )
│
├── source/          # Arquivoc de origem ( .cpp )
│
├── tests/           # Arquivos de testes
│
├── CMakeLists.txt   # Arquvio de projeto e compilação
│
└── README.md        # Briefing do projeto
```

---
## 3 - Estrutura de Pastas Gerada pelo Script
```powershell
/ 📂 NOME_DO_PROJETO
│
├── 📁 01_AUDIO_FILES            # Matéria-prima do projeto
│   ├── 🎤 RECORD                # Gravações originais ( RAW )
│   └── 🎹 SAMPLES               # Loops, One-shots e Sound Design
│
├── 📁 02_SESSION_FILES          # Arquivos de projeto ( DAW )
│   ├── 🛠️ PRODUCER_SESSION      # Sessão principal de produção/arranjo
│   ├── 🎚️ MIX_SESSION            # Sessão dedicada à mixagem
│   └── 💿 MASTER_SESSION        # Sessão dedicada à masterização
│
├── 📁 03_BOUNCED_FILES           # Exportações e entregáveis
│   ├── 📦 STEMS                 # Multitracks processadas/separadas
│   ├── 📻 MIXING_EXPORTS        # Pré-masters e versões de mix
│   ├── 🏁 MASTERING_EXPORTS     # Arquivos finalizados ( WAV/MP3 )
│   ├── 🎸 INSTRUMENTAL          # Versões sem voz/backing tracks
│   └── 🗑️ OBSOLETE              # Versões descartadas ou antigas
│
└── 📄 metadados.txt               # Informações técnicas e créditos
```

---
## 4 - Estrutura do Arquivo de Metadados
```txt
============================================================
					METADADOS DO PROJETO 
============================================================

TÍTULO:      [Nome da Obra / Álbum / Single]
AUTOR(ES):   [Compositor, Produtor, Artistas]
GÊNERO:      [Estilo Musical]
DATA:        [DD/MM/AAAA]

------------------------------------------------------------
COMENTÁRIOS E NOTAS:
   > 
   > 
   > 

------------------------------------------------------------
SPECS TÉCNICAS:
   Sample Rate: [ex: 48kHz] | Bit Depth: [ex: 24-bit]
   BPM: [000]               | Key: [ex: Am]
============================================================
```

---
## 5.1 - Estratégia de Branches
O projeto segue um modelo simples e eficiente de versionamento.

### Branches Principais
- ``main`` → sempre estável
- ``dev`` → branch de integração

### Branches de Desenvolvimento
Padrão:
```bash
feature/nome-da-feature
```

Exemplos:
```bash
feature/base-generator
feature/metadata-template
feature/cli-interface
feature/logging-system
```

---
## 5.2 - Devo criar uma branch só para documentação?

**Recomendação: NÃO.**

Documentação deve acompanhar a feature que ela descreve.

Ou seja:
- Se você cria uma nova funcionalidade → atualiza a documentação na mesma ``feature/``
- Depois faz merge para ``dev``

Criar uma ``docs/branch`` separada tende a:
- gerar conflitos desnecessários
- criar desalinhamento entre código e documentação

> [!success] Melhor prática
> documentação versionada junto com a feature.

---
## 5.3 - Fluxo de Trabalho
```BASH
main
  ↑
 dev
  ↑
feature/x
```

1. Criar branch a partir de ``dev``

2. Desenvolver

3. Merge em ``dev``

4. Quando estiver estável → merge ``dev`` → ``main``

---
## 6 - Organização de Commits
O projeto utiliza o padrão Conventional Commits.

|    Tipo    | Uso                 |
| :--------: | ------------------- |
|   `feat`   | Nova funcionalidade |
|   `fix`    | Correção de bug     |
| `refactor` | Refatoração         |
|   `docs`   | Documentação        |
|  `chore`   | Configuração        |
|   `test`   | Testes              |

**Exemplos**
```git
feat: add base folder tree generator
docs: update metadata template section
refactor: isolate directory creation logic
chore: initialize repository structure
```
Isso mantém o histórico limpo, legível e profissional.

---
## 7 - Requisitos

| Ferramentas | Versão |
| ----------- | ------ |
| C++         | 20     |
| Git         | 2.x    |

