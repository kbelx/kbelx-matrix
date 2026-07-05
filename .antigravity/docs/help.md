## 1 - Pasta /context
Esta é a sua biblioteca de "conhecimento estendido". O agente vai consultar esses arquivos sempre que precisar entender o panorama geral.

### O que colocar aqui:

- ``style_guide.md``: Definições de padrões de código que você segue ( _ex: convenções de nomes, uso de comentários, estrutura de classes_ ).

- ``project_roadmap.md``: Um arquivo mantido com o que já foi feito e o que está por vir.

- ``tech_stack.md``: Um resumo técnico ( _ex: "Estamos usando Python 3.12 com Typer e Firebase"_ ).

Como otimizar: Sempre que iniciar uma sessão no CLI, você pode dizer:

*"Considere todos os arquivos dentro de .antigravity/context como base para as nossas decisões de implementação."*

---

## 2 - Pasta /spec
Esta pasta serve para definir as regras de negócio e comportamento. É aqui que o agente vai buscar "o que deve ser feito" antes de escrever qualquer código.

### O que colocar aqui:

- ``feature_specs.md``: Definição detalhada de cada nova funcionalidade ( _input, saída, lógica de erro_ ).

- ``api_contract.md``: Se estiver fazendo o seu projeto de CLI ( _como o Pebbl ), coloque aqui o esquema de comandos e respostas esperadas.

- ``test_cases.md``: Cenários de teste que o agente deve validar antes de te entregar o código final.

Como otimizar: Quando você pedir uma funcionalidade nova, aponte para o spec:

*"Implemente a funcionalidade X seguindo a especificação descrita em .antigravity/spec/feature_specs.md."*