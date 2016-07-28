# Дополните предложенный в задании код, чтобы построить следующий график по данным ToothGrowth.
# Изобразите различия длины зубов морских свинок в различных условиях дозировки и типа потребляемого продукта.

# По оси x - переменная supp.
# По оси y - переменная len.
# Цвет ящиков с усами (boxplot) - переменная dose.

# Если все правильно, то должен получиться следующий график:

library("ggplot2")
ToothGrowth$dose <- as.factor(ToothGrowth$dose)
obj <- ggplot(data = ToothGrowth, aes(x = supp,y = len))
obj + geom_boxplot(aes(fill = dose))
