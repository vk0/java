import decimal
from threading import Lock
from Config import portionSize, precision

__author__ = 'luckyman'


class ResultHolder:
    _lock = Lock()
    _currentN = 0
    def __init__(self):
        decimal.getcontext().prec = precision
        self._result = decimal.Decimal("0.0", decimal.Context(precision))

    def readResult(self):
        self._lock.acquire()
        try:
            return str(self._result)
        finally:
            self._lock.release()

    def addCalculatedPart(self, part):
        self._lock.acquire()
        try:
            decimal.getcontext().prec = precision
            self._result += decimal.Decimal(part)
        finally:
            self._lock.release()

    def getNextPortion(self):
        self._lock.acquire()
        start = self._currentN
        stop = self._currentN + portionSize
        self._currentN += portionSize
        try:
            return {
                "startN" : start,
                "stopN"  : stop,
                "prec"   : precision
            }
        finally:
            self._lock.release()

  