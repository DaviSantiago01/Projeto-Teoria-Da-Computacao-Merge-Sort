#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "merge_sort.h"

#ifdef _WIN32
#include <windows.h>
#endif

#define RODADAS 30

#ifdef _WIN32
// Usa o contador de alta resolução do Windows para medir o tempo.
double tempo_atual_ns() {
    LARGE_INTEGER freq, cnt;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&cnt);
    return (double)cnt.QuadPart / (double)freq.QuadPart * 1e9;
}
#else
// Usa CLOCK_MONOTONIC em sistemas compatíveis com POSIX.
double tempo_atual_ns() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1e9 + ts.tv_nsec;
}
#endif

// Monta o vetor de entrada conforme o cenário do teste.
void preencher_vetor(int *v, int n, int tipo) {
    if (tipo == 0) {
        for (int i = 0; i < n; i++) v[i] = i;
    } else if (tipo == 1) {
        for (int i = 0; i < n; i++) v[i] = rand() % (n * 10);
    } else {
        for (int i = 0; i < n; i++) v[i] = n - i;
    }
}

int main() {
    srand(42);

    // Define os três tamanhos de entrada usados nos experimentos.
    int tam_entrada[] = {1000, 10000, 100000};
    char *nomes_tam[] = {"pequeno", "medio", "grande"};
    char *nomes_cenario[] = {"melhor_caso", "caso_medio", "pior_caso"};

    printf("==============================================================\n");
    printf("  BENCHMARK - Merge Sort (C)\n");
    printf("==============================================================\n\n");

#ifdef _WIN32
    CreateDirectoryA("..\\results", NULL);
#else
    system("mkdir -p ../results");
#endif

    FILE *arq = fopen("../results/c_results.csv", "w");
    if (!arq) {
        printf("Erro ao abrir arquivo csv\n");
        return 1;
    }
    fprintf(arq, "linguagem,cenario,tamanho,n,media_ms,desvio_ms,min_ms,max_ms,rodadas\n");

    // Percorre todos os cenários e tamanhos definidos para o experimento.
    for (int c = 0; c < 3; c++) {
        for (int t = 0; t < 3; t++) {
            int n = tam_entrada[t];
            double tempos[RODADAS];

            int *vetor = malloc(n * sizeof(int));

            for (int r = 0; r < RODADAS; r++) {
                // Gera um novo vetor antes de cada medição.
                preencher_vetor(vetor, n, c);

                double t1 = tempo_atual_ns();
                mergesort(0, n - 1, vetor);
                double t2 = tempo_atual_ns();

                tempos[r] = (t2 - t1) / 1e6;
            }
            free(vetor);

            // Calcula média, menor e maior tempo observados.
            double soma = 0, menor = tempos[0], maior = tempos[0];
            for (int r = 0; r < RODADAS; r++) {
                soma += tempos[r];
                if (tempos[r] < menor) menor = tempos[r];
                if (tempos[r] > maior) maior = tempos[r];
            }
            double media = soma / RODADAS;

            // Calcula o desvio-padrão amostral das rodadas.
            double sq = 0;
            for (int r = 0; r < RODADAS; r++) {
                double d = tempos[r] - media;
                sq += d * d;
            }
            double desvio = sqrt(sq / (RODADAS - 1));

            printf("  %-14s %-10s n=%-7d  media=%.4f ms  desvio=%.4f ms\n",
                   nomes_cenario[c], nomes_tam[t], n, media, desvio);

            fprintf(arq, "C,%s,%s,%d,%.4f,%.4f,%.4f,%.4f,%d\n",
                    nomes_cenario[c], nomes_tam[t], n, media, desvio, menor, maior, RODADAS);
        }
    }

    fclose(arq);
    printf("\nSalvo em: ../results/c_results.csv\n");
    printf("Pronto!\n");

    return 0;
}
