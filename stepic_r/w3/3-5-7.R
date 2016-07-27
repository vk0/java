# Напишите функцию resid.norm, которая тестирует распределение остатков от модели на нормальность при помощи функции shapiro.test и создает гистограмму при помощи функции ggplot() с красной заливкой "red", если распределение остатков значимо отличается от нормального (p < 0.05), и с зелёной заливкой "green" - если распределение остатков значимо не отличается от нормального.

# На вход функция получает регрессионную модель. Функция возвращает переменную, в которой сохранен график ggplot.

# В поле для ответа не нужно создавать никаких дополнительных объектов, только напишите функцию  resid.norm.

# Пример работы функции:

# > fit <- lm(mpg ~ disp, mtcars)
# > my_plot <- resid.norm(fit)
# > my_plot
# https://ucarecdn.com/aa14c5a2-a9f4-4c0e-8596-56b9bac92c74/

# > fit <- lm(mpg ~ wt, mtcars)
# > my_plot <- resid.norm(fit)
# > my_plot
# https://ucarecdn.com/cfdea22e-f555-43b5-9388-b77d32a75a21/

# Для создания гистограммы при помощи функции ggplot требуется dataframe, где хранится переменная. Обратите внимание на такие функции как:

# data.frame()
# as.data.frame()

library(ggplot2)

resid.norm  <- function(fit){
  data <- data.frame(fit_v = fit$fitted.values,res = fit$residuals)
  test <- shapiro.test(data$res)
  color <- ifelse((test$p.value < 0.05),"red","green")

  plot <- ggplot(data, aes(x = res)) +
    geom_histogram(fill = color)
  return(plot)
}

fit <- lm(mpg ~ disp, mtcars)
my_plot <- resid.norm(fit)
my_plot

fit <- lm(mpg ~ wt, mtcars)
my_plot <- resid.norm(fit)
my_plot