// 6_비기능테스트.cpp
//  : 기능적인 동작 뿐 아니라 성능이나 메모리 등의 비기능적인 부분을 검증한다.

#include <string>
#include <unistd.h>

void OpenFile(const std::string& filename) {
	sleep(2);
}

//--------
#include <gtest/gtest.h>


// 방법 1. TestSuite - SetUp / TearDown를 이용하는 방법.
class SampleTest : public testing::Test {
protected:
	time_t startTime;
	void SetUp() override {
		startTime = time(nullptr);
	}

	void TearDown() override {
		time_t endTime = time(nullptr);
		time_t duration = endTime - startTime;

		EXPECT_LE(duration, 1) << "시간 초과: " << duration << "초 걸림";
	}
};

TEST_F(SampleTest, OpenFile) {
	OpenFile("");
}

// OpenFile은 1초 이내에 동작해야 합니다.
#if 0
TEST(SampleTest, OpenFile) {
	OpenFile("");
}
#endif


