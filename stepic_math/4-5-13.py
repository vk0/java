# -*- coding: utf-8 -*-
# Еще один интересный рекуррентный объект, родственный числам Фибоначчи,  —  числа Люка. Они задаются соотношением:
# Ln=Ln−1+Ln−2,L0=2,L1=1
# Решите это рекуррентное соотношение. Найдите сорок второе число Люка.

from time import sleep
from random import randint

print "Lucas Numbers"
print
sleep(randint(1,3))
input = input('How many terms do you want?: ')
print
input = int(input)
series = [2,1]
if input < 0:
  sleep(randint(1,3))
  print "Cannot execute, invalid number. Input should be a valid positive integer"
elif input == 1:
  print series[0]
elif input == 2:
  print series
else:
  for i in range(1,input-1):
    temp = series[i] + series[i-1]
    series.append(temp)
  sleep(randint(1,3))
  print "The series is: "
  print
  sleep(randint(1,3))
  print series
  print
sleep(randint(1,3))
print "Why is this awesome?"
print
sleep(randint(1,3))
print "The ratio of any two consecutive terms is always the Golden Ratio"
sleep(randint(1,3))
print "For example, from the series above, taking the last two terms"
lastterm = series[-1]
secondlastterm = series[-2]
sleep(randint(1,3))
print str(lastterm) + " by " + str(secondlastterm) + " is " + str(float(lastterm)/float(secondlastterm))
sleep(randint(1,3))
print "Which is almost equal to the Golden Ratio!"