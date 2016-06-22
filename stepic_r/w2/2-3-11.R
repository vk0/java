# Проведите однофакторный дисперсионный анализ на встроенных данных iris. Зависимая переменная - ширина чашелистика (Sepal.Width), независимая переменная - вид (Species). Затем проведите попарные сравнения видов. Какие виды статистически значимо различаются по ширине чашелистика?

# *virginica и setosa
# *versicolor и setosa
# *virginica и versicolor

df <- iris
fit <- aov(Sepal.Width ~ Species, data=df)
TukeyHSD(fit)