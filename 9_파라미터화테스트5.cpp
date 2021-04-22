#include <iostream>
#include <vector>
#include <string>

#include <gtest/gtest.h>

class StringTest : public testing::TestWithParam<std::string> {
};

// Data가 별도의 파일에서 로드가 필요합니다.
//  => ValuesIn

#if 0
std::vector<std::string> LoadFromFile() {
	std::vector<std::string> result;
	result.push_back("hello");
	result.push_back("world");
	return result;
}
#endif
// $ ./a.out < input.txt
std::vector<std::string> LoadFromFile() {
	std::vector<std::string> v;

	while (!std::cin.eof()) {
		std::string input;
		std::cin >> input;

		v.push_back(input);
	}

	return v;
}

using testing::ValuesIn;
INSTANTIATE_TEST_SUITE_P(StringValues, StringTest, 
	ValuesIn(LoadFromFile()));

TEST_P(StringTest, InputTest) {
	std::string s = GetParam();
	std::cout << s << std::endl;
}
