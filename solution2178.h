#pragma once

#include <string>

/*
����:


�Է�:

���:

���� �Է� 1:

���� ��� 1:

���� ���:


���͵� Ǯ�� �����:
*/

namespace BG2178 {
	struct InputData {
		int x, y;
		bool** arr;
	};
	using INPUT = InputData;
	using OUTPUT = int;
	using SOLUTION = OUTPUT(*)(INPUT);
	using INPUT_PROCESS = bool(*)(INPUT&);

	bool inputProcess(INPUT&);

	OUTPUT solution_1(INPUT);
	OUTPUT solution_2(INPUT);
	OUTPUT solution_3(INPUT);

	/** ����� ��*/
#define INVALID_INPUT -1

	/** Test Case */
	void SetTestCase(INPUT& input);
}
