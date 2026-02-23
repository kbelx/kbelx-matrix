## Etapa 1 - Objetivos
_O que exatamente esse projeto deve fazer?_

**Resposta**: criar uma estrutura de diretórios automaticamente para projetos profissionais de produção musical.

---
## Etapa 2 - Requisitos
Olhar o arquivo `README.MD`

---
## Etapa 3 - as Ferramentas, Metas e Backup
Olhar o arquivo `README.MD`

---
## Etapa 4 - Dividir Problemas
```
main()
├─ 1. Solicitar nome do projeto
│  └─ 1.1 Validar nome informado
│
├─ 2. Diretório raiz
│  └─ 2.1 Verificar se já existe
│      ├─ Se NÃO existir → criar diretório
│      └─ Se existir → manter e continuar
│
├─ 3. Estrutura principal
│  └─ 3.1 Criar 3 pastas principais
│      └─ Para cada pasta:
│          ├─ Verificar se já existe
│          └─ Criar apenas se necessário
│
├─ 4. Subestrutura
│	├─ 4.1 Criar subpastas das 3 pastas principais
│   └─ Para cada subpasta:
│       ├─ Verificar se já existe
│       └─ Criar apenas se necessário
│
├─ 5. Metadados
│    ├─ 5.1 Verificar se metadados.txt já existe
│    ├─ Se NÃO existir → criar com template
│    └─ Se existir → manter arquivo
│
└─ 6. Finalização
	├─ 6.1 Validar execução geral
	├─ 6.2 Se houver erro → reportar claramente
	└─ 6.3 Se tudo ok → emitir resumo final
```

---
## Etapa 5 - Sequência de Eventos
olhar a etapa 4