# Projeto de Teoria da Computação - Merge Sort

Projeto acadêmico da disciplina de Teoria da Computação com foco no algoritmo Merge Sort.

## Objetivo do Trabalho

O objetivo deste repositório é implementar o Merge Sort em Python e em C, medir o tempo de execução em diferentes cenários e comparar os resultados práticos com a complexidade teórica esperada.

## O que é o Merge Sort

O Merge Sort é um algoritmo de ordenação baseado na estratégia de divisão e conquista.

De forma resumida, ele funciona assim:

1. dividir a sequência original em duas partes menores;
2. aplicar o mesmo processo recursivamente em cada metade;
3. intercalar as partes já ordenadas para formar a sequência final.

Essa estratégia faz com que o algoritmo mantenha um comportamento previsível mesmo quando a ordem inicial dos dados muda.

## Comportamento Teórico Esperado

- Melhor caso: `Theta(n log n)`
- Caso médio: `Theta(n log n)`
- Pior caso: `Theta(n log n)`
- Espaço auxiliar: `O(n)`

Nesta parte teórica, o ponto principal é que o Merge Sort tende a crescer na ordem de `n log n`, independentemente do caso analisado. A etapa experimental do projeto existe para observar se os dados medidos seguem essa tendência.

## Como o Projeto Foi Organizado

O desenvolvimento foi dividido em etapas simples:

1. Primeiro, foi implementado o algoritmo Merge Sort em Python e em C.
2. Depois, foram criados os benchmarks para medir o tempo de execução em diferentes cenários e tamanhos de entrada.
3. Em seguida, os resultados passaram a ser salvos em arquivos CSV.
4. Por fim, os notebooks foram usados para ler os CSVs e gerar os gráficos da análise.

## Estrutura das Pastas

- `merge_sort_python/`: implementação do Merge Sort em Python e benchmark da linguagem.
- `merge_sort_c/`: implementação do Merge Sort em C e benchmark da linguagem.
- `results/`: arquivos CSV com os resultados medidos.
- `notebooks/`: notebooks usados para leitura dos CSVs e geração dos gráficos.
- `graphs/`: imagens PNG exportadas a partir dos notebooks.

## Como os Testes Foram Feitos

Os experimentos foram montados para comparar as duas implementações do mesmo algoritmo em condições equivalentes.

- Tamanhos de entrada:
  - pequeno: `n = 1000`
  - médio: `n = 10000`
  - grande: `n = 100000`
- Cenários analisados:
  - melhor caso: vetor já ordenado
  - caso médio: vetor aleatório
  - pior caso: vetor em ordem inversa
- Quantidade de execuções:
  - 30 rodadas por tamanho em cada cenário
- Medidas registradas:
  - tempo médio
  - desvio-padrão
  - tempo mínimo
  - tempo máximo

## Como Executar o Projeto

### Python

Para executar o exemplo simples do Merge Sort em Python:

```bash
python merge_sort_python/merge_sort.py
```

Para gerar o CSV de benchmark do Python:

```bash
python merge_sort_python/benchmark.py
```

### C

Compile os arquivos da implementação em C e depois execute o benchmark.

Exemplo com `gcc`:

```bash
gcc merge_sort_c/merge_sort.c merge_sort_c/benchmark.c -o merge_sort_c/benchmark -lm
./merge_sort_c/benchmark
```

No Windows, o executável gerado pode ser `benchmark.exe`.

## Onde Ficam os Resultados

- Os resultados numéricos ficam em `results/python_results.csv` e `results/c_results.csv`.
- Os gráficos são gerados pelos notebooks dentro de `notebooks/`.
- As imagens exportadas ficam salvas em `graphs/`.

## Papel dos Notebooks

Os notebooks foram separados para deixar a análise mais organizada:

- `notebooks/graficos_python.ipynb`
  - lê o CSV do Python e gera o gráfico por cenário da implementação em Python
- `notebooks/graficos_c.ipynb`
  - lê o CSV do C e gera o gráfico por cenário da implementação em C
- `notebooks/graficos_comparacao.ipynb`
  - compara Python e C no caso médio
  - compara os dados reais com a curva teórica `n log n`
