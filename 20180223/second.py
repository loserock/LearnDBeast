#!/bin/python

# Revised Russian Roulette (very easy task)
# https://www.hackerrank.com/contests/w36/challenges/revised-russian-roulette


import sys

def revisedRussianRoulette(doors):
    l = doors.split('0')
    maxUnlock = sum(map(len, l))
    minUnlock = sum([n/2 + n%2 for n in map(len, l)])
    return minUnlock, maxUnlock

if __name__ == "__main__":
    n = int(raw_input().strip())
    doors = raw_input().strip().replace(' ', '')
    result = revisedRussianRoulette(doors)
    print " ".join(map(str, result))

