#!/bin/bash

gcc -o ord ord.c -pg
./ord
gprof ./ord gmon.out > saida.txt 
python3 gprof2dot.py -n0 -e0 saida.txt > saida.dot
dot -Tpng -o saida_grafo.png saida.dot

./ord
gprof ./ord gmon.out > saida2.txt 
python3 gprof2dot.py -n0 -e0 saida2.txt > saida2.dot
dot -Tpng -o saida_grafo2.png saida2.dot

./ord
gprof ./ord gmon.out > saida3.txt 
python3 gprof2dot.py -n0 -e0 saida3.txt > saida3.dot
dot -Tpng -o saida_grafo3.png saida3.dot

./ord
gprof ./ord gmon.out > saida4.txt 
python3 gprof2dot.py -n0 -e0 saida4.txt > saida4.dot
dot -Tpng -o saida_grafo4.png saida4.dot

./ord
gprof ./ord gmon.out > saida5.txt 
python3 gprof2dot.py -n0 -e0 saida5.txt > saida5.dot
dot -Tpng -o saida_grafo5.png saida5.dot

./ord
gprof ./ord gmon.out > saida6.txt 
python3 gprof2dot.py -n0 -e0 saida6.txt > saida6.dot
dot -Tpng -o saida_grafo6.png saida6.dot

./ord
gprof ./ord gmon.out > saida7.txt 
python3 gprof2dot.py -n0 -e0 saida7.txt > saida7.dot
dot -Tpng -o saida_grafo7.png saida7.dot

./ord
gprof ./ord gmon.out > saida8.txt 
python3 gprof2dot.py -n0 -e0 saida8.txt > saida8.dot
dot -Tpng -o saida_grafo8.png saida8.dot

./ord
gprof ./ord gmon.out > saida9.txt 
python3 gprof2dot.py -n0 -e0 saida9.txt > saida9.dot
dot -Tpng -o saida_grafo9.png saida9.dot

./ord
gprof ./ord gmon.out > saida10.txt 
python3 gprof2dot.py -n0 -e0 saida10.txt > saida10.dot
dot -Tpng -o saida_grafo2.png saida10.dot
