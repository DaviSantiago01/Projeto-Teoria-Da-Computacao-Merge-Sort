import csv
import os
import random
import statistics
import time

from merge_sort import merge_sort

RODADAS = 30

# Define os tamanhos de entrada usados na análise experimental.
tamanhos = [
    ("pequeno", 1000),
    ("medio", 10000),
    ("grande", 100000),
]


# Gera os vetores de entrada para melhor caso, caso médio e pior caso.
def gerar_vetor(tipo, n):
    if tipo == "melhor_caso":
        return list(range(n))
    elif tipo == "pior_caso":
        return list(range(n, 0, -1))
    else:
        return [random.randint(0, n * 10) for _ in range(n)]


# Executa o benchmark para todos os cenários e tamanhos definidos.
def rodar_testes():
    resultados = []

    for cenario in ["melhor_caso", "caso_medio", "pior_caso"]:
        for nome_tam, n in tamanhos:
            tempos = []

            for _ in range(RODADAS):
                # Cria um novo vetor para cada rodada antes de medir o tempo.
                vetor = gerar_vetor(cenario, n)

                t1 = time.perf_counter_ns()
                merge_sort(vetor)
                t2 = time.perf_counter_ns()

                tempos.append((t2 - t1) / 1e6)

            media = statistics.mean(tempos)
            desvio = statistics.stdev(tempos)

            resultados.append(
                {
                    "linguagem": "Python",
                    "cenario": cenario,
                    "tamanho": nome_tam,
                    "n": n,
                    "media_ms": round(media, 4),
                    "desvio_ms": round(desvio, 4),
                    "min_ms": round(min(tempos), 4),
                    "max_ms": round(max(tempos), 4),
                    "rodadas": RODADAS,
                }
            )

            print(f"  {cenario:<14} {nome_tam:<10} n={n:<7}  media={media:.4f} ms  desvio={desvio:.4f} ms")

    return resultados


# Salva os resultados consolidados em um arquivo CSV.
def salvar_csv(dados, caminho):
    # Garante que a pasta de resultados exista antes de salvar o arquivo.
    os.makedirs(os.path.dirname(caminho), exist_ok=True)

    with open(caminho, "w", newline="", encoding="utf-8") as f:
        writer = csv.DictWriter(f, fieldnames=dados[0].keys())
        writer.writeheader()
        writer.writerows(dados)

    print(f"\nSalvo em: {caminho}")


if __name__ == "__main__":
    random.seed(42)

    print("=" * 60)
    print("  BENCHMARK - Merge Sort (Python)")
    print("=" * 60)

    resultados = rodar_testes()

    pasta = os.path.dirname(os.path.abspath(__file__))
    csv_path = os.path.join(pasta, "..", "results", "python_results.csv")

    salvar_csv(resultados, csv_path)
    print("Pronto!")
