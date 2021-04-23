

struct User {
	virtual ~User() {}

	virtual void Go() = 0;
	virtual void Say() = 0;
};

void UseUser(User* p) {
	p->Go();
	p->Say();
}
//---------
#include <gmock/gmock.h>

class MockUser : public User {
public:
	MOCK_METHOD(void, Go, (), (override));
	MOCK_METHOD(void, Say, (), (override));
};

#if 0
GMOCK WARNING:
Uninteresting mock function call - returning directly.
    Function call: Say()
#endif
// UseUser에서 User에 대하여 Go가 제대로 호출되는지 여부를 검증하고 싶다.
TEST(UserTest, UseUser) {
	MockUser mock;

	EXPECT_CALL(mock, Go);

	UseUser(&mock);
}
