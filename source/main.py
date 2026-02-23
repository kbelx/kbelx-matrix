"""
                                                      
▄▄▄   ▄▄▄ ▄▄▄▄▄▄▄         ▄▄▄        ▄▄▄▄   ▄▄▄▄▄▄▄   
███ ▄███▀ ███▀▀███▄       ███      ▄██▀▀██▄ ███▀▀███▄ 
███████   ███▄▄███▀       ███      ███  ███ ███▄▄███▀ 
███▀███▄  ███  ███▄       ███      ███▀▀███ ███  ███▄ 
███  ▀███ ████████▀       ████████ ███  ███ ████████▀ 
                   ▄▄▄▄▄▄▄▄                           
                                                      
────────────────────────────────────────────────────────────────────────────────
PROJETO   : KB_LAB
ARQUIVO   : main.py
AUTOR     : Bruno Costa
CRIADO    : 2026-02-23
LICENÇA   : KB Tecnologias

────────────────────────────────────────────────────────────────────────────────
DESCRIÇÃO:
Núcleo principal da aplicação

────────────────────────────────────────────────────────────────────────────────
"""
def validar_nome(nome) -> bool:
    """
    Recebe um nome e verifica se é válido

    Args:
        nome (Unknow): nome do objeto
    
    Returns:
        bool: resultado da validação do nome
    """
    
    validar = False

    if isinstance(nome, str):
        # só tem espaços?
        if nome.isspace():
            pass

        else:
            # apenas letras ?
            if nome.isalpha():
                validar = True

            # apenas números ?
            elif nome.isnumeric():
                validar = True

            # Letras e Números ?
            elif nome.isalnum():
                validar = True
    else:
        pass

    return validar


    