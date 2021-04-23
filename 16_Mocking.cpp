// #include <gtest/gtest.h>
#include <gmock/gmock.h>
// : Google Mock은 Google Test에 대한 의존성이 있습니다.

struct Mp3 {
	virtual ~Mp3() {}

	virtual void Play() = 0;
	virtual void Stop(int n) = 0;
};

// Mocking - 테스트 대역
// 1.10
//  - MOCK_METHOD(반환타입, 이름, (인자1, 인자2), (한정자1, 한정자2));

// 한정자
//  - override: virtual 함수(옵션)

class MockMp3 : public Mp3 {
public: // !
	// void Play() override {}
	// MOCK_METHOD(void, Play, ());
	MOCK_METHOD(void, Play, (), (override));
	
	// void Stop(int n) override {}
	MOCK_METHOD(void, Stop, (int n), (override));
};

TEST(Mp3Test, Sample) {
	MockMp3 mock;      // !
}






