# Casos de Teste - kbelx-matrix

O agente deverá garantir a aprovação dos seguintes testes antes de finalizar novas entregas:

## Testes de Validação de Input
1. **Input Vazio**: Passar uma string vazia deve retornar alerta e impedir criação.
2. **Caracteres Especiais (Windows)**: String com `?` ou `<` no Windows deve falhar imediatamente.
3. **Caracteres Especiais (POSIX)**: String com `/` deve falhar imediatamente em ambos, mas regras do Windows são mais estritas.
4. **Finais de String (Windows)**: String terminada em espaço (`Projeto `) deve falhar.
5. **Nomes Reservados (Windows)**: Nomes como `CON` ou `LPT1` devem falhar.
6. **Input Válido**: `Mixagem_Artista_2026` deve prosseguir sem disparar validações.

## Testes de Criação de Sistema de Arquivos
1. **Criação de Raiz**: Garantir que a pasta no disco bate perfeitamente com a string de input após a aprovação de validação.
2. **Criação de Árvore Completa**: Garantir que o comando `criarBouncedFiles`, `criarSessionFiles` e `criarAudioFiles` concluem com código de sucesso.
3. **Escrita do Metadado**: O arquivo `metadados.txt` deve existir na raiz do projeto e possuir o cabeçalho "METADADOS DO PROJETO".
