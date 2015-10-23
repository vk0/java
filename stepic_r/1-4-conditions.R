# control statements

mydata <- read.csv('evals.csv')



# if

a <- 

if (a > 0){
  print('positive')
} else {
  print('not positive')
}


if (a > 0){
  print('positive')
} else print('not positive')


if (a > 0){
  print('positive')
} else if (a < 0) {
  print('negative')
} else print('zero')



# ifelse

a <- 10


ifelse(a > 0, 'positive', 'not positive')

a <- c(1, -1)


# for 

for (i in 1:100){
  print(i)
}


for (i in 1:nrow(mydata)){
  print(mydata$score[i])
}



# for + if
for (i in 1:nrow(mydata)){
  if (mydata$gender[i] == 'male'){
    print(mydata$score[i]) 
  }
}



# for + if  VS  ifelse

mydata$quality <- rep(NA, nrow(mydata))

for (i in 1:nrow(mydata)){
  if (mydata$score[i] > 4){
    mydata$quality[i] <- 'good'
  } else mydata$quality[i] <- 'bad'
}






mydata$quality2 <- ifelse(mydata$score > 4, 'good', 'bad')







# while

i <- 1

while(i < 51){
  print(mydata$score[i])
  i <- i+1
}





