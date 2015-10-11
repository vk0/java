__author__ = 'luckyman'

A = int(raw_input())
B = int(raw_input())
N = int(raw_input())

if (N > A and N > B) or (A == B and A != N) or (A % 2 == 0 and B % 2 == 0 and N % 2 != 0):
    print "Impossible"
elif A == N:
    print ">A"
elif B == N:
    print ">B"
else:
    maxSymbol, minSymbol, maxValue, minValue = ("A", "B", A, B) if A > B else ("B", "A", B, A)
    MAX = {
        "curValue": 0,
        "volume": maxValue,
        "fill": ">" + maxSymbol,
        "free": maxSymbol + ">",
        "merge": maxSymbol + ">" + minSymbol
    }
    MIN = {
        "curValue": 0,
        "volume": minValue,
        "fill": ">" + minSymbol,
        "free": minSymbol + ">",
        "merge": minSymbol + ">" + maxSymbol
    }

    if MAX["volume"] % MIN["volume"] == 0 and N % MIN["volume"] != 0:
        print "Impossible"
    else:
        if not N % MIN["volume"]:
            while MAX["curValue"] != N:
                MIN["curValue"] = MIN["volume"]
                print MIN["fill"]

                MAX["curValue"] += MIN["curValue"]
                MIN["curValue"] = 0
                print MIN["merge"]
        else:
            modN = N % MIN["volume"]
            modMax = MAX["volume"] % MIN["volume"]
            if modN == modMax:
                MAX["curValue"] = MAX["volume"]
                print MAX["fill"]
                while MAX["curValue"] != N:
                    if MIN["curValue"]:
                        MIN["curValue"] = 0
                        print MIN["free"]

                    MAX["curValue"] -= MIN["volume"]
                    MIN["curValue"] = MIN["volume"]
                    print MAX["merge"]

            else:
                commands = []
                while MIN["curValue"] != N or MAX["curValue"] != N:
                    while MAX["curValue"] + MIN["volume"] < MAX["volume"]:
                        if not MIN["curValue"]:
                            MIN["curValue"] = MIN["volume"]
                            commands.append(MIN["fill"])
                        MAX["curValue"] += MIN["curValue"]
                        MIN["curValue"] = 0
                        commands.append(MIN["merge"])
                        if MAX["curValue"] == N:
                            break
                    if MAX["curValue"] == N:
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
                    if MIN["curValue"] == N:
                        break

                    MAX["curValue"] = MIN["curValue"]
                    MIN["curValue"] = 0
                    commands.append(MAX["free"])
                    commands.append(MIN["merge"])
                if MAX["curValue"] != N and MIN["curValue"] != N:
                    print "Impossible"
                else:
                    for command in commands:
                        print command