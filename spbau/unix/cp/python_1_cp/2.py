__author__ = 'luckyman'

def fillModulo(MAX, MIN, N, modulo, commands):
    if (modulo > MAX["volume"] and modulo > MIN["volume"]) or \
       (MAX["volume"] == MIN["volume"] and MAX["volume"] != modulo) or\
       (MAX["volume"] % 2 == 0 and MIN["volume"] % 2 == 0 and modulo % 2 != 0):
        return N
    elif MAX["volume"] == modulo:
        commands.append(MAX["fill"])
        MAX["curValue"] = MAX["volume"]
    elif MIN["volume"] == modulo:
        commands.append(MIN["fill"])
        MIN["curValue"] = MIN["volume"]
    else:
        if MAX["volume"] % MIN["volume"] == 0 and modulo % MIN["volume"] != 0:
            return
        else:
            if not modulo % MIN["volume"]:
                while MAX["curValue"] != modulo:
                    MIN["curValue"] = MIN["volume"]
                    commands.append(MIN["fill"])

                    MAX["curValue"] += MIN["curValue"]
                    MIN["curValue"] = 0
                    commands.append(MIN["merge"])
            else:
                modN = modulo % MIN["volume"]
                modMax = MAX["volume"] % MIN["volume"]

                if modN == modMax:
                    MAX["curValue"] = MAX["volume"]
                    commands.append(MAX["fill"])
                    while MAX["curValue"] != modulo:
                        if MIN["curValue"]:
                            MIN["curValue"] = 0
                            commands.append(MIN["free"])

                        MAX["curValue"] -= MIN["volume"]
                        MIN["curValue"] = MIN["volume"]
                        commands.append(MAX["merge"])

                else:
                    while MIN["curValue"] != modulo or MAX["curValue"] != modulo:
                        while MAX["curValue"] + MIN["volume"] < MAX["volume"]:
                            if not MIN["curValue"]:
                                MIN["curValue"] = MIN["volume"]
                                commands.append(MIN["fill"])
                            MAX["curValue"] += MIN["curValue"]
                            MIN["curValue"] = 0
                            commands.append(MIN["merge"])
                            if MAX["curValue"] == modulo:
                                break
                        if MAX["curValue"] == modulo:
                            break

                        if not MIN["curValue"]:
                            MIN["curValue"] = MIN["volume"]
                            commands.append(MIN["fill"])

                        delta = MAX["volume"] - MAX["curValue"]

                        if delta == MIN["volume"]:
                            break

                        MIN["curValue"] = MIN["curValue"] - delta
                        MAX["curValue"] = MAX["volume"]
                        commands.append(MIN["merge"])
                        if MIN["curValue"] == modulo:
                            break

                        MAX["curValue"] = MIN["curValue"]
                        MIN["curValue"] = 0
                        commands.append(MAX["free"])
                        commands.append(MIN["merge"])
    if MAX["curValue"] == modulo:
        commands.append(MAX["fillC"])
        N += MAX["curValue"]
    elif MIN["curValue"] == modulo:
        commands.append(MIN["fillC"])
        N += MIN["curValue"]
    return N

A = int(raw_input())
B = int(raw_input())
N = int(raw_input())

maxSymbol, minSymbol, maxValue, minValue = ("A", "B", A, B) if A > B else ("B", "A", B, A)
MAX = {
    "curValue": 0,
    "volume": maxValue,
    "fill": ">" + maxSymbol,
    "free": maxSymbol + ">",
    "merge": maxSymbol + ">" + minSymbol,
    "fillC": maxSymbol + ">C"
}
MIN = {
    "curValue": 0,
    "volume": minValue,
    "fill": ">" + minSymbol,
    "free": minSymbol + ">",
    "merge": minSymbol + ">" + maxSymbol,
    "fillC": minSymbol + ">C"
}
waterPool = 0
commands = []
if N > MAX["volume"]:
    while waterPool + MAX["volume"] < N :
        commands.append(MAX["fill"])
        commands.append(MAX["fillC"])
        waterPool += MAX["volume"]

modulo = N - waterPool
waterPool = fillModulo(MAX, MIN, waterPool, modulo, commands)
if waterPool != N:
    print "Impossible"
else:
    for command in commands:
        print command
