
#include <string>

struct Time {
	virtual ~Time() {}

	virtual std::string GetCurrentTime() = 0;
};

class Clock : public Time {
public:
	std::string GetCurrentTime() override {
		// 현재 시간을 문자열로 변경해서 반환한다.
		return "15:07";
	}
};

class User {
	Time* time;
public:
	User(Time* p) : time(p) {}

	int Display() {
		std::string t = time->GetCurrentTime();
		if (t == "00:00") {
			return 42;
		}

		return 0;
	}
};

//----------
// User의 Display를 호출하였을 때,
// 00시 00분에 42를 반환하는지 여부를 검증하고 싶다.
#include <gtest/gtest.h>

class StubTime : public Time {
public:
	std::string GetCurrentTime() override {
		return "00:00";
	}
};

TEST(UserTest, Display) {
	StubTime c;
	// Clock c;
	User user(&c);

	EXPECT_EQ(user.Display(), 42) << "00:00분에 수행하였을 때";
}

