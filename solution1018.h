#pragma once

#include <vector>
#include <bitset>
/*
문제:
지민이는 자신의 저택에서 MN개의 단위 정사각형으로 나누어져 있는 M*N크기의 보드를 찾았다.
어떤 정사각형은 검정색으로 칠해져있고, 나머지는 흰색으로 칠해져 있다. 지민이는이 보드를
잘라서 8*8크기의 체스판으로 만드려고 한다.
하지만 지민이는 이 보드가 체스판처럼 검정/흰색 패턴이 번갈아가며 색칠해져있지 않기 때문에
고민에 빠졌다. 따라서 지민이는 8*8크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 
칠해야 겠다고 생각했다. 당연히 8*8크기는 아무데서나 골라도 된다.
현재 보드의 색이 어떤지 상태가 주어질 때, 지민이가 8*8크기로 자른 뒤에 다시 칠해야하는
정사각형 개수의 최솟값을 구하는 프로그램을 작성하시오.
체스판은 각 정사각형이 검정 또는 흰색이며, 변을 공유하는 두 개의 사각형이 같은 색이 아닐 때 이다.
따라서 위 정의에 의하면 체스판의 색은 항상 두 가지가 가능한데, 하나는 왼쪽 위 코너가 흰색인 것,
검정색인 것 두가지이다.

입력:
첫째 줄에 N과 M이 주어진다. M과 N은 8보다 크거나 같고, 50보다 작거나 같은 자연수이다.
둘째 줄부터 N개 줄에는 체스판의 색 상태가 주어진다. B는 검정색이며, W는 흰색이다.

출력:
첫째 줄에 지민이가 8*8크기로 자른 뒤에 다시 칠해야하는 정사각형 개수의 최솟값을 출력한다.

예제 입력 1:
8 8
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBBBWBW
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBWBWBW

예제 출력 1:
1

예제 입력 2:
10 13
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
WWWWWWWWWWBWB
WWWWWWWWWWBWB

예제 출력 2:
12

나의 방법:
"브루트 포스" : 사실 모든 경우의 수를 모두 계산하여야 한다.
검사할 범위를 더 줄일 수는 없다.
-> 그렇다면 검사하는 방법에서 최대한 효율을 발휘하자
 1) if문 최소한으로 사용
 2) 비트연산으로 한번에 비교

스터디 풀이 방법들:
1. 
2. 
3. 
*/

namespace BG1018 {
	struct InputData {
		int n, m;
		std::vector< std::vector<bool> > vec;
	};
	using INPUT = InputData;
	using OUTPUT = int;
	using SOLUTION = OUTPUT(*)(INPUT);

	OUTPUT solution_1(INPUT);
	OUTPUT solution_2(INPUT);
	OUTPUT solution_3(INPUT);

	/** 사용할 값*/
#define B true
#define W false
#define SIZE 8
	static const int size = 8;
	using CheckArea = std::bitset<size * size>;


	/** Test Case */
	void SetTestCase(INPUT& input);
}

