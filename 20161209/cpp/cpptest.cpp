#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

int FromRoman(const char *roman) 
{
	// TODO
	return 0;
}

std::string ToRomanCommon(int number) 
{
	// TODO
	return "0";
}

std::string ToRomanExtended(int number) 
{
	// TODO
	return "0";
}

int main()
{
	std::ifstream in;
	std::ofstream out_common, out_extended;
	in.open("input.txt");
	out_common.open("output_common.txt");
	out_extended.open("output_extended.txt");

	while (!in.eof())
	{
		std::string line;
		in >> line;
		int x;
		std::istringstream ss(line);
		if (ss >> x)	// decimal number
		{
			out_common << ToRomanCommon(x) << std::endl;
			out_extended << ToRomanExtended(x) << std::endl;
		}
		else
		{
			// I know it's redundant to write this in two files, but I don't care
			out_common << FromRoman(line.c_str()) << std::endl;
			out_extended << FromRoman(line.c_str()) << std::endl;
		}
	}

	return 0;
}
