"""Implementacao didatica do algoritmo Merge Sort em Python.

O algoritmo ordena a propria lista recebida, dividindo o problema em
sublistas menores e depois intercalando as partes ja ordenadas.
"""


# Junta duas metades ja ordenadas e grava o resultado na lista original.
def merge(lista, inicio, meio, fim):
    # Copia as duas metades que serao intercaladas.
    esquerda = lista[inicio:meio]
    direita = lista[meio:fim]

    i = 0
    j = 0
    k = inicio

    # Compara os menores elementos de cada metade e grava o menor na lista original.
    while i < len(esquerda) and j < len(direita):
        if esquerda[i] <= direita[j]:
            lista[k] = esquerda[i]
            i += 1
        else:
            lista[k] = direita[j]
            j += 1
        k += 1

    # Copia os elementos restantes da metade esquerda, se houver.
    while i < len(esquerda):
        lista[k] = esquerda[i]
        i += 1
        k += 1

    # Copia os elementos restantes da metade direita, se houver.
    while j < len(direita):
        lista[k] = direita[j]
        j += 1
        k += 1


# Funcao principal do Merge Sort.
# Ela divide a lista em duas partes, ordena cada metade recursivamente
# e depois chama a intercalação final.
def merge_sort(lista, inicio=0, fim=None):
    # Na primeira chamada, o algoritmo considera a lista inteira.
    if fim is None:
        fim = len(lista)

    # Uma sublista com zero ou um elemento ja esta ordenada.
    if fim - inicio <= 1:
        return

    meio = (inicio + fim) // 2

    # Ordena recursivamente as metades esquerda e direita.
    merge_sort(lista, inicio, meio)
    merge_sort(lista, meio, fim)

    # Junta as duas metades ordenadas.
    merge(lista, inicio, meio, fim)


if __name__ == "__main__":
    lista = [8, 3, 5, 1, 4, 2]

    merge_sort(lista)

    print("Lista original:", [8, 3, 5, 1, 4, 2])
    print("Lista ordenada:", lista)
