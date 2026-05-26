dados = [8522,12630,7453,6005,
         5874,6612,8439,7531,
         6430,4986]


rol = [5, 8, 10, 10, 12, 
       15, 18, 20, 20, 24, 
       25, 25, 25, 30, 38, 
       45, 52, 52, 60, 65, 
       70, 70, 79, 84, 90]

# Calcular a média: qual é o valor médio ?
def calcular_media(numeros: list) -> int:
    soma = 0
    tamanho_amostra = len(numeros)

    if tamanho_amostra == 0:
        return 0
    else:
        for num in numeros:
            soma = soma + num

        resultado = soma // tamanho_amostra

        return resultado
    

# Calcular a mediana: qual é o valor central ?
def calcular_mediana(numeros: list) -> int:
    tamanho_amostra = len(numeros)

    # se a amostra É IMPAR
    # fórmula: Emd = n + 1 / 2
    if tamanho_amostra % 2 == 1:
        resultado_impar = tamanho_amostra + 1 // 2
        return resultado_impar
    
    # se a amostra É PAR
    # fórmula (média aritmética): 
    # Em1 = n / 2
    # Em2 = n + 1 / 2
    # Md = Em1 + Em2 / 2
    else: 
        Md1 = tamanho_amostra // 2
        Md2 = tamanho_amostra + 1 // 2
        resultado_par = Md1 + Md2 // 2

        return resultado_par


# Calcular a mediana: qual valor mais se repete ?
def calcular_moda(numeros: list) -> list | int | str:

    # contar as frequências
    contagem = {}
    for n in numeros:
        if n in contagem:
            contagem[n] += 1
        else:
            contagem[n] = 1

    # qual é a maior frequência
    maior_frequencia = 0
    for valor in contagem.values():
        if valor > maior_frequencia:
            maior_frequencia = valor
    
    # quais números são a frequência máxima?
    modas = []
    for chave in contagem:
        frequencia_da_chave = contagem[chave]
        if frequencia_da_chave == maior_frequencia:
            modas.append(chave)

    # Se a maior frequência for 1, significa que ninguém se repetiu
    if maior_frequencia == 1:
        return "Conjunto Amodal"
    
    # Se houver apenas uma moda, retorna o número; se houver várias, retorna a lista
    if len(modas) == 1:
        return modas[0]
    else:
        return modas

print(calcular_media(dados))
#print(calcular_mediana(rol))
#print(calcular_moda(rol))
