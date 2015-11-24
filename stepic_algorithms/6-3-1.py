import sys

def fractional_knapsack(capacity, values_and_weights):
    return 0

def main():
    reader = (tuple(map(int, line.split())) for line in sys.stdin)
    n, capacity = next(reader)
    values_and_weights = list(reader)
    assert len(values_and_weights) == n
    opt_value = fractional_knapsack(capacity, values_and_weights)
    print("{:.3f}".format(opt_value))

if __name__ == "__main__":
    main()