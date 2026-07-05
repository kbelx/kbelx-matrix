## 1 - CONTEXTO
Quero estar trabalhando com uma estrutura de "contexto persistente" e 
"especificações de projeto" ao utilizar o Antigravity CLI, o que é a maneira 
ideal de extrair o máximo do Antigravity CLI.

## 2 - STACK
na pasta ``.antigravity/context`` : Esta é a biblioteca de "conhecimento estendido". O agente vai consultar esses arquivos sempre que precisar entender o panorama geral.

- ``style_guide.md``: Definições de padrões de código que e u sigo (ex: convenções de nomes, uso de comentários, estrutura de classes).

- ``project_roadmap.md``: Um arquivo mantido com o que já foi feito e o que está por vir.

- ``tech_stack.md``: Um resumo técnico

---

na pasta ``.antigravity/spec`` : Esta pasta serve para definir as regras de negócio e comportamento. É aqui que o agente vai buscar "o que deve ser feito" antes de escrever qualquer código.

- ``feature_specs.md``: Definição detalhada de cada nova funcionalidade (input, saída, lógica de erro).

- ``api_contract.md``: esquema de comandos e respostas esperadas.

- ``test_cases.md``: Cenários de teste que o agente deve validar antes de entregar o código final.

## 3 - REQUISITOS
- Analisar todo o projeto e entregar as pastas "spec" e "context" completamente prontas

- criar uma pasta chamada "docs/" para armazenar detalhes dessa implementação.
