
// SUT
class User {
private:
	int age;
public:
	User() : age(42) {}

	void Do() {
		age += 1;
	}

protected: 
	int GetAge() const {
		return age;
	}
};

//------------
#include <gtest/gtest.h>
// 접근하는 속성이 protected 인 경우
//  => 테스트 전용 하위 클래스

class TestUser : public User {
public:
	using User::GetAge;  // protected ->public
};

TEST(UserTest, Do) {
	// User user;
	TestUser user;

	user.Do();

	EXPECT_EQ(43, user.GetAge());
}
