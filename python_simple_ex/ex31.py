# Implement the higher order functions map(), filter() and reduce(). 
# (They are built-in but writing them yourself may be a good exercise.)

# map(func, *iterables) --> map object
def map(func, iterable):
    return [func(item) for item in iterable]

# filter(function or None, iterable) --> filter object
def filter(func, iterable):
    return [item for item in iterable if func(item)]

# 
def reduce(func, iterable):
    if len(iterable) == 2:
        return func(iterable[0], iterable[-1])
    else:
        return func(reduce(func, iterable[0:-1]), iterable[-1])

# test
numbers = [1, 2, 3, 4, 5]
print(map(lambda x: x * 2, numbers))
print(filter(lambda x: x > 3, numbers))
print(reduce(lambda x, y: x + y, numbers))
