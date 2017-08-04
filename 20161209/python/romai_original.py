R2I = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
CANPLACEDBEFORE = {'I': ['V', 'X'], 'X': ['L', 'C'], 'C': ['D', 'M']}
I2R = {1: 'I', 4: 'IV', 5: 'V', 9: 'IX', 10: 'X', 40: 'XL', 50: 'L', 90: 'XC',
		100: 'C', 400: 'CD', 500: 'D', 900: 'CM', 1000: 'M'}
RDIVS = sorted(I2R.keys(), reverse=True)

I2Ro = {1: 'I', 5: 'V', 10: 'X', 50: 'L', 100: 'C', 500: 'D', 1000: 'M'}
RDIVSo = sorted(I2Ro.keys(), reverse=True)
I2Re = I2Ro.copy()
for n,i in enumerate(RDIVSo):
	for j in RDIVSo[n:]:
		I2Re[i-j] = I2Ro[j]+I2Ro[i]
RDIVSe = sorted(I2Re.keys(), reverse=True)

def FromRoman(s):
	s = s.strip()
	value = 0
	for c in s:
		if c not in R2I.keys():
			return -1
	for i, c in enumerate(s):
		if i == len(s)-1:
			nextC = None
		else:
			nextC = s[i+1]
		if nextC and R2I[c] < R2I[nextC]:
			if (c not in CANPLACEDBEFORE.keys()) or (nextC not in CANPLACEDBEFORE[c]):
				return -1
			if (i < len(s)-2) and (nextC in s[i+2:]):
				return -1
			value -= R2I[c]
		else:
			value += R2I[c]
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

def ToRomanExtended(i):
	#return ToRomanCommon(i) #FIXME
	i = int(i)
	roman = ""
	while i > 0:
		for rValue in RDIVSe:
			if i >= rValue:
				roman += I2Re[rValue]
				i -= rValue
				break
	return roman

def RepresentsInt(s):
	try:
		int(s)
		return True
	except ValueError:
		return False

def main():
	lines=[]
	with open("input.txt", "r") as input:
		lines = input.readlines()

	with open("output_common.txt", "w") as out_common:
		with open("output_extended.txt", "w") as out_extended:
			for line in lines:
				if RepresentsInt(line):
					out_common.write(ToRomanCommon(line)+"\n")
					out_extended.write(ToRomanExtended(line)+"\n")
				else:
					out_common.write(str(FromRoman(line))+"\n")
					out_extended.write(str(FromRoman(line))+"\n")

if __name__ == "__main__":
    main()
