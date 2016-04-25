# # -*- coding: utf-8 -*-
# Let's dive into decorators! You are given NN mobile numbers. Sort them in ascending order then print them in the standard format shown below:


# +91 xxxxx xxxxx

# The given mobile numbers may have +91+91, 9191 or 00 written before the actual 1010 digit number. Alternatively, there may not be any prefix at all.

# Input Format

# The first line of input contains an integer NN, the number of mobile phone numbers.
# NN lines follow each containing a mobile number.

# Output Format

# Print NN mobile numbers on separate lines in the required format.

# Sample Input

# 3
# 07895462130
# 919875641230
# 9195969878
# Sample Output

# +91 78954 62130
# +91 91959 69878
# +91 98756 41230
# Concept

# Like most other programming languages, Python has the concept of closures. Extending these closures gives us decorators, which are an invaluable asset. You can learn about decorators in 12 easy steps here.
# To solve the above question, make a list of the mobile numbers and pass it to a function that sorts the array in ascending order. Make a decorator that standardizes the mobile numbers and apply it to the function.

phonelist =[input() for _ in range(int(input()))]

def phoneformat(func):
    def phonetoformat(phonelist):
        for i in range(len(phonelist)):
            phonelist[i] = '+91 ' + phonelist[i][-10:-5]  + ' ' + phonelist[i][-5:]

        func(phonelist)
    return phonetoformat

@phoneformat
def phone(phonelist):
    print('\n'.join(sorted(phonelist)))

phone(phonelist)