import sys

def find_pos(xs, query):
    try:
        return xs.index(query) + 1
    except ValueError:
        return -1

def main():
    reader = (map(int, line.split()) for line in sys.stdin)
    n, *xs = next(reader)
    k, *queries = next(reader)
    for query in queries:
        print(find_pos(xs, query), end=" ")

if __name__ == "__main__":
    main()