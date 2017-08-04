
############################################
# define and create roman number structures

R2I = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
CANPLACEDBEFORE = {'I': ['V', 'X'], 'X': ['L', 'C'], 'C': ['D', 'M']}
I2R = {1: 'I', 4: 'IV', 5: 'V', 9: 'IX', 10: 'X', 40: 'XL', 50: 'L', 90: 'XC',
       100: 'C', 400: 'CD', 500: 'D', 900: 'CM', 1000: 'M'}
RDIVS = sorted(I2R.keys(), reverse=True)

I2Ro = {1: 'I', 5: 'V', 10: 'X', 50: 'L', 100: 'C', 500: 'D', 1000: 'M'}
RDIVSo = sorted(I2Ro.keys(), reverse=True)
I2Re = I2Ro.copy()
for n, i in enumerate(RDIVSo):
    for j in RDIVSo[n:]:
        I2Re[i - j] = I2Ro[j] + I2Ro[i]
del I2Re[0]

RDIVSe = sorted(I2Re.keys(), reverse=True)

#############################################

###################
# config

ACCEPTEDEXTENDED = True

###################


def FromRoman(s):
    s = s.strip()
    value = 0
    for c in s:
        if c not in R2I.keys():
            return -1
    for i, c in enumerate(s):
        if i == len(s) - 1:
            nextC = None
        else:
            nextC = s[i + 1]
        if nextC and R2I[c] < R2I[nextC]:
            if not ACCEPTEDEXTENDED:
                if (c not in CANPLACEDBEFORE.keys()) or (nextC not in CANPLACEDBEFORE[c]):
                    return -1
                if (i < len(s) - 2) and (nextC in s[i + 2:]):
                    return -1
            value -= R2I[c]
        else:
            value += R2I[c]
    # if ACCEPTEDEXTENDED:
    #     i = 0
    #     decimals = []
    #     while i < len(s):
    #         if s[i:i+2] in I2Re.values():
    #             pass
    #             # TODO
    #         elif s[i] in R2I.keys():
    #             decimals.append(R2I[s[i]])
    #         else:
    #             return -1
    #     # TODO

    return value


def ToRomanCommon(i):
    i = int(i)
    roman = ""
    while i > 0:
        for rValue in RDIVS:
            if i >= rValue:
                roman += I2R[rValue]
                i -= rValue
                break
    return roman


def get_extended_roman_decreasing_order(i):
    for currKey in RDIVSe:
        if currKey <= i:
            yield currKey


def get_roman_from_decimal_list(l):
    return "".join([I2Re[i] for i in l])


class BestExtendedRomanIteration:

    def __init__(self, decimal):
        self.decimal = decimal
        self.__romanCommon = ToRomanCommon(decimal)
        self.__cBestLen = len(self.__romanCommon)
        self.__cBestDecimals = []

    def calculate(self):
        cache = []
        oBestLen = self.__cBestLen
        self.__iterate_extended_roman(self.decimal, cache, 0)
        if (len(self.__cBestDecimals) > 0) and (self.__cBestLen < oBestLen):
            return get_roman_from_decimal_list(self.__cBestDecimals)
        else:
            return self.__romanCommon

    def __iterate_extended_roman(self, iMax, decimals, cSum):
        for inPlace in get_extended_roman_decreasing_order(iMax - cSum):
            decimals.append(inPlace)
            cLen = len(get_roman_from_decimal_list(decimals))
            if cLen > self.__cBestLen:
                del decimals[-1]
                continue
            cSum = sum(decimals)
            if cSum < iMax:
                try:
                    self.__iterate_extended_roman(iMax, decimals, cSum)
                except:
                    print "ERROR:", iMax, decimals, cSum, self.__cBestDecimals, self.__cBestLen
            else:
                if cLen < self.__cBestLen:
                    self.__cBestDecimals = decimals[:]
                    self.__cBestLen = cLen
            del decimals[-1]


def ToRomanExtended(i):
    # return ToRomanCommon(i) #FIXME
    i = int(i)
    bIt = BestExtendedRomanIteration(i)
    bestRoman = bIt.calculate()
    del bIt
    return bestRoman

    # roman = ""
    # while i > 0:
    #     for rValue in RDIVSe:
    #         if i >= rValue:
    #             roman += I2Re[rValue]
    #             i -= rValue
    #             break
    # return roman


def RepresentsInt(s):
    try:
        int(s)
        return True
    except ValueError:
        return False


def main():
    lines = []
    with open("input.txt", "r") as input:
        lines = input.readlines()

    with open("output_common.txt", "w") as out_common:
        with open("output_extended.txt", "w") as out_extended:
            for line in lines:
                if RepresentsInt(line):
                    out_common.write(ToRomanCommon(line) + "\n")
                    out_extended.write(ToRomanExtended(line) + "\n")
                else:
                    out_common.write(str(FromRoman(line)) + "\n")
                    out_extended.write(str(FromRoman(line)) + "\n")

if __name__ == "__main__":
    main()
