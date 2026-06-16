# Projeto de Teoria da Computacao - Merge Sort

Projeto academico da disciplina de Teoria da Computacao com foco no algoritmo Merge Sort.

## Objetivo do Trabalho

O objetivo deste repositorio e implementar o Merge Sort em Python e em C, medir o tempo de execucao em diferentes cenarios e comparar os resultados praticos com a complexidade teorica esperada.

## O que e o Merge Sort

O Merge Sort e um algoritmo de ordenacao baseado na estrategia de divisao e conquista.

De forma resumida, ele funciona assim:

1. dividir a sequencia original em duas partes menores;
2. aplicar o mesmo processo recursivamente em cada metade;
3. intercalar as partes ja ordenadas para formar a sequencia final.

Essa estrategia faz com que o algoritmo mantenha um comportamento previsivel mesmo quando a ordem inicial dos dados muda.

## Comportamento Teorico Esperado

- Melhor caso: `Theta(n log n)`
- Caso medio: `Theta(n log n)`
- Pior caso: `Theta(n log n)`
- Espaco auxiliar: `O(n)`

Nesta parte teorica, o ponto principal e que o Merge Sort tende a crescer na ordem de `n log n`, independentemente do caso analisado. A etapa experimental do projeto existe para observar se os dados medidos seguem essa tendencia.

## Como o Projeto Foi Organizado

O desenvolvimento foi dividido em etapas simples:

1. Primeiro, foi implementado o algoritmo Merge Sort em Python e em C.
2. Depois, foram criados os benchmarks para medir o tempo de execucao em diferentes cenarios e tamanhos de entrada.
3. Em seguida, os resultados passaram a ser salvos em arquivos CSV.
4. Por fim, os notebooks foram usados para ler os CSVs e gerar os graficos da analise.

## Estrutura das Pastas

- `merge_sort_python/`: implementacao do Merge Sort em Python e benchmark da linguagem.
- `merge_sort_c/`: implementacao do Merge Sort em C e benchmark da linguagem.
- `results/`: arquivos CSV com os resultados medidos.
- `notebooks/`: notebooks usados para leitura dos CSVs e geracao dos graficos.
- `graphs/`: imagens PNG exportadas a partir dos notebooks.

## Como os Testes Foram Feitos

Os experimentos foram montados para comparar as duas implementacoes do mesmo algoritmo em condicoes equivalentes.

- Tamanhos de entrada:
  - pequeno: `n = 1000`
  - medio: `n = 10000`
  - grande: `n = 100000`
- Cenarios analisados:
  - melhor caso: vetor ja ordenado
  - caso medio: vetor aleatorio
  - pior caso: vetor em ordem inversa
- Quantidade de execucoes:
  - 30 rodadas por tamanho em cada cenario
- Medidas registradas:
  - tempo medio
  - desvio-padrao
  - tempo minimo
  - tempo maximo

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

Compile os arquivos da implementacao em C e depois execute o benchmark.

Exemplo com `gcc`:

```bash
gcc merge_sort_c/merge_sort.c merge_sort_c/benchmark.c -o merge_sort_c/benchmark -lm
./merge_sort_c/benchmark
```

No Windows, o executavel gerado pode ser `benchmark.exe`.

## Onde Ficam os Resultados

- Os resultados numericos ficam em `results/python_results.csv` e `results/c_results.csv`.
- Os graficos sao gerados pelos notebooks dentro de `notebooks/`.
- As imagens exportadas ficam salvas em `graphs/`.

## Papel dos Notebooks

Os notebooks foram separados para deixar a analise mais organizada:

- `notebooks/graficos_python.ipynb`
  - le o CSV do Python e gera o grafico por cenario da implementacao em Python
- `notebooks/graficos_c.ipynb`
  - le o CSV do C e gera o grafico por cenario da implementacao em C
- `notebooks/graficos_comparacao.ipynb`
  - compara Python e C no caso medio
  - compara os dados reais com a curva teorica `n log n`
