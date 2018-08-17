#pragma once

#include <vector>
#include <bitset>
/*
����:
�����̴� �ڽ��� ���ÿ��� MN���� ���� ���簢������ �������� �ִ� M*Nũ���� ���带 ã�Ҵ�.
� ���簢���� ���������� ĥ�����ְ�, �������� ������� ĥ���� �ִ�. �����̴��� ���带
�߶� 8*8ũ���� ü�������� ������� �Ѵ�.
������ �����̴� �� ���尡 ü����ó�� ����/��� ������ �����ư��� ��ĥ�������� �ʱ� ������
��ο� ������. ���� �����̴� 8*8ũ���� ü�������� �߶� �Ŀ� �� ���� ���簢���� �ٽ� 
ĥ�ؾ� �ڴٰ� �����ߴ�. �翬�� 8*8ũ��� �ƹ������� ��� �ȴ�.
���� ������ ���� ��� ���°� �־��� ��, �����̰� 8*8ũ��� �ڸ� �ڿ� �ٽ� ĥ�ؾ��ϴ�
���簢�� ������ �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
ü������ �� ���簢���� ���� �Ǵ� ����̸�, ���� �����ϴ� �� ���� �簢���� ���� ���� �ƴ� �� �̴�.
���� �� ���ǿ� ���ϸ� ü������ ���� �׻� �� ������ �����ѵ�, �ϳ��� ���� �� �ڳʰ� ����� ��,
�������� �� �ΰ����̴�.

�Է�:
ù° �ٿ� N�� M�� �־�����. M�� N�� 8���� ũ�ų� ����, 50���� �۰ų� ���� �ڿ����̴�.
��° �ٺ��� N�� �ٿ��� ü������ �� ���°� �־�����. B�� �������̸�, W�� ����̴�.

���:
ù° �ٿ� �����̰� 8*8ũ��� �ڸ� �ڿ� �ٽ� ĥ�ؾ��ϴ� ���簢�� ������ �ּڰ��� ����Ѵ�.

���� �Է� 1:
8 8
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBBBWBW
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBWBWBW

���� ��� 1:
1

���� �Է� 2:
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

���� ��� 2:
12

���� ���:
"���Ʈ ����" : ��� ��� ����� ���� ��� ����Ͽ��� �Ѵ�.
�˻��� ������ �� ���� ���� ����.
-> �׷��ٸ� �˻��ϴ� ������� �ִ��� ȿ���� ��������
 1) if�� �ּ������� ���
 2) ��Ʈ�������� �ѹ��� ��

���͵� Ǯ�� �����:
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

	/** ����� ��*/
#define B true
#define W false
#define SIZE 8
	static const int size = 8;
	using CheckArea = std::bitset<size * size>;


	/** Test Case */
	void SetTestCase(INPUT& input);
}

