#! /usr/bin/env python
# coding=utf-8

from bisect import bisect_left, insort_left
from sys import argv


def main():
    if len(argv) > 1 and argv[1] == "-s":
        runWithSorting()
    else:
        runAlwaysOrdered()


def runAlwaysOrdered():
    n = int(raw_input().strip())
    names = []
    for a0 in xrange(n):
        op, contact = raw_input().strip().split(' ')
        if op == "add":
            insort_left(names, contact)
        elif op == "find":
            first = bisect_left(names, contact)
            if first == len(names):
                print 0
                continue
            last = bisect_left(names, contact + "{", first)
            print last - first


def runWithSorting():
    n = int(raw_input().strip())
    names = []
    n_sorted = True
    for a0 in xrange(n):
        op, contact = raw_input().strip().split(' ')
        if op == "add":
            names.append(contact)
            n_sorted = False
        elif op == "find":
            if not n_sorted:
                names.sort()
                n_sorted = True
            first = bisect_left(names, contact)
            if first == len(names):
                print 0
                continue
            last = bisect_left(names, contact + "{", first)
            print last - first


if __name__ == '__main__':
    main()
