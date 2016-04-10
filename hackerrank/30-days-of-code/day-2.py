# -*- coding: utf-8 -*-
# Objective
# In this challenge, you'll work with arithmetic operators. Check out the Tutorial tab for learning materials and an instructional video!

# Task
# Given the meal price (base cost of a meal), tip percent (the percentage of the meal price being added as tip), and tax percent (the percentage of the meal price being added as tax) for a meal, find and print the meal's total cost.

# Note: Be sure to use precise values for your calculations, or you may end up with an incorrectly rounded result!

# Input Format

# There are 33 lines of numeric input:
# The first line has a double, mealCostmealCost (the cost of the meal before tax and tip).
# The second line has an integer, tipPercenttipPercent (the percentage of mealCostmealCost being added as tip).
# The third line has an integer, taxPercenttaxPercent (the percentage of mealCostmealCost being added as tax).

# Output Format

# Print The total meal cost is totalCost dollars.The total meal cost is totalCost dollars., where totalCosttotalCost is the rounded integer result of the entire bill (mealCostmealCost with added tax and tip).

# Sample Input

# 12.00
# 20
# 8
# Sample Output

# The total meal cost is 15 dollars.
# Explanation

# Given:
# mealCost=12mealCost=12, tipPercent=20tipPercent=20, taxPercent=8taxPercent=8

# Calculations:
# tip=12×20100=2.4tip=12×20100=2.4
# tax=12×8100=0.96tax=12×8100=0.96
# totalCost=mealCost+tip+tax=12+2.4+0.96=15.36totalCost=mealCost+tip+tax=12+2.4+0.96=15.36
# round(totalCost)=15round(totalCost)=15
# We round totalCosttotalCost to the nearest dollar (integer) and then print our result:

# The total meal cost is 15 dollars.

mealCost = input()
tipPercent = input()
taxPercent = input()

tip = float(mealCost) * int(tipPercent)/100
tax = float(mealCost) * int(taxPercent)/100
totalCost = float(mealCost) + tip + tax
print("The total meal cost is " + str(round(totalCost)) + " dollars.")