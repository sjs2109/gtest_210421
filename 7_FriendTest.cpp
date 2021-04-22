
// SUT
class User {
private:
	int age;
public:
	User() : age(42) {}

	void Do() {
		age += 1;
	}

protected: // ??
private:   // ??
	int GetAge() const {
		return age;
	}
};

//------------

#include <gtest/gtest.h>

TEST(UserTest, Do) {
	User user;

	user.Do();

	EXPECT_EQ(43, user.GetAge());
}

