# # Big-O notation describes how quickly runtime will grow relative to the input as the input get arbitrarily large.
# # Let's examine some of these points more closely:
# # Remember, we want to compare how quickly runtime will grows, not compare exact runtimes, since those can vary depending on hardware.
# # Since we want to compare for a variety of input sizes, we are only concerned with runtime grow relative to the input. This is why we use n for notation.
# # As n gets arbitrarily large we only worry about terms that will grow the fastest as n gets large, to this point, Big-O analysis is also known as asymptotic analysis
# # As for syntax sum1() can be said to be O(n) since its runtime grows linearly with the input size. In the next lecture we will go over more specific examples of various O() types and examples. To conclude this lecture we will show the potential for vast difference in runtimes of Big-O functions.

# Big-O   Name
# 1   Constant
# log(n)  Logarithmic
# n   Linear
# nlog(n) Log Linear
# n^2 Quadratic
# n^3 Cubic
# 2^n Exponential

from math import log
import numpy as np
import matplotlib.pyplot as plt
%matplotlib inline
plt.style.use('bmh')

# Set up runtime comparisons
n = np.linspace(1,10,1000)
labels = ['Constant','Logarithmic','Linear','Log Linear','Quadratic','Cubic','Exponential']
big_o = [np.ones(n.shape),np.log(n),n,n*np.log(n),n**2,n**3,2**n]

# Plot setup
plt.figure(figsize=(12,10))
plt.ylim(0,50)

for i in range(len(big_o)):
    plt.plot(n,big_o[i],label = labels[i])


plt.legend(loc=0)
plt.ylabel('Relative Runtime')
plt.xlabel('n')