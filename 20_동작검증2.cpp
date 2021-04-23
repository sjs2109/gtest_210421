struct Calc {
	virtual ~Calc() {}

	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
};

void UseCalc(Calc* p) {
	printf("Add: %d\n", p->Add(10, 20));
	printf("Sub: %d\n", p->Sub(30, 20));

#if 0
	if (p->Add(10, 20) == 30) {
		printf("Sub: %d\n", p->Sub(30, 20));
	}
#endif
}

#include <gmock/gmock.h>

class MockCalc : public Calc {
public:
	MOCK_METHOD(int, Add, (int a, int b), (override));
	MOCK_METHOD(int, Sub, (int a, int b), (override));
};

// ON_CALL / EXPECT_CALL 을 같이 사용하고 있다면,
//  => ON_CALL을 사용할 필요가 없습니다.
//  => EXPECT_CALL을 통해 결과를 제어하는 것이 가능합니다.

TEST(CalcTest, UseCalc) {
	MockCalc mock;
	ON_CALL(mock, Add).WillByDefault(Return(30));
	ON_CALL(mock, Sub).WillByDefault(Return(10));
	
	EXPECT_CALL(mock, Add);
	EXPECT_CALL(mock, Sub(30, 20));
	
	UseCalc(&mock);
}






