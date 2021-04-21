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

TEST(GoogleTest, Sample1) {
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
	const char* s4 = "Hello";

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
	EXPECT_NEAR(a, b, 0.000000000);
}












