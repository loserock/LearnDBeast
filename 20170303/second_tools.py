#! /usr/bin/env python
# coding=utf-8


def main():
    "The main function's description."
    xorray(40)


def xorray(i):
    c = 0
    j = 0
    while (j < i):
        j += 1
        c ^= j
        print j, c


if __name__ == '__main__':
    main()
