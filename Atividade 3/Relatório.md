# Dados Coletados e Estruturados para Relatório

* Arquitetura: AMD Ryzen 7 5700X com frequência de clock 3.4/4.6GHz (8 CPU Cores - 16 Threads), 32GB de RAM, L1 512KB, L2 4MB, 32MB.

* Escolher Dois Programas CLBG em https://benchmarksgame-team.pages.debian.net/benchmarksgame/:

  * Descrição dos dois programas: https://benchmarksgame-team.pages.debian.net/benchmarksgame/description/pidigits.html#pidigits

  * Primeiro Programa: https://benchmarksgame-team.pages.debian.net/benchmarksgame/program/pidigits-gcc-1.html

  * Segundo Programa: https://benchmarksgame-team.pages.debian.net/benchmarksgame/program/pidigits-gcc-2.html

> Observação importante: para rodar os códigos, foi necessário compilar com a flag -lgmp, de modo que incluisse a biblioteca gmp.h.

* Compilar sem nenhuma flag de otimização e depois com todas as opções de otimização: os comandos de prompt foram automatizados no arquivo script.sh e execution.sh para coletar resultados de tamanho dos executáveis e os tempos de compilação e de execução.

* Comparar os resultados em termos de tempo de execução do código, tempo de compilação e tamanho do executável:

  * Não houve alteração no tamanho médio dos arquivos em todas as 10 execuções. Foram elaborados dois gráficos: um para a comparação do tamanho de todos os arquivos (estilo exigido pela atividade) e outro que compara o tamanho do codigo 1 e do codigo 2 (por meio de um gráfico de linha). As imagens estão na pasta Analises arquivos comparacao_tamanho_codigo.png. No relatório final, seria interessante expor ambos os gráficos lado a lado para melhor comparação.

  * o tempo médio de compilação: resultados no diretorio de análises.

  * tempo médio de execução: resultados no diretório de análises.
