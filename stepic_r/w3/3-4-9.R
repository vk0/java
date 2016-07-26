# Напишите функцию normality.test, которая получает на вход dataframe с количественными переменными, проверяет распределения каждой переменной на нормальность с помощью функции shapiro.test. Функция должна возвращать вектор с значениями p - value, полученного в результате проверки на нормальность каждой переменной. Названия элементов вектора должны совпадать с названиями переменных.

# Пример работы функции:

# > normality.test(mtcars[,1:6])

#          mpg          cyl         disp           hp         drat           wt
# 1.228814e-01 6.058338e-06 2.080657e-02 4.880824e-02 1.100608e-01 9.265499e-02


# > normality.test(iris[,-5])

# Sepal.Length  Sepal.Width Petal.Length  Petal.Width
# 1.018116e-02 1.011543e-01 7.412263e-10 1.680465e-08


# Опять же, обратите внимание функция должна работать корректно с различным количеством переменных и в независимости от их названий.

# Подсказка. Как задать имена элементов вектора:

# > my_vector <- c(1, 2, 3, 4)

# > names(my_vector) <- c("A", "B", "C", "D")

# > my_vector

# A B C D
# 1 2 3 4


# * мы подробнее поговорим о функциях семейства apply в следующем курсе - Advanced R, но вы можете изучить справку о apply и sapply. Для решения данной задачи, эти функции могут пригодиться.

normality.test  <- function(x){
  vect_of_name <- apply(x, 1, names)
  a <- apply(x, 2, shapiro.test)

  for (i in 1:length(vect_of_name[,1])){
    res <- shapiro.test(x[,i])
    if (i == 1) {my_vec <- res$p.value}
    else{
      my_vec <- append(my_vec, res$p.value)
    }
  }
  names(my_vec) <- vect_of_name[,1]
  return(my_vec)
}

normality.test(mtcars[,1:6])
normality.test(iris[,-5])