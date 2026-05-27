- Eu manteria a ``main`` como branch de **release estável**, não como branch de desenvolvimento.

### Estado atual do Git:

- branch atual: dev
- working tree: limpo
- dev: 5 commits à frente de origin/dev
- main: ainda está no commit inicial
- build: passando

---

### Minha recomendação:

  1. **Não publique isso na ``main`` ainda** se o objetivo do projeto é “criar estrutura de pastas para projetos musicais”, porque a funcionalidade principal ainda parece incompleta. Hoje você já tem entrada, validação, MessageBox, CMake e organização inicial, mas ainda não tem o fluxo final de criação das pastas/metadados.

  2. **Publique a ``dev`` no remoto agora**, porque ela já representa o estado atual do desenvolvimento:
  
```git
    git push origin dev
```

  3. Use a ``main`` só quando tiver **uma versão minimamente utilizável**, por exemplo:
  - pede nome do projeto;
  - valida nome;
  - cria diretório raiz;
  - cria subpastas;
  - gera metadados.txt;
  - build passa;
  - README explica como compilar e usar.

  Quando isso estiver pronto, aí sim:

```git
git checkout main
git merge dev
git push origin main
```

  Resumo direto: **publique ``dev`` agora; reserve ``main`` para releases**.