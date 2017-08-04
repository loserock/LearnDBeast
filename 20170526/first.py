#!/bin/python

import sys
from math import log


def getCounter(t):
    seqNum = int(log((2 * t + 6) / 3.0, 2))
    restSeq = 2**(seqNum - 1) * 3 - 3
    currSeq = 2**(seqNum - 1) * 3
    t -= restSeq
    if t == 0:
        return 1
    else:
        return currSeq - t + 1


t = int(raw_input().strip())
print getCounter(t)
