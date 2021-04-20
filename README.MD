<h1 align="center">
  COVID-19 Calculator
</h1>

<p align="center">
  <a href="#-Technologies">Technologies</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#-Project">Project</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#memo-Info">Info</a>
</p>

<p align="center">
 <img src="https://img.shields.io/static/v1?label=PRs&message=welcome&color=49AA26&labelColor=000000" alt="PRs welcome!" />

</p>

<br>



## 🚀 Technologies

This project was developed with the following technologies:

- C
- libAllegro
- R


## 💻 Project

This was my first project upon entering university, a COVID-19 calculator that calculates the probability of death for COVID-19 patients based on their comorbidity history. It can be found on youtube at the link: https://youtu.be/dEZyf03uDvI



## :memo: Info

This was my first project from the information systems course, it was developed in C and the graphic library Allegro was used.

The project is a calculator for the COVID-19 virus, the calculator calculates the probability of death of the patient in case he/she contracts the COVID-19 virus. The model used for the calculation was the Logistic Regression model, and the data was formulated in R. As a source a sample of Alagoas from 06/06/2020 that contained 15,537 patients was used.

Below is the formula:
 - 1/(1+exp(-1*(-7.09+0.4456*sex(1 male, 0 female)+0.058*age + 0.9866 * diabetes(1 has diabetes, 0 does not) + 0.9176 * hypertension(1 has hypertension, 0 does not) + 0.5628 * elderly(1 if elderly, 0 if not) + 1.6053 * obesity (1 if obese 0 if not)))

 >> This calculation returns a value between 0 and 1 because the probability result can only be from 0 to 1

 Here are some interesting considerations about the program:

 > Logistic regression is a non-linear regression, i.e. it is possible to predict the value of this response variable whether it is 0 or 1

> In it we have the response variable that in this case is the patient's death, that is, 0 or 1 

> The objective of the logistic regression is to predict the probability of occurrence of the response variable based on the explanatory variables (gender, age, diabetes, hypertension, >60 years, obesity.)

> These were the explanatory variables selected at the 99% statistical confidence level (this was possible by predicting the regression model, and these explanatory variables explain the outcome of the response variable)

> The regression model was made in "R" which is a statistical technology.

> The average probability of death of the people who died was 15% chance of dying.

> The average of the patients who didn't die had a 3% chance of not dying.

>> There are infinite combinations because I didn't limit the age

- 44% of the people who received a 50% chance of dying actually died.

- 3% of the people who received probability below 50% actually died.
