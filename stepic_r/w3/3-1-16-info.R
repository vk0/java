Памятка

cor.test(mtcars$mpg, mtcars$disp) # Расчет корреляции Пирсона

cor.test(~ mpg + disp, mtcars) # запись через формулу

cor.test(mtcars$mpg, mtcars$disp, method = "spearman") # Расчет корреляции Спирмена

cor.test(mtcars$mpg, mtcars$disp, method = "kendall") # Расчет корреляции Кендала

cor(iris[, -5]) # построение корреляционной матрицы

fit <- lm(mpg ~ disp, mtcars) # построение линейной регрессии

fit$coefficients # коэффициенты регрессии

fit$fitted.values # предсказанные значения зависимой переменной


При наличии одинаковых значений в переменных расчет непараметрических корреляций будет сопровождаться предупреждением о невозможности рассчитать точное значение p - value.

Если в ваших данных есть одинаковые наблюдения, но вы хотите рассчитать непараметрическую корреляцию, используйте функцию spearman_test  из пакета coin

library(coin)
spearman_test(~ mpg + disp, mtcars)


Обратите внимание на различия в графиках. То что в первом aes() будет распространяться на все слои. А то, что в aes() конкретного geom - только на него.

ggplot(mtcars, aes(mpg, disp, col = factor(am)))+
  geom_point()+
  geom_smooth()

ggplot(mtcars, aes(mpg, disp))+
  geom_point(aes(col = factor(am)))+
  geom_smooth()

ggplot(mtcars, aes(mpg, disp))+
  geom_point()+
  geom_smooth(aes(col = factor(am)))

