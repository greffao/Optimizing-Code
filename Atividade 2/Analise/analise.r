# Carregar as bibliotecas
library(dplyr)
library(knitr)

# Pegando os dados e dividindo em algoritmos
dados <- read.csv("/home/greff/Desktop/Optimizing-Code/Atividade 2/Analise/resultados2.csv")
algoritmos <- split(dados, dados$Name)

# Funcao que calcula o intervalo de confianca a partir da tabela t-student 
# (amostras com menos de 30 elementos)
calcula_intervalo_confianca <- function(dados) {
  media <- mean(dados$Self_Seconds)
  desvio_padrao <- sd(dados$Self_Seconds)
  tamanho_amostra <- length(dados$Self_Seconds)
  nivel_confianca <- 0.95
  
  erro_padrao <- desvio_padrao / sqrt(tamanho_amostra)
  valor_critico_t <- qt((1 + nivel_confianca) / 2, df = tamanho_amostra - 1)
  
  limite_inferior <- media - valor_critico_t * erro_padrao
  limite_superior <- media + valor_critico_t * erro_padrao
  
  return(c(media, limite_inferior, limite_superior))
}

# Aplicando a funcao a cada algoritmo
resultados <- lapply(algoritmos, calcula_intervalo_confianca)

# Criando um df com os resultados
resultado_df <- data.frame(
  Algoritmo = names(resultados),
  Media = sapply(resultados, `[`, 1),
  Limite_Inferior = sapply(resultados, `[`, 2),
  Limite_Superior = sapply(resultados, `[`, 3)
)

# Imprimindo o df
kable(resultado_df, "markdown")
