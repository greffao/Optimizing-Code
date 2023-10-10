#!/bin/bash

gcc -o ord ord.c -pg
./ord
gprof ./ord gmon.out > saida.txt 
gprof2dot saida.txt > saida.dot
dot -Tpng -o saida_grafo.png saida.dot