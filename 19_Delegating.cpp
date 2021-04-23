#include <stdio.h>

struct Calc {
	virtual ~Calc() {}

	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
};

void UseCalc(Calc* p) {
	// printf("Add: %d\n", p->Add(10, 20));
	// printf("Sub: %d\n", p->Sub(30, 20));

	if (p->Add(10, 20) == 30) {
		printf("Sub: %d\n", p->Sub(30, 20));
	}
}

#include <gmock/gmock.h>

// 모의 객체는 행위 기반 검증을 위해서도 사용할 수 있지만,
// 모킹된 메소드의 결과를 제어하는 것도 가능합니다.
//  => Stub / Fake 를 구현하는 목적으로도 사용할 수 있습니다.
class MockCalc : public Calc {
public:
	MOCK_METHOD(int, Add, (int a, int b), (override));
	MOCK_METHOD(int, Sub, (int a, int b), (override));
};

// ON_CALL => 결과 제어
//  - WillByDefault(Return(30));
using testing::Return;

TEST(CalcTest, UseCalc) {
	MockCalc mock;
	ON_CALL(mock, Add).WillByDefault(Return(30));
	
	EXPECT_CALL(mock, Add);
	EXPECT_CALL(mock, Sub(30, 20));
	
	UseCalc(&mock);
}




