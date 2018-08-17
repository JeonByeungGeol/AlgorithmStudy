

/**
 Ǯ�� ����� main
*/
#include <iostream>
#include <string>

/** ���� ���� */
#include <vector>
#include <bitset>

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

/** ����� ��*/
#define B true
#define W false
#define SIZE 8
static const int size = 8;
using CheckArea = std::bitset<size * size>;

OUTPUT solution(INPUT input);

int main()
{
	/** INPUT ó��*/
	INPUT input;
	std::cin >> input.m >> input.n;
	for (int i = 0; i < input.m; i++) {
		std::vector<bool> vec;
		vec.resize(input.n);
		input.vec.push_back(vec);
	}

	char c;
	for (int i = 0; i < input.m; i++) {
		for (int j = 0; j < input.n; j++) {
			std::cin >> c;
			c == 'B' ? input.vec[i][j] = true : input.vec[i][j] = false;
		}
	}

	OUTPUT answer{ solution(input) };
	std::cout << answer;

	return 0;
}

OUTPUT solution(INPUT input)
{
	// ���� �� ����
	CheckArea answerCase1, answerCase2;
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

	// �˻� ���� ���
	auto makeArea = [input](const int m, const int n) -> CheckArea {
		CheckArea check;
		int index{ 0 };

		for (int i = m; i < m + SIZE; i++) {
			for (int j = n; j < n + SIZE; j++) {
				check[index++] = input.vec[i][j];
			}
		}
		return check;
	};

	// �ٲ�� �ϴ� ���� ���	
	auto findFixCount = [answerCase1, answerCase2](CheckArea area) -> int {
		// xor ������ �ٸ� �� 1�̴�.
		CheckArea tmp1 = area ^ answerCase1;
		int cnt1 = tmp1.count();

		CheckArea tmp2 = area ^ answerCase2;
		int cnt2 = tmp2.count();
		
		return cnt1 < cnt2 ? cnt1 : cnt2;
	};

	// �ּҰ�
	int min{ SIZE*SIZE /*std::numeric_limits<int>::max()*/ };

	for (int i = 0; i <= input.m - SIZE; i++) {
		for (int j = 0; j <= input.n - SIZE; j++) {
			CheckArea check = makeArea(i, j);
			int fixCnt{ findFixCount(check) };
			if (fixCnt < min)
				min = fixCnt;
		}
	}


	OUTPUT output{ min };
	return output;
}