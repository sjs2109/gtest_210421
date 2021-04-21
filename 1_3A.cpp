
// 1_3A.cpp

// 단위 테스트를 만드는 방법
//  - Google Test 1.10 이전
//  - xUnit Test Framework의 표준 용어와 차이가 있었습니다.
//
//  TestCase
//    - Test
//    - Test
//    - Test
//  TestCase
//    - Test
//    - Test
//------------------------------------
//  - Google Test 1.10 이후
//  - xUnit Test Framework 표준 용어
//
//  TestSuite
//   - TestCase
//   - TestCase
//   - TestCase
//  TestSuite
//   - TestCase
//   - TestCase

// * 구글 테스트에서 TestCase 를 추가하는 방법.
// : TEST(TestSuite 이름, TestCase 이름)

#if 0
#include <gtest/gtest.h>

TEST(SampleTest, Sample1) {
	// 명시적으로 성공을 표현하는 방법
	SUCCEED();
}

TEST(SampleTest, Sample2) {
	// 명시적으로 실패하는 방법
	FAIL();
}
#endif
//----------------------------------
// "단위 테스트를 구성하는 방법"

// SUT(System Under Test)
//  - 테스트 대상 시스템
//  - Code Under Test / Class Under Test - CUT
class Calculator {
public:
	double Display() { return 0; }
	
	void Enter(double v) { }
	void PressPlus() {}
	void PressMinus() {}
	void PressEquals() {}
};



































