# Define a function that computes the length of a given list or string.
# (It is true that Python has the len() function built in, but writing it
# yourself is nevertheless a good exercise.)

def length(seq):
    seq_length = 0
    for item in seq:
        seq_length += 1
    return seq_length

# test
print(length("TROLOLO"))