# Используем знакомые нам данные mtcars.

# Нужно построить scatterplot с помощью ggplot из ggplot2, по оси x которого будет mpg, по оси y - disp, а цветом отобразить переменную (hp).

# Полученный график нужно сохранить в переменную plot1. Таким образом в ответе должен быть скрипт:

# plot1 <- ggplot(data, aes())+
#  geom_****()

data <- mtcars
plot1 <- ggplot(data, aes(x = mpg, y = disp, col = hp))+
    geom_point()