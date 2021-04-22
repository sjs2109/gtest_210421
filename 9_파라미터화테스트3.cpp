
#include <gtest/gtest.h>

bool Check(int arg1, int arg2) {
	return arg1 > arg2;
}

//-----

struct Input {
	int arg1;
	int arg2;

	bool result;
};

std::ostream& operator<<(std::ostream& os, const Input& input) {
	return os << "Input{arg1=" << input.arg1 << ", arg2=" << input.arg2 << ", result=" << input.result << "}";
}

class SampleTest : public testing::TestWithParam<Input> {
};

using testing::Values;

INSTANTIATE_TEST_SUITE_P(InputValues, SampleTest,
	Values(Input{20, 30, true}, Input{30, 40, true}, Input{40, 50, true}));

TEST_P(SampleTest, Check) {
	Input input = GetParam();
	EXPECT_TRUE(Check(input.arg1, input.arg2));
	EXPECT_EQ(Check(input.arg1, input.arg2), input.result);
}










