# Какие из указанных ниже множеств являются декартовым произведением множеств A×B, где A = {3, 5} и B = {1, 2}?

# (3, 1) (3, 2) (5, 1) (5, 2)


import itertools
somelists = [[3,5],[1, 2]]
somelists1 = [[5,3],[1, 2]]
for element in itertools.product(*somelists):
    print element,

for element in itertools.product(*somelists1):
    print element,