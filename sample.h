#pragma once

#include <string>

/*
문제:


입력:

출력:

예제 입력 1:

예제 출력 1:

나의 방법:


스터디 풀이 방법들:
*/

namespace BG0000 {
	struct InputData {
		int val1;
		int val2;
	};

	using INPUT = InputData;
	using OUTPUT = int;
	using SOLUTION = OUTPUT(*)(INPUT);
	using INPUT_PROCESS = bool(*)(INPUT&);

	bool inputProcess(INPUT&);

	OUTPUT solution_1(INPUT);
	OUTPUT solution_2(INPUT);
	OUTPUT solution_3(INPUT);

	/** 사용할 값*/
#define INVALID_INPUT -1	

	/** Test Case */
	void SetTestCase(INPUT& input);
}

