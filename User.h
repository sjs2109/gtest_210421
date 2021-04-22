// User.h
#ifndef USER_H
#define USER_H

#include <gtest/gtest.h> // !!!!!!

class User {
public:
	User() : age(42) {}

	void Do() {
		age += 1;
	}

	FRIEND_TEST(UserTest, Do);  // 문제점: Google Test 의존성이 형성됩니다.
private: 
	int GetAge() const {
		return age;
	}
private:
	int age;
};

#endif
