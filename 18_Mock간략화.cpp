
enum Level {
	INFO, WARN, ERROR,
};

struct Logger {
	virtual ~Logger() {}

	virtual void Send(Level level, const char* filename, const char* dir, int line) = 0;
};

class User {
public:
	void Do(Logger* logger) {
		// logger->Send(INFO, "user.txt", "/tmp", 42);
	}
};

//-------------------
#include <gmock/gmock.h>

class MockLogger : public Logger {
public:
	// MOCK_METHOD(void, Send, (Level level, const char* filename, const char* dir, int line), (override));
	void Send(Level level, const char* filename, const char* dir, int line) override {
		// MOCK_METHOD를 통해 생성한 함수를 호출한다.
		Send(level);
	}

	MOCK_METHOD(void, Send, (Level level));
};

TEST(UserTest, Do) {
	MockLogger mock;
	User user;

	EXPECT_CALL(mock, Send(INFO));

	user.Do(&mock);
}

#if 0
class MockLogger : public Logger {
public:
	MOCK_METHOD(void, Send, (Level level, const char* filename, const char* dir, int line), (override));
};


TEST(UserTest, Do) {
	MockLogger mock;
	User user;

	EXPECT_CALL(mock, Send(INFO, "user.txt", "/tmp", 42));

	user.Do(&mock);
}
#endif
