def merge(lista, inicio, meio, fim):
    # Copia as duas metades que ja foram divididas recursivamente.
    esquerda = lista[inicio:meio]
    direita = lista[meio:fim]

    i = 0
    j = 0
    k = inicio

    # Intercala os elementos de volta na lista original.
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


def merge_sort(lista, inicio=0, fim=None):
    if fim is None:
        fim = len(lista)

    # Para sublistas com zero ou um elemento, nada precisa ser ordenado.
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
