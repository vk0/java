# Напишите функцию filtered.cor которая на вход получает data.frame с  произвольным количеством переменных (как количественными, так и любых других типов), рассчитывает коэффициенты корреляции Пирсона между всеми парами количественных переменных и возвращает наибольшее по модулю значение коэффициента корреляции. (То есть функция может вернуть -0.9, если это наибольшая по модулю  корреляция).

# Гарантируется наличие в data.frame хотя бы двух количественных переменных.

# Обратите внимание: при проверке вашей функции на вход будут подаваться данные с различными именами колонок. Ваша функция должна корректно работать независимо от имен переменных. Перед тем, как сдавать решение, убедитесь, что ваша функция работает корректно на разных данных, с разными именами колонок.

# Если вы хотите использовать функцию corr.test не забудьте загрузить библиотекy psych.

# Данные для тренировки:

# https://stepic.org/media/attachments/lesson/11504/step6.csv

# step6 <-  read.table("step6.csv",  header=TRUE, sep=',' )

# > filtered.cor(step6)

# [1] 0.235997


# > filtered.cor(my_df) #вымышленные данные, где максимальная по модулю корреляция отрицательна

# [1] -0.9



# > filtered.cor(iris)

# [1] 0.9628654


# > iris$Petal.Length <- -iris$Petal.Length # сделаем отрицательной максимальную по модулю корреляцию
# > filtered.cor(iris)

# [1] - 0.9628654

# * мы подробнее поговорим о функциях семейства apply в следующем курсе - Advanced R, но вы можете изучить справку о apply и sapply. Для решения данной задачи, эти функции могут пригодиться.

step6 <-  read.table("step6.csv",  header=TRUE, sep=',' )

nums <- sapply(step6, is.numeric)
head(step6[, nums])
r <- corr.test(head(step6[, nums]))
a <- r$r
which.max(a)
x <- c(1:4, 0:5)
which.min(x)
m <- max(abs(a[a!=1]))
k <- 0
for (mi in a){
if (mi == m){
  k <- k+1
}
}
if(k==2) print(m) else  print(m*(-1))
max(a, na.rm=TRUE)


# START_determination
library(psych)
filtered.cor <- function(x){
  nums <- sapply(x, is.numeric)
  a1 <- x[ , nums]
  r <- corr.test(a1)
  a <- r$r
  m <- max(abs(a[a!=1]))
  k <- 0
  for (mi in a){
    if (mi == m){
      k <- k+1
    }
  }

  if(k==2) return(m) else  return(m*(-1))
  }
filtered.cor(iris)
iris$Petal.Length <- -iris$Petal.Length