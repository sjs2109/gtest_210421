
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

//-------------------
// calculator.h / calculator.cpp
// - spec/calculator.spec.cpp
// - test/calculator.test.cpp

// TestSuite 이름
// : 테스트 대상 클래스의 마지막에 Test / Spec 이름을 붙입니다.
// => CalculatorTest / CalculatorSpec


// TDD(Test Driven Development) vs BDD(Behavior Driven Development)
//  1. 용어적인 차이
//    : 사람의 구어체와 유사한 형태를 권장합니다.
//  2. 행위 기반 검증

#include <gtest/gtest.h>
// 3A: TC를 구성하는 방법
// 1. Arrange(Given): 객체를 생성하고, 필요한 경우 설정하고 준비한다.
// 2. Act(When): 객체를 작용을 가한다.
// 3. Assert(Then): 기대하는 바를 단언한다.

// 테스트 코드 품질
// 1. 가독성
//  : 테스트 이름 / 테스트 실패 메세지
// 2. 유지보수성
//  : 테스트 케이스 안에서 제어 구문(조건문, 반복문, 예외 처리 등)의 발생을 최소화 해야 한다.
// 3. 신뢰성

#define SPEC printf

// 테스트의 이름이 어떤 테스트를 수행하는지 드러날 수 있도록 하는 것이 좋습니다.
// - ex) 테스트대상함수_시나리오_기대값
TEST(CalculatorTest, PressPlus_2Plus2_Display4) {
	SPEC("2 더하기 2는 4가 나오는지 검증한다.\n");
	// Arrange
	Calculator* calc = new Calculator();

	// Act
	calc->Enter(2);
	calc->PressPlus();
	calc->Enter(2);
	calc->PressEquals();

	// Assert
	ASSERT_EQ(calc->Display(), 4) << "2 + 2 하였을 때";
#if 0
	if (calc->Display() != 4) {
		// 실패가 발생한 원인을 명시해야 한다.
		FAIL() << "result: " << calc->Display() << " - 2 + 2 하였을 때"; 
	} else {
		SUCCEED();
	}
#endif
}

TEST(CalculatorTest, Plus) {
	// Arrange
	Calculator* calc = new Calculator();

	// Act
	calc->Enter(2);
	calc->PressPlus();
	calc->Enter(2);
	calc->PressEquals();

	// Assert
	if (calc->Display() != 4) {
		FAIL();
	} else {
		SUCCEED();
	}
}























































