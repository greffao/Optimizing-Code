
Compilacao Sem Vetorizacao
```
g++ semVetorizacao.cpp -o semVetorizacao
```

Compilacao Com Vetorizacao Pelo Compilador
```
g++ semVetorizacao.cpp -O3 -march=native -ftree-vectorize -o comVetorizacaoCompilador
```

Compilacao Com Vetorizacao Pelo Programador
```
g++ comVetorizacao.cpp -o comVetorizacao -march=native -mtune=native -mfpmath=sse -msse2
```