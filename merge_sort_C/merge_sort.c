#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"

void mergesort(int inicio, int fim, int v[])
{
  if (inicio < fim)
  {
    int meio = (inicio + fim)/2;
    mergesort(inicio, meio, v);
    mergesort(meio+1, fim, v);
    intercala(inicio, meio, fim, v);
  }
}

void intercala(int inicio, int meio, int fim, int v[])
{
  int tamanho = fim - inicio + 1;
  int *aux = malloc(tamanho * sizeof(int));
  int inicio_v01 = inicio, inicio_v02 = meio+1, poslivre=0;

  while (inicio_v01 <= meio && inicio_v02 <= fim)
  {
    if (v[inicio_v01] <= v[inicio_v02])  
      aux[poslivre++] = v[inicio_v01++];
    else  
      aux[poslivre++] = v[inicio_v02++];
  }
  while (inicio_v01 <= meio)  
    aux[poslivre++] = v[inicio_v01++];

  while (inicio_v02 <= fim)  
    aux[poslivre++] = v[inicio_v02++];

  for (inicio_v01 = inicio; inicio_v01 <= fim; inicio_v01++)  
    v[inicio_v01] = aux[inicio_v01-inicio];

  free(aux);
}
