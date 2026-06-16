#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"

/* Funcao principal do Merge Sort.
   Ela divide o vetor em duas partes, ordena cada lado e depois intercala. */
void mergesort(int inicio, int fim, int v[])
{
  // Divide o vetor recursivamente ate chegar em partes de tamanho 1.
  if (inicio < fim)
  {
    int meio = (inicio + fim)/2;
    mergesort(inicio, meio, v);
    mergesort(meio+1, fim, v);
    intercala(inicio, meio, fim, v);
  }
}

/* Junta duas metades ja ordenadas em um vetor auxiliar
   e depois copia o resultado para o vetor original. */
void intercala(int inicio, int meio, int fim, int v[])
{
  // Cria um vetor auxiliar para armazenar a intercalação ordenada.
  int tamanho = fim - inicio + 1;
  int *aux = malloc(tamanho * sizeof(int));
  int inicio_v01 = inicio, inicio_v02 = meio+1, poslivre=0;

  // Compara os elementos das duas metades e copia o menor para o auxiliar.
  while (inicio_v01 <= meio && inicio_v02 <= fim)
  {
    if (v[inicio_v01] <= v[inicio_v02])  
      aux[poslivre++] = v[inicio_v01++];
    else  
      aux[poslivre++] = v[inicio_v02++];
  }

  // Copia os elementos restantes da primeira metade.
  while (inicio_v01 <= meio)  
    aux[poslivre++] = v[inicio_v01++];

  // Copia os elementos restantes da segunda metade.
  while (inicio_v02 <= fim)  
    aux[poslivre++] = v[inicio_v02++];

  // Devolve os valores ordenados para o vetor original.
  for (inicio_v01 = inicio; inicio_v01 <= fim; inicio_v01++)  
    v[inicio_v01] = aux[inicio_v01-inicio];

  free(aux);
}
