
// SUT
#if 0
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
#endif

//------------
// GetAge() 가 private인 경우
//  : 절대 사용하면 안되는 접근 방식입니다.
//  => pImpl idiom(컴파일러 방화벽)은 위의 접근을 막을 수 있습니다.
// #define class struct
// #define private public
#include "User.h"
// #undef class
// #undef private

// => Frined Test를 이용해서 해결해야 합니다.
//  : Google Test 의존성이 형성됩니다.

//---------
//  로버트 C 마틴 - Clean Code
//   => private 메소드는 public 메소드의 가독성을 높이기 위해 사용해야 한다.
//   => public 메소드를 통해 호출되지 않는 private 메소드는 잘못된 설계이다.
//
//   "테스트 되지 않은 private 메소드가 테스트 된 public 메소드보다 위험하다."


#include <gtest/gtest.h>

TEST(UserTest, Do) {
	User user;

	user.Do();

	EXPECT_EQ(43, user.GetAge());
}







