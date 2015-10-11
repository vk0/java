import sys

__author__ = 'luckyman'
filename = sys.stdin.readline()
if filename:
    fileString = open(filename.strip(), "r")
    for line in fileString.readlines():
        stat = {}
        for symbol in line:
            if symbol.strip():
                if symbol in stat:
                    stat[symbol]["count"] += 1
                else:
                    stat[symbol] = {
                        "symbol" : symbol,
                        "count"  :  1
                    }
        mas=[]
        val = sorted(stat.values(),key = lambda obj:obj["count"], reverse=True)
        for key in val:
            mas.append(key["symbol"] + str(key["count"]))
        print mas

  