#!/usr/bin/zsh

mkdir ../Resultados

# Coletando dados da execução 1
sudo ./execution.sh
sudo mkdir -p ../Resultados/1
sudo mv *.ex *.metrics ../Resultados/1

# Coletando dados da execução 2
sudo ./execution.sh
sudo mkdir -p ../Resultados/2
sudo mv *.ex *.metrics ../Resultados/2

# Coletando dados da execução 3
sudo ./execution.sh
sudo mkdir -p ../Resultados/3
sudo mv *.ex *.metrics ../Resultados/3

# Coletando dados da execução 4
sudo ./execution.sh
sudo mkdir -p ../Resultados/4
sudo mv *.ex *.metrics ../Resultados/4

# Coletando dados da execução 5
sudo ./execution.sh
sudo mkdir -p ../Resultados/5
sudo mv *.ex *.metrics ../Resultados/5

# Coletando dados da execução 6
sudo ./execution.sh
sudo mkdir -p ../Resultados/6
sudo mv *.ex *.metrics ../Resultados/6

# Coletando dados da execução 7
sudo ./execution.sh
sudo mkdir -p ../Resultados/7
sudo mv *.ex *.metrics ../Resultados/7

# Coletando dados da execução 8
sudo ./execution.sh
sudo mkdir -p ../Resultados/8
sudo mv *.ex *.metrics ../Resultados/8

# Coletando dados da execução 9
sudo ./execution.sh
sudo mkdir -p ../Resultados/9
sudo mv *.ex *.metrics ../Resultados/9

# Coletando dados da execução 10
sudo ./execution.sh
sudo mkdir -p ../Resultados/10
sudo mv *.ex *.metrics *.metrics ../Resultados/10