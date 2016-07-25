# Визуализируйте взаимодействие переменных wt и am, дополнив код, приведённый в задании:
# Ось x - переменная wt
# Ось y - переменная mpg
# Цвет регрессионных прямых - переменная am

# У вас должно получиться следующее изображение:
# https://ucarecdn.com/a6a5dc1e-8248-4b5a-82a8-57c85ec16ef5/

# Пожалуйста, сохраняйте график в переменную my_plot.

library(ggplot2)
df_numeric  <- mtcars
my_plot <- ggplot(df_numeric, aes(x = wt, y = mpg, col = am)) +
  geom_smooth(method = 'lm')