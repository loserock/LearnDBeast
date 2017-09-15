def main():
    T = input()
    for i in xrange(T):
        N = raw_input()
        l = map(int, raw_input().split())
        r = [l[0]]
        for a, b in zip(l[:-1], l[1:]):
            v = max(a, b) if a % b == 0 or b % a == 0 else a * b
            r.append(v)
        r.append(l[-1])
        print " ".join(map(str, r))


main()
