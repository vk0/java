# -*- coding: utf-8 -*-
# Вам дана частичная выборка из датасета зафиксированных преступлений, совершенных в городе Чикаго с 2001 года по настоящее время.

# Одним из атрибутов преступления является его тип – Primary Type.

# Вам необходимо узнать тип преступления, которое было зафиксировано максимальное число раз в 2015 году.

# Файл с данными:
# Crimes.csv https://stepic.org/media/attachments/lesson/24473/Crimes.csv

# unix way
# cat module3/Crimes.csv |grep 2015|cut -d, -f6  | sort | uniq -c | sort -rn

# https://rstudio-pubs-static.s3.amazonaws.com/34540_21762762dd6247389fcb8689ef7f9e4c.html

import csv

fieldnames = ['ID','Case Number','Date','Block','IUCR','Primary Type','Description',
              'Location Description','Arrest','Domestic','Beat','District','Ward',
              'Community Area','FBI Code','X Coordinate','Y Coordinate','Year',
              'Updated On','Latitude','Longitude','Location']

csv_filename = "./Crimes.csv"
    # reader = csv.reader(f, delimiter=",")
    # for row in reader:
    #     print(row)
d = {}
with open(csv_filename) as csvfile:
    # the values in the first row of the csvfile will be used as the fieldnames (the keys for the dict)
    reader = csv.DictReader(csvfile, fieldnames)
    for row in reader:
        d[row['ID']] = row

crime_dict = d
crime_type_l = []
for crime_id in crime_dict:
    crime = crime_dict[crime_id]
    # print(crime)
    crime_type = crime['Primary Type']
    if crime_type not in crime_type_l:
        crime_type_l.append(crime_type)

print(crime_type_l)