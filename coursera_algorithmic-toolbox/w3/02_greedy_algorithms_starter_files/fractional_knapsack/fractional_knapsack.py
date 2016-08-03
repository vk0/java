# Uses python3
import sys
import itertools

def get_optimal_value(capacity, weights, values):
    value = 0.0
    val =[]
    for i in range(min(len(weights),len(values))):
        val.append([float(values[i]/(weights[i])),weights[i], values[i]])

    for i,w,v in sorted(val,key=lambda x:-x[0]):
        if capacity>0:
            if capacity-w>=0:
                value += v
                capacity-=w
            else:
                value += i*capacity

        return value

if __name__ == "__main__":
    data = list(map(int, sys.stdin.read().split()))
    n, capacity = data[0:2]
    values = data[2:(2 * n + 2):2]
    weights = data[3:(2 * n + 2):2]
    opt_value = get_optimal_value(capacity, weights, values)
    print("{:.10f}".format(opt_value))
