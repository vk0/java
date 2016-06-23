# Напишите функцию NA.counter для подсчета пропущенных значений в векторе.

# На вход функция  NA.counter должна принимать один аргумент - числовой вектор. Функция должна возвращать количество пропущенных значений.

# > my_vector <- c(1, 2, 3, NA, NA)
# > NA.counter(my_vector)
# [1] 2

# Sample Input:

# 34.900 -18.046 6.994 24.734 3.249 -43.119 25.954 36.096 -19.827 14.983 -10.751 12.178 -6.868 -23.513 -14.366 -1.462 -6.085 -22.345 -2.335 22.852 NA 14.977 -3.021 -21.733 22.490 NA NA 19.240 NA 6.078 NA -52.255 5.768 25.386 16.266 NA NA -43.957 NA NA

# Sample Output:

# 9

# NA.counter <- function(x){
#   count <- 0
#   for (j in 1:length(x))
#   {
#     if (is.na(x[j]))
#     {
#       count <- count + 1
#     }
#   }
#   return(count)
# }

NA.counter <- function(x){
  return(sum(is.na(x)))
}

my_vector <- c(1, 2, 3, NA, NA, NA)
NA.counter(my_vector)