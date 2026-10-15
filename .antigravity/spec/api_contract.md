# API Contract - kbelx-matrix

## Interação com CLI (Main Flow)

O projeto age como um CLI simples de única interação.

**Comando de Execução:**
```bash
./kbelx-matrix
```

**Esquema de Respostas (I/O)**:
1. **Prompt Inicial**:
   - Out: `Digite o nome do projeto: `
   - In: `<String>`

2. **Fluxo de Erro** (se invalido):
   - Out: 
     ```
     ╭──────────────────────────────────────────────╮
     │Sistema Operacional: Windows...               │
     │Status: ERRO                                  │
     ╰──────────────────────────────────────────────╯
     ```
   - E aciona a interface de alerta exibindo o motivo específico (Janela do Windows ou stdout dependendo do SO).
   - *Exit Code*: `1`

3. **Fluxo de Sucesso**:
   - Out:
     ```
     ╭──────────────────────────────────────────────╮
     │Sistema Operacional: Windows...               │
     │Status: SUCESSO                               │
     ╰──────────────────────────────────────────────╯
     ```
   - Alerta visual: `Pasta "[nome_projeto]" criada com sucesso.`
   - Aguarda input `std::cin.ignore()` para fechar a execução.
   - *Exit Code*: `0`
