
#include "solution0814.h"

#include <iostream>
#include <string>
#include <map>
#include <fstream>

int BG0814::f(int n)
{
	if (n == 1)
		return 1;

	return f(n / 10) + n;
}

BG0814::OUTPUT BG0814::inputProcess(BG0814::INPUT &input)
{
	std::cin >> input.N >> input.findN;

	return VALID_INPUT;
}

BG0814::OUTPUT BG0814::solution_1(BG0814::INPUT input)
{
	// SetTestCase(input);

	BG0814::OUTPUT output{0};

	std::string str;

	std::map<int, int> map;

	for (int i = 0; i <= input.N; i++)
		str.append(std::to_string(i));

	for (auto c : str) {
		std::string s{ c };
		map[atoi(s.c_str())]++;
	}
	
	output = map[input.findN];

	return output;
}

BG0814::OUTPUT BG0814::solution_2(BG0814::INPUT input)
{
	BG0814::OUTPUT output{ 0 };

	int cur{ 10 };
	int prev{ 1 };

	while (1) {
		if (input.N % cur != 0) {
			output += f(prev);
			prev *= cur;
			cur *= 10;			
		}
		else {
			// n = 7921
			// cur=10000, prev=1000


			break;
		}		
	}
	



	return output;
}

BG0814::OUTPUT BG0814::solution_3(BG0814::INPUT input)
{
	BG0814::OUTPUT output{};

	std::fstream fs;
	fs.open("test.txt");

	std::map<int, int> map;
	char c[2];
	while (fs.read(c, 1)) {
		map[atoi(c)]++;
	}
	std::fstream fs2;
	fs2.open("result.txt");
	for (auto iter : map)
	{
		fs2 << "¼ýÀÚ:" << iter.first;
		fs2 << " /°¹¼ö:" << iter.second << "\n";
	}
	fs2.close();

	return output;
}

void BG0814::SetTestCase(BG0814::INPUT& input)
{
	
}
