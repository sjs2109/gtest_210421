// 2_테스트픽스쳐.cpp

class Calculator {
public:
	// Calculator(int n) {}

	double Display() { return 0; }
	
	void Enter(double v) { }
	void PressPlus() {}
	void PressMinus() {}
	void PressEquals() {}
};

//-------------------
#include <gtest/gtest.h>
#define SPEC printf

// Test Fixture
//  정의: xUnit Test Pattern에서는 SUT를 실행하기 위해서 준비해야 하는 모든 작업을 
//        테스트 픽스쳐 라고 합니다.
//        픽스쳐를 구성하는 모든 로직 부분을 "픽스쳐를 설치한다" 라고 합니다.

// 픽스쳐 설치하는 방법.
//  1. Inline Fixture Setup
//    : 모든 픽스쳐 설치를 테스트 케이스 안에서 수행한다.
//    장점:  픽스쳐를 설치하는 과정과 검증 로직이 테스트 함수 안에 존재하기 때문에
//           인과관계를 쉽게 분석할 수 있다.
//    단점:  모든 테스트 코드 안에서 '테스트 코드 중복'이 발생합니다.

//  테스트 냄새(Test Smells)
//   : 테스트 코드의 유지보수를 어렵게 만드는 요소 

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























































