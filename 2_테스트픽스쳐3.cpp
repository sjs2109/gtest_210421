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
//  3. 암묵적 설치/해체(Implicit SetUp / TearDown)
//   : 여러 테스트에서 같은 테스트 픽스쳐의 코드를 SetUp() 함수에서 생성한다.
//   => xUnit Test Framework 기능
//   장점: 테스트 코드 중복을 제거하고, 꼭 필요하지 않은 상호작용을 캡슐화 수 있다.
//   단점: 픽스쳐 설치 코드가 테스트 함수 밖에 존재하기 때문에,
//         테스트 함수만으로 테스트 코드를 이해가 어려울 수 있다.

class CalculatorTest : public testing::Test {
protected:
	Calculator* calc;
	CalculatorTest() : calc(nullptr) {
		printf("CalculatorTest()\n");
	}
	~CalculatorTest() {
		printf("~CalculatorTest()\n");
	}

	// virtual void SetUp() {
	void SetUp() override {
		printf("SetUp()\n");
		calc = new Calculator();
	}

	void TearDown() override {
		printf("TearDown()\n");
		delete calc;
		calc = nullptr;
	}
};

// xUnit Test Pattern에서 테스트 케이스를 구성하는 방법.
//  => Four Phase Test Pattern(4단계 테스트 패턴)
//  1단계: 테스트 픽스쳐를 설치하거나 실제 결과를 관찰하기 위해서 필요한 것을 집어넣는 작업을 한다. - SetUp()
//  2단계: SUT와 상호작용한다.  - TestBody()
//  3단계: 기대 결과를 단언한다.- TestBody()
//  4단계: 테스트 픽스쳐를 해체해서 테스트 시작 이전의 상태로 돌려놓는다. - TearDown()

// xUnit Test Framework이 테스트를 실행하는 흐름
//  - Test Runner
//    : RUN_ALL_TESTS();
//    => 신선한 픽스쳐 전략
//      : 픽스쳐가 망가지더라도, 이후의 테스트에 신뢰성에 영향을 주지 않는다.
//
//	  CalculatorTest* ts = new CalculatorTest;
//	  ts->SetUp();
//	  ts->Plus();
//	  ts->TearDown();
//	  delete ts;
//
//	  CalculatorTest* ts = new CalculatorTest;
//	  ts->SetUp();
//	  ts->Plus2();
//	  ts->TearDown();
//	  delete ts;


TEST_F(CalculatorTest, PressPlus_2Plus2_Display4) {
	SPEC("2 더하기 2는 4가 나오는지 검증한다.\n");
	// Act
	calc->Enter(2);
	calc->PressPlus();
	calc->Enter(2);
	calc->PressEquals();

	// Assert
	ASSERT_EQ(calc->Display(), 4) << "2 + 2 하였을 때";

	// Assertion이 실패하면, 이후의 코드는 수행되지 않습니다.
	// printf("Delete Calc\n");
	// delete calc;
}

TEST_F(CalculatorTest, Plus) {
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























































