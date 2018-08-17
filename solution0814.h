#pragma once

/*
문제:
1 부터 N 까지 차례대로 수를 쓰내려갈 때 특정수의 빈도수를 구하는 것이 문제이다.​
예를 들어, N = 11 이고 조사할 수가 1 인 경우
​
1234567891011
빈도 수는 4 이다.

입력:
N 과 한 자리 수(0 ~ 9)가 주어진다. N 은 100 000 000 이하의 자연수이다.


출력:
빈도 수를 출력한다. 답은 32 비트 정수 범위를 넘어가지 않는다.

예제 입력 1:
11 1

예제 출력 1:
4


나의 방법:
1) 
1~9와 0은 계산법이 약간 다르다.

2) 

스터디 풀이 방법들:
1.
2.
3.
*/


namespace BG0814 {
	struct InputData {
		int N, findN;
	};
	using INPUT = InputData;
	using OUTPUT = int;
	using SOLUTION = OUTPUT(*)(INPUT);
	using INPUT_PROCESS = OUTPUT(*)(INPUT&);
	
	OUTPUT inputProcess(INPUT&);

	OUTPUT solution_1(INPUT);
	OUTPUT solution_2(INPUT);
	OUTPUT solution_3(INPUT);

	/** 사용할 값*/
#define VALID_INPUT 1
#define INVALID_INPUT -1
	int f(int n);

	/** Test Case */
	void SetTestCase(INPUT& input);
}

