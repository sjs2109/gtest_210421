// 2_테스트픽스쳐.cpp
class Calculator {
public:
	Calculator(int n) {}

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
// TEST(SampleTest, foo) {} // class SampleTest_foo_Test : public testing::Test {};
// TEST(SampleTest, goo) {} // class SampleTest_goo_Test : public testing::Test {};

//                 testing::Test
//                       |
//                -------------------
//                |                 |
//            SampleTest_foo  SampleTest_goo


//   2) TEST_F: 명시적인 테스트 스위트를 이용합니다.
//   class SampleTest : public testing::Test {}
//   TEST_F(SampleTest, foo) {} // class SampleTest_foo_Test : public SampleTest {};
//   TEST_F(SampleTest, goo) {} // class SampleTest_goo_Test : public SampleTest {};

//                testing::Test
//                      |
//                 SampleTest   
//                      |
//                -------------------
//                |                 |
//            SampleTest_foo  SampleTest_goo


// 적용 방법.
//  1. 테스트 스위트 클래스를 만듭니다.
class CalculatorTest : public testing::Test {
// private: - X
// public:
protected:
	// 주의사항: 테스트케이스 안에서 테스트스위트 클래스에 정의된 함수에 접근하기 위해서는 
	//           protected 이상 이어야 합니다.
	// Calculator* Create() { return new Calculator; }
	Calculator* Create() { return new Calculator(0); }
	// 테스트 유틸리티 메소드 - Creation 메소드
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























































