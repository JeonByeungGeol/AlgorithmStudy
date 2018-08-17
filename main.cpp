

#include <iostream>
#include <chrono>

#include <string>
#include <sstream>

#define _TEST_MODE_


/** 문제 셋팅 */
#include "solution2178.h"
using INPUT = BG2178::INPUT;
using OUTPUT = BG2178::OUTPUT;
using SOLUTION = BG2178::SOLUTION;
using INPUT_PROCESS = BG2178::INPUT_PROCESS;

INPUT_PROCESS inputProcess = BG2178::inputProcess;
SOLUTION solution = BG2178::solution_1;


int main()
{
	/** INPUT 처리*/
	INPUT input;
	OUTPUT answer;

	if (false == inputProcess(input)) {
#ifdef _TEST_MODE_
		std::cout << "Invalid Input " << std::endl;
#endif	
		return -1;		
	}
	
	auto s = std::chrono::system_clock::now();
	answer = solution(input);
	auto du = std::chrono::duration_cast<std::chrono::milliseconds>((std::chrono::system_clock::now() - s));
	
#ifdef _TEST_MODE_
	std::cout << "OUTPUT : " << answer << std::endl;
	std::cout << "SEC : " << (double)du.count() / 1000.0 << std::endl << std::endl;
#else
	std::cout << answer;	
#endif

	return 0;
}