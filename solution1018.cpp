
#include "solution1018.h"

#include <iostream>
#include <bitset>

BG1018::OUTPUT BG1018::solution_1(BG1018::INPUT input)
{
	// SetTestCase(input);

	BG1018::OUTPUT output{};

	// 정답 판 제작
	BG1018::CheckArea answerCase1, answerCase2;
	bool start1 = B;
	bool start2 = W;

	for (int i = 0; i < SIZE * SIZE; i++) {
		if (i % size == 0) {
			answerCase1[i] = start1;
			start1 = !start1;

			answerCase2[i] = start2;
			start2 = !start2;
		}
		else {
			answerCase1[i] = !answerCase1[i - 1];
			answerCase2[i] = !answerCase2[i - 1];
		}		
	}

	// 검사 지역 얻기
	auto makeArea = [input](const int m, const int n) -> BG1018::CheckArea {
		BG1018::CheckArea check;
		int index{ 0 };

		for (int i = m; i < m + SIZE; i++) {
			for (int j = n; j < n + SIZE; j++) {
				check[index++] = input.vec[i][j];
			}
		}
		return check;
	};

	// 바꿔야 하는 갯수 얻기	
	auto findFixCount = [answerCase1, answerCase2](BG1018::CheckArea area) -> int {
		// xor 연산은 다를 때 1이다.
		BG1018::CheckArea tmp1 = area ^ answerCase1;
		int cnt1 = tmp1.count();

		BG1018::CheckArea tmp2 = area ^ answerCase2;
		int cnt2 = tmp2.count();
		
#ifndef _TEST_MODE_
		std::cout << "검사할 판 : " << area.to_string() << std::endl;
		std::cout << "anwr1 : " << answerCase1.to_string() << std::endl;
		std::cout << "tmp01 : " << tmp1.to_string() << std::endl<<std::endl;

		std::cout << "check : " << area.to_string() << std::endl;
		std::cout << "anwr2 : " << answerCase2.to_string() << std::endl;		
		std::cout << "tmp02 : " << tmp2.to_string() << std::endl;
#endif

		return cnt1 < cnt2 ? cnt1 : cnt2;
	};

	// 최소값
	int min{ std::numeric_limits<int>::max() };

	for (int i = 0; i <= input.m - SIZE; i++) {
		for (int j = 0; j <= input.n - SIZE; j++) {
			BG1018::CheckArea check = makeArea(i, j);
			int fixCnt{ findFixCount(check) };
			if (fixCnt < min)
				min = fixCnt;
		}
	}

	output = min;

	return output;
}

BG1018::OUTPUT BG1018::solution_2(BG1018::INPUT input)
{
	BG1018::OUTPUT output{};


	return output;
}


BG1018::OUTPUT BG1018::solution_3(BG1018::INPUT input)
{
	BG1018::OUTPUT output{};


	return output;
}

void BG1018::SetTestCase(BG1018::INPUT& input)
{
	input.m = 8;
	input.n = 8;

	std::vector<bool> vec1{ W, B, W, B, W, B, W, B };
	std::vector<bool> vec2{ B, W, B, W, B, W, B, W };
	std::vector<bool> vec3{ W, B, W, B, W, B, W, B };
	std::vector<bool> vec4{ B, W, B, B, B, W, B, W };
	std::vector<bool> vec5{ W, B, W, B, W, B, W, B };
	std::vector<bool> vec6{ B, W, B, W, B, W, B, W };
	std::vector<bool> vec7{ W, B, W, B, W, B, W, B };
	std::vector<bool> vec8{ B, W, B, W, B, W, B, W };


	input.vec.clear();

	input.vec.push_back(vec1);
	input.vec.push_back(vec2);
	input.vec.push_back(vec3);
	input.vec.push_back(vec4);
	input.vec.push_back(vec5);
	input.vec.push_back(vec6);
	input.vec.push_back(vec7);
	input.vec.push_back(vec8);
}
