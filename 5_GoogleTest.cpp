// 5_GoogleTest.cpp
#include <gtest/gtest.h>
#include <string>

// 1. 단언문
//   ASSERT_XX : EQ, TRUE / FALSE, LT, GT, LE, GE ...
//    -> 하나의 단언문의 실패하면, 이후의 코드는 수행되지 않습니다.
//    -> "죽은 단언문"
//     : 하나의 테스트케이스 안에 최소한의 단언문을 사용하는 것이 좋다.
//       => 여러개의 테스트케이스를 만들어야 한다.
//   => 구글 테스트는 위의 문제를 해결하기 위한 단언 매크로를 제공합니다.
//   
//   EXPECT_XX : EQ(==), TRUE / FALSE, LT(<), GT(>), LE(<=), GE(>=) ...
//    : 단언문이 실패하더라도 이후의 코드는 계속 수행됩니다.
//      하나의 단언문이 실패한다면, 테스트의 결과는 실패가 됩니다.
int foo() { return 0;  }
int goo() { return -1; }

TEST(GoogleTest, DISABLED_Sample1) {
	int expected = 42;

	int actual1 = foo();
	int actual2 = goo();

	// ASSERT_EQ(actual1, expected);
	// ASSERT_EQ(actual2, expected);
	EXPECT_EQ(actual1, expected);
	EXPECT_EQ(actual2, expected);
}

// 2. 문자열 
//   C-Style 문자열: const char*
//     : EXPECT_STREQ / STRNE
//       EXPECT_STRCASEEQ / STRCASENE
//
//   C++ 문자열: std::string
TEST(GoogleTest, Sample2) {
	std::string s1 = "hello";
	std::string s2 = "hello";

	const char* s3 = s2.c_str();
	const char* s4 = "hello";

	EXPECT_EQ(s1, s2);
	// EXPECT_EQ(s3, s4);
	EXPECT_STREQ(s3, s4);
	EXPECT_STRCASEEQ(s3, s4);
}

// 3. 부동 소수점 
//   EXPECT_DOUBLE_EQ 
//   EXPECT_FLOAT_EQ
//
//   EXPECT_NEAR: 오차 범위를 직접 설정하는 것이 가능합니다.
TEST(GoogleTest, Sample3) {
	double a = 0.7;
	double b = 0.1 * 7;

	// EXPECT_EQ(a, b);
	EXPECT_DOUBLE_EQ(a, b); // 4ULP's
	EXPECT_NEAR(a, b, 0.0000000001);
}

// Coverage: 테스트 코드를 통해 수행된 제품 코드의 비율을 측정
void IsValidFilename(const std::string& filename) {
	if (filename.empty()) {
		throw std::invalid_argument("filename is empty!");
		// throw 1;
	}

	// ...
}

// IsValidFilename 빈 문자열을 전달하였을 경우, invalid_argument 예외가 제대로 발생하는지 여부를 검증하고 싶다.
// 4. 예외 검증
//  - EXPECT_THROW
//  - EXPECT_ANY_THROW
TEST(GoogleTest, Sample4) {
	std::string emptyFilename = "";

	EXPECT_THROW(IsValidFilename(emptyFilename), std::invalid_argument) << "빈 문자열을 전달하였을 때";
	EXPECT_ANY_THROW(IsValidFilename(emptyFilename));
}
#if 0
TEST(GoogleTest, Sample4) {
	std::string emptyFilename = "";

	try {
		IsValidFilename(emptyFilename);
		FAIL() << "예외가 발생하지 않았습니다.";
	} catch (std::invalid_argument&) {
		SUCCEED();
	} catch (...) {
		FAIL() << "다른 종류의 예외가 발생하였습니다.";
	}
}
#endif

// 5. 테스트 비활성화
//  = 테스트 케이스를 주석 처리하면 "잊혀진 테스트"가 됩니다.
//  => 비활성화된 테스트가 존재한다는 사실을 알려준다.
//
//    TEST_F(DISABLED_TestSuiteName, DISABLED_TestCaseName)
//     => TestSuite 의 이름이 DISABLED_ 로 되어 있거나
//        TestCase의 이름이 DISABLED_로 되어 있으면 됩니다.
//
//     : 비활성화된 테스트를 구동하는 방법.
//     $ ./a.out --gtest_also_run_disabled_tests

TEST(SampleTest, DISABLED_TestA) {
}

TEST(SampleTest, TestB) {
}

class DISABLED_HelloTest : public testing::Test {};
TEST_F(DISABLED_HelloTest, TestA) {}
TEST_F(DISABLED_HelloTest, TestB) {}

// 6. 반복 테스트
//  $ ./a.out --gtest_repeat=100 --gtest_break_on_failure --gtest_shuffle
//   : "변덕스러운 테스트"의 문제가 발생하는지 여부를 체크하기 위해 사용한다.
int i = 0;
TEST(GoogleTest, Sample6) {
	if (++i == 50) {
		FAIL() << "Fail!!!";
	}
}

// 7. 필터
//   : 잘 정의된 이름 규칙이 필요합니다.
//   $ ./a.out --gtest_filter=*.TestA
//   $ ./a.out --gtest_filter=-*.TestA
//
//   $ ./a.out --gtest_filter=TestSuiteA.*:-*.TestA
TEST(TestSuiteA, TestA) {}
TEST(TestSuiteB, TestA) {}
TEST(TestSuiteC, TestA) {}
TEST(TestSuiteD, TestA) {}

TEST(TestSuiteA, TestB) {}
TEST(TestSuiteB, TestB) {}
TEST(TestSuiteC, TestB) {}























