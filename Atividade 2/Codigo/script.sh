#!/bin/bash

gcc -o ord ord.c -pg
./ord
gprof ./ord gmon.out > saida.txt 
python3 gprof2dot.py -n0 -e0 saida.txt > saida.dot
dot -Tpng -o saida_grafo.png saida.dot