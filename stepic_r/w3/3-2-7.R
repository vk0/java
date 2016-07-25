# Воспользуйтесь встроенным датасетом attitude, чтобы предсказать рейтинг (rating) по переменным complaints и critical. Каково t-значение для взаимодействия двух факторов?

# Разделителем целой и дробной части в ответе должна быть запятая!

dataset <- attitude
model <- lm(rating~critical*complaints, dataset) #mpg*disp*drat*hp
summary(model)