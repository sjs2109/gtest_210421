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

// 픽스쳐 설치하는 방법.
//  2. Delegate SetUp(위임 설치)
//    : 테스트 케이스 안에서 발생하는 픽스쳐 설치에 대한 코드를 별도 테스트 유틸리티 함수를 통해 모듈화한다.
//     => 명시적인 테스트 스위트가 필요합니다.

//  테스트케이스를 만드는 매크로
//   1) TEST: 암묵적인 테스트 스위트를 사용합니다.


// 적용 방법.
//  1. 테스트 스위트 클래스를 만듭니다.
class CalculatorTest : public testing::Test {
public:
	Calculator* Create() { return new Caluclator(); }
};


//  2. TEST_F 매크로를 이용해서 테스트 케이스를 만듭니다.
TEST_F(CalculatorTest, PressPlus_2Plus2_Display4) {
	SPEC("2 더하기 2는 4가 나오는지 검증한다.\n");
	// Arrange
	Calculator* calc = Create();

	// Act
	calc->Enter(2);
	calc->PressPlus();
	calc->Enter(2);
	calc->PressEquals();

	// Assert
	ASSERT_EQ(calc->Display(), 4) << "2 + 2 하였을 때";
}

TEST_F(CalculatorTest, Plus) {
	// Arrange
	Calculator* calc = Create();

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























































