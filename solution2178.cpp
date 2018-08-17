
#include "solution2178.h"

#include <iostream>
#include <string>

bool BG2178::inputProcess(BG2178::INPUT& input)
{
	std::cin >> input.x >> input.y;

	std::string str;
	for (int i = 0; i < input.x; i++) {
		std::cin >> str;
		for (int j = 0; j < input.y; j++) {
			std::string tmp{ str[j] };
			input.arr[i][j] = std::atoi(tmp.c_str()) == 1 ? true : false;
		}
	}

	return true;
}

BG2178::OUTPUT BG2178::solution_1(BG2178::INPUT input)
{
	// SetTestCase(input);

	BG2178::OUTPUT output{};


	return output;
}

BG2178::OUTPUT BG2178::solution_2(BG2178::INPUT input)
{
	BG2178::OUTPUT output{};


	return output;
}


BG2178::OUTPUT BG2178::solution_3(BG2178::INPUT input)
{
	BG2178::OUTPUT output{};


	return output;
}

void BG2178::SetTestCase(BG2178::INPUT& input)
{
	input.x = 8;
	input.y = 8;

}
