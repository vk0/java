import sys

def fractional_knapsack(capacity, values_and_weights):
    order = [(v / w, w) for v, w in values_and_weights]
    order.sort(reverse=True)
    acc = 0
    for v_per_w, w in order:
        if w < capacity:
            acc += v_per_w * w
            capacity -= w
        else:
            acc += v_per_w * capacity
            break
    return acc

def main():
    reader = (tuple(map(int, line.split())) for line in sys.stdin)
    n, capacity = next(reader)
    values_and_weights = list(reader)
    assert len(values_and_weights) == n
    opt_value = fractional_knapsack(capacity, values_and_weights)
    print("{:.3f}".format(opt_value))

if __name__ == "__main__":
    main()