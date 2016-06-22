# Вспомните графики из лекций и дополните шаблон графика в поле для ответа так (не добавляя еще один geom) , чтобы объединить линиями точки, принадлежащие разным уровням фактора supp. Не забудьте подключить нужный для построение графика пакет.
# Пожалуйста, сохраните график в переменную obj.

# Желаемый результат: https://ucarecdn.com/8e47f0ca-b605-40a2-b9e0-31027fe66bbd/

library(ggplot2)
df <- ToothGrowth
df$dose <- as.factor(df$dose)

pd = position_dodge(0.1)
obj <- ggplot(df, aes(x = dose, y = len, color = supp, group = supp)) +
stat_summary(fun.data = mean_cl_boot, geom = 'errorbar', width = 0.1, position = position_dodge(0.2))+
stat_summary(fun.data = mean_cl_boot, geom = 'point', size = 3, position = position_dodge(0.2))+
stat_summary(fun.data = mean_cl_boot, geom = 'line', position = position_dodge(0.2))