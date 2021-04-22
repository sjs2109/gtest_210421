
#include <gtest/gtest.h>

class SampleTest : public testing::TestWithParam<int> {
};

// Values
// ValuesIn
// Combine
// Range
using testing::Range;
// Range(0, 100, step)
//   [0, 100)

INSTANTIATE_TEST_SUITE_P(IntValues, SampleTest, 
	Range(0, 100, 10));

TEST_P(SampleTest, Sample) {
	printf("%d\n", GetParam());
}
	
