// 4_전역픽스쳐.cpp
//  => xUnit Test Framework이 제공하는 기능이 아닙니다.
//  => Google Test 고유의 기능입니다.
//     프로그램 시작 - SetUp
//     프로그램 종료 - TearDown

#include <gtest/gtest.h>

class TestEnvironment : public testing::Environment {
public:
	TestEnvironment() { printf("TestEnvironment()\n"); }
	~TestEnvironment() { printf("~TestEnvironment()\n"); }

	void SetUp() override {
		printf("Global SetUp()\n");
	}

	void TearDown() override {
		printf("Global TearDown()\n");
	}
};

TEST(SampleTest, foo) {}
TEST(MyTest, goo) {}

// 등록하는 방법 2가지
//  1) main함수 직접 제공하지 않을 때 - 전역 변수
testing::Environment* my_env = testing::AddGlobalTestEnvironment(new TestEnvironment);

//  2) main함수 직접 제공하고 있을 때









