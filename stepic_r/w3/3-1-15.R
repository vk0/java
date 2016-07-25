# Постройте scatterplot по данным iris, сохранив его в переменную my_plot :
# Ось X - переменная Sepal.Width
# Ось Y -  переменная Petal.Width
# Цвет точек - переменная Species
# Также добавьте сглаживание для каждой группы наблюдений по переменной Species.

# Если Вы все сделали правильно должен получиться следующий график:
# https://ucarecdn.com/a49accdd-e1ab-41e3-bc68-30437ba7eeb9/

# Пожалуйста, сохраняйте график в переменную my_plot.

library(ggplot2)
my_plot <- ggplot(iris, aes(Sepal.Width,Petal.Width,  color = Species))+
  geom_point(size = 5)+
  geom_smooth()
