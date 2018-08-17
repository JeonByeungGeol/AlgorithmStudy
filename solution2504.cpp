
#include "solution2504.h"

#include <stack>
#include <vector>
#include <sstream>


OUTPUT solution2504_1(INPUT input)
{
	OUTPUT output{ 0 };

	return output;
}
OUTPUT solution2504_2(INPUT input)
{
	OUTPUT output{ 0 };

	auto isValidInput = [](INPUT input) -> bool {
		if (input.empty())
			return false;

		std::stack<char> stack;

		for (char ch : input) {
			switch (ch)
			{
			case '(':
			case '[':
				stack.push(ch);
				break;

			case ')':
				if (stack.empty())
					return false;

				if (stack.top() == '(')
					stack.pop();
				else
					return false;
				break;

			case ']':
				if (stack.empty())
					return false;

				if (stack.top() == '[')
					stack.pop();
				else
					return false;
				break;

			default:
				return false;
			}
		}

		if (stack.empty() == false)
			return 0;

		return true;
	};

	if (isValidInput(input) == false)
		return 0;


	auto isNumber = [](std::string str, int& number)  -> bool {
		std::stringstream ss{ str };

		if ((ss >> number).fail())
			return false;
		return true;
	};

	int number{ 0 };

	std::stack<std::string> stack;
	std::vector<std::string> vec;

	static int step{ 0 };

	for (auto ch : input)
		vec.push_back(std::string{ ch });

	while (vec.size() > 1) {
		for (auto str : vec) {
			if (str == "(" || str == "[") {
				stack.push(str);
			}
			// 숫자+숫자 치환
			else if (isNumber(str, number)) {
				int number2{ 0 };
				if (stack.empty()) {
					stack.push(str);
				}
				else if (isNumber(stack.top(), number2)) {
					stack.pop();
					stack.push(std::to_string(number + number2));
				}
				else
					stack.push(str);
			}

			else if (str == ")") {
				// () 치환
				if (stack.top() == "(")
				{
					stack.pop();
					stack.push("2");
				}
				// (숫자) 치환
				else {
					if (isNumber(stack.top(), number)) {
						stack.pop();

						if (stack.top() == "(") {
							stack.pop();
							stack.push(std::to_string(2 * number));
						}
						else {
							stack.push(std::to_string(number));
							stack.push(str);
						}
					}
					else {
						stack.push(str);
					}
				}
			}

			else if (str == "]") {
				// [] 치환
				if (stack.top() == "[")
				{
					stack.pop();
					stack.push("3");
				}
				// [숫자] 치환
				else {
					if (isNumber(stack.top(), number)) {
						stack.pop();

						if (stack.top() == "[") {
							stack.pop();
							stack.push(std::to_string(3 * number));
						}
						else {
							stack.push(std::to_string(number));
							stack.push(str);
						}
					}
					else {
						stack.push(str);
					}
				}
			}

			else {
				//std::cout << "ERROR" << std::endl;
				return 0;
			}
		}

		vec.clear();
		while (stack.empty() == false) {
			vec.push_back(stack.top());
			stack.pop();
		}

		std::reverse(vec.begin(), vec.end());

		step++;
	}

	// for (auto str : vec) std::cout << str << " ";
	// std::cout << "STEP : " << step << std::endl;
	//std::cout << std::endl;

	output = atoi(vec[0].c_str());

	return output;
}
OUTPUT solution2504_3(INPUT input)
{
	OUTPUT output{ 0 };


	return output;
}