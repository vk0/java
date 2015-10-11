import decimal

__author__ = 'luckyman'


def calculatePI(nStart, nStop, prec = 100):
    print nStart, nStop, prec , "start"
    decimal.getcontext().prec = prec
    xn = decimal.Decimal("0.0")
    summa = xn
    n = decimal.Decimal(nStart)
    z = 1
    if n % 2:
        z = -1
    while n < nStop:
        xn = 4 * z / ( 2*n + 1)
        n = n + decimal.Decimal(1)
        summa += xn
        z *= -1
    print nStart, nStop, prec , "end"
    return summa

  