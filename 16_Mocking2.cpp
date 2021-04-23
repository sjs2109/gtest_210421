
#include <gmock/gmock.h>

struct Element {};

class Calc {
	int x;
public:
	virtual ~Calc() {}

	// 행위 기반 검증 대상이 아닙니다.
	virtual int Add(Element x) {}

	// 행위 기반 검증 대상
	virtual int Add(int times, Element x) {}
};

class User {
public:
	void Add(Calc* p) {
		// p->Add(10, Element{});
	}
};
//------------------
// 의존하는 객체가 상속 가능한 클래스라면, Google Mock을 통해 행위기반 검증을 수행하 수 있습니다.
class MockCalc : public Calc {
public:
	MOCK_METHOD(int, Add, (int times, Element x), (override));
};

TEST(UserTest, Add) {
	User user;
	MockCalc calc;

	EXPECT_CALL(calc, Add);
	
	user.Add(&calc);
}

























