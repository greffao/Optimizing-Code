#!/usr/bin/zsh

# Coleta os dados de tempo de compilação
(time gcc -O0 -lgmp code1.c -o code1_0.ex) 2> compile.metrics
(time gcc -O1 -lgmp code1.c -o code1_1.ex) 2>> compile.metrics
(time gcc -O2 -lgmp code1.c -o code1_2.ex) 2>> compile.metrics
(time gcc -O3 -lgmp code1.c -o code1_3.ex) 2>> compile.metrics
(time gcc -Os -lgmp code1.c -o code1_s.ex) 2>> compile.metrics
(time gcc -O0 -lgmp code2.c -o code2_0.ex) 2>> compile.metrics
(time gcc -O1 -lgmp code2.c -o code2_1.ex) 2>> compile.metrics
(time gcc -O2 -lgmp code2.c -o code2_2.ex) 2>> compile.metrics
(time gcc -O3 -lgmp code2.c -o code2_3.ex) 2>> compile.metrics
(time gcc -Os -lgmp code2.c -o code2_s.ex) 2>> compile.metrics

# Coleta o tempo de execução dos executáveis para 10.000 digitos de pi
(time ./code1_0.ex 10000) 2> execution.metrics
(time ./code1_1.ex 10000) 2>> execution.metrics
(time ./code1_2.ex 10000) 2>> execution.metrics
(time ./code1_3.ex 10000) 2>> execution.metrics
(time ./code1_s.ex 10000) 2>> execution.metrics
(time ./code2_0.ex 10000) 2>> execution.metrics
(time ./code2_1.ex 10000) 2>> execution.metrics
(time ./code2_2.ex 10000) 2>> execution.metrics
(time ./code2_3.ex 10000) 2>> execution.metrics
(time ./code2_s.ex 10000) 2>> execution.metrics

# Coleta os dados de tamanho dos executáveis
ls -al > size_programs.metrics
