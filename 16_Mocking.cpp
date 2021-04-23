// #include <gtest/gtest.h>
#include <gmock/gmock.h>
// : Google Mock은 Google Test에 대한 의존성이 있습니다.

struct Mp3 {
	virtual ~Mp3() {}

	virtual void Play() = 0;
	virtual void Stop(int n) = 0;

	virtual std::string GetName() const = 0;
	virtual void Foo() noexcept = 0;

	virtual std::pair<bool, int> GetPair() const = 0;
	virtual bool CheckMap(std::map<int, double> a, bool b) = 0;
};

// Mocking - 테스트 대역
// 1.10
//  - MOCK_METHOD(반환타입, 이름, (인자1, 인자2), (한정자1, 한정자2));

// 한정자
//  - override: virtual 함수(옵션)
//  - const: 필수
//  - noexcept: 필수
//  - stdcall: Windows platform(필수)

// Type aliasing
using BoolIntPair = std::pair<bool, int>;
using IntDoubleMap = std::map<int, double>;

class MockMp3 : public Mp3 {
public:
	MOCK_METHOD(bool, CheckMap, (IntDoubleMap a, bool b), (override));
	MOCK_METHOD(BoolIntPair, GetPair, (), (const, override));
	
	// 템플릿 인자가 두 개 이상인 경우, 괄호가 필요합니다.
	// MOCK_METHOD(bool, CheckMap, ((std::map<int, double> a), bool b), (override));
	// MOCK_METHOD((std::pair<bool, int>), GetPair, (), (const, override));

	// std::string GetName() const override {}
	MOCK_METHOD(std::string, GetName, (), (const, override));

	// void Foo() noexcept override {}
	MOCK_METHOD(void, Foo, (), (noexcept, override));

	// void Play() override {}
	// MOCK_METHOD(void, Play, ());
	MOCK_METHOD(void, Play, (), (override));
	
	// void Stop(int n) override {}
	MOCK_METHOD(void, Stop, (int n), (override));
};

TEST(Mp3Test, Sample) {
	MockMp3 mock;      // !
}






