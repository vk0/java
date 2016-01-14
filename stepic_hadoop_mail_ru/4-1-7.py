# Реализуйте Combiner в задаче подсчета среднего времени, проведенного пользователем на странице.

# Mapper пишет данные в виде key / value, где key - адрес страницы, value - пара чисел, разделенных ";". Первое - число секунд, проведенных пользователем на данной странице, второе равно 1.

# Sample Input:

# www.facebook.com    100;1
# www.google.com  10;1
# www.google.com  5;1
# www.google.com  15;1
# stepic.org  60;1
# stepic.org  100;1

# Sample Output:

# www.facebook.com    100;1
# www.google.com  30;3
# stepic.org  160;2