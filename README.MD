Esse foi o meu primeiro projeto do curso de sistemas de informação, foi desenvolvido em C e foi utilizada a biblioteca gráfica Allegro.

O Projeto é uma calculadora do vírus COVID-19, a calculadora calcula a probabilidade de óbito do paciente caso ele venha a contrair o vírus da COVID-19. O modelo utilizado para o calculo foi o de Regressão Logística, e os dados foram formulados no R. Como fonte foi utilizada uma amostragem de Alagoas do dia 06/06/2020 que continha 15.537 pacientes.

Para conhecer a execução, assista o link abaixo:
 - https://youtu.be/dEZyf03uDvI

Abaixo a fórmula:
 - 1/(1+exp(-1*(-7,09+0,4456*sexo(1 masculino, 0 feminino)+0,058*idade + 0,9866 * diabetes(1 tem diabetes, 0 não tem) + 0,9176 * hipertensao(1 tem hipertensao, 0 nao tem) + 0,5628 * idoso(1 se for idoso, 0 se não for) + 1,6053 * obesidade (1 se for obeso 0 se não for)))

 >> Esse calculo retorna o valor entre 0 e 1 pois o resultado da probabilidade só pode ser de 0 a 1

 Abaixo algumas considerações interessantes sobre o programa:

 > Regressão de logística é uma regressão não linear, ou seja a é possível prever o valor dessa variável resposta se é 0 ou 1

> Nela temos a variável resposta que no caso é a morte do paciente, ou seja 0 ou 1 

> O objetivo da regressão logística é prever a probabilidade de ocorrência da variável resposta baseada nas variáveis explicativas (Sexo, idade, diabetes, hipertensão, >60 anos, obesidade.)

> Essas foram as variáveis explicativa selecionadas ao nível de 99% de confiança estatística (isso foi possível prevê ao modelo de regressão, e essas variáveis explicativas explicam o resultado da variável resposta)

> O modelo de regressão foi feito no "R" que é uma tecnologia estatística.

> A média de probabilidade de morte das pessoas que morreram foi 15% de chances de morrer.

> A média dos pacientes que não morreram foi de 3% de chances de não morrer.

>> São infinitas combinações por eu não ter limitado a idade

- 44% das pessoas que receberam probabilidade 50% de morrer realmente morreram.

- %3 das pessoas que receberam probabilidade abaixo de 50% morreram.


