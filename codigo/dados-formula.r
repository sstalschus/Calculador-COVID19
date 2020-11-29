library(readxl)
sintomas <- read_excel("~/coronavirus/sintomas06.06.2020.xls")
View(sintomas)
sintomas = sintomas[,c(1,3,6,11,28,29,30,31,33,35,38,42)]

## situação atual, 1 óbito, 0 c.c
sintomas$situacao_atual[sintomas$situacao_atual!="Óbito"] = 0
sintomas$situacao_atual[sintomas$situacao_atual=="Óbito"] = 1
sintomas$situacao_atual = factor(sintomas$situacao_atual, levels = c(0,1), labels = c("nao obito", "obito"))

## transofrmando sexo em fator, 1 masculino 0 feminino

sintomas$sexo[sintomas$sexo=="Mascuino"] = 1
sintomas$sexo[sintomas$sexo=="Masculino"] = 1
sintomas$sexo[sintomas$sexo=="Feminino"] = 0
sintomas$sexo = factor(sintomas$sexo, levels = c(0,1), labels = c("Feminino","Masculino"))

## mineracao idade

sintomas = sintomas[sintomas$idade > 0 & sintomas$idade < 120,]

## transformação doenca_cardiovascular

sintomas$doenca_cardiovascular[which(is.na(sintomas$doenca_cardiovascular))] = 0
sintomas$doenca_cardiovascular[sintomas$doenca_cardiovascular == "X"] = 1
sintomas$doenca_cardiovascular = factor(sintomas$doenca_cardiovascular, levels = c(0,1), labels = c("nao doenca cardiovascular","doenca cardiovascular"))

## transformação diabetes

sintomas$diabetes[which(is.na(sintomas$diabetes))] = 0
sintomas$diabetes[sintomas$diabetes == "X"] = 1
sintomas$diabetes = factor(sintomas$diabetes, levels = c(0,1), labels = c("nao diabetes","diabetes"))

## transformação doenca_respiratoria_cronica

sintomas$doenca_respiratoria_cronica[which(is.na(sintomas$doenca_respiratoria_cronica))] = 0
sintomas$doenca_respiratoria_cronica[sintomas$doenca_respiratoria_cronica == "X"] = 1
sintomas$doenca_respiratoria_cronica = factor(sintomas$doenca_respiratoria_cronica, levels = c(0,1), labels = c("nao doenca respiratoria cronica","doenca_respiratoria_cronica"))

## transformação hipertensao

sintomas$hipertensao[which(is.na(sintomas$hipertensao))] = 0
sintomas$hipertensao[sintomas$hipertensao == "X"] = 1
sintomas$hipertensao = factor(sintomas$hipertensao, levels = c(0,1), labels = c("nao hipertensao","hipertensao"))

## transformação idoso

sintomas$idoso[which(sintomas$idade<60)] = 0
sintomas$idoso[which(sintomas$idade>60)] = 1
sintomas$idoso = factor(sintomas$idoso, levels = c(0,1), labels = c("nao idoso","idoso"))

## transformação obesidade

sintomas$obesidade[which(is.na(sintomas$obesidade))] = 0
sintomas$obesidade[sintomas$obesidade == "X"] = 1
sintomas$obesidade = factor(sintomas$obesidade, levels = c(0,1), labels = c("nao obesidade","obesidade"))

## transformação asma

sintomas$asma[which(is.na(sintomas$asma))] = 0
sintomas$asma[sintomas$asma == "X"] = 1
sintomas$asma = factor(sintomas$asma, levels = c(0,1), labels = c("nao asma","asma"))

## transformação pneumopatia

sintomas$pneumopatia[which(is.na(sintomas$pneumopatia))] = 0
sintomas$pneumopatia[sintomas$pneumopatia == "X"] = 1
sintomas$pneumopatia = factor(sintomas$pneumopatia, levels = c(0,1), labels = c("nao pneumopatia","pneumopatia"))

## removendo NA

sintomas = sintomas[complete.cases(sintomas),]

## modelo de regressão logística

fit = glm(situacao_atual ~ sexo + idade + doenca_cardiovascular + diabetes + doenca_respiratoria_cronica + hipertensao + idoso + obesidade + asma,
          data = sintomas, family = binomial())
summary(fit)

## modelo de regressão logística, retirando doença cardiovascular que foi não significativo

fit = glm(situacao_atual ~ sexo + idade + diabetes + hipertensao + idoso + obesidade,
          data = sintomas, family = binomial())
summary(fit)


## probabilidade

attach(sintomas)
prob = 1/(1+exp(-1*(fit$coefficients[1] + fit$coefficients[2]*(as.numeric(sexo)-1) + fit$coefficients[3]*idade
                    + fit$coefficients[4](as.numeric(diabetes)-1) + fit$coefficients[5](as.numeric(hipertensao)-1) 
                    + fit$coefficients[6](as.numeric(idoso)-1) + fit$coefficients[7](as.numeric(obesidade)-1))))
sintomas = cbind(sintomas, prob)
sintomas[sintomas$situacao_atual=="obito",]