#include <stdio.h>

struct Calc {
	virtual ~Calc() {}

	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
};

#include <gmock/gmock.h>

class MockCalc : public Calc {
public:
	MOCK_METHOD(int, Add, (int a, int b), (override));
	MOCK_METHOD(int, Sub, (int a, int b), (override));
};

// ON_CALL / EXPECT_CALL 을 같이 사용하고 있다면,
//  => ON_CALL을 사용할 필요가 없습니다.
//  => EXPECT_CALL을 통해 결과를 제어하는 것이 가능합니다.
//  1. WillOnce
//  2.

// 횟수
//  1. WillOnce + WillOnce + WillOnce  => Times(3)

void UseCalc(Calc* p) {
	printf("Add: %d\n", p->Add(10, 20));
	printf("Add: %d\n", p->Add(10, 20));
	printf("Add: %d\n", p->Add(10, 20));
	printf("Add: %d\n", p->Add(10, 20));
	printf("Add: %d\n", p->Add(10, 20));
	// printf("Sub: %d\n", p->Sub(30, 20));
}

using testing::Return;
TEST(CalcTest, UseCalc) {
	MockCalc mock;
	
	EXPECT_CALL(mock, Add)
		.WillOnce(Return(30))
		.WillOnce(Return(20))
		.WillOnce(Return(10))
		.WillOnce(Return(20))
		.WillOnce(Return(30));

	// EXPECT_CALL(mock, Sub(30, 20))
	//	.WillOnce(Return(10));
	
	UseCalc(&mock);
}






