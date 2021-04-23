#include <stdio.h>

class Engine {
public:
	Engine() {}
	virtual ~Engine() {}

	virtual void Start() {
		printf("Engine Start...\n");
	}
};

class Car {
	Engine* engine;
public:
	Car(Engine* p) : engine(p) {}

	void Go() {
		// ...
		engine->Start();
		// ...
	}
};

//----------
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class TestEngine : public Engine {
public:
	MOCK_METHOD(void, Start, (), (override));
};

// Car의 Go를 호출하였을 때, Engine의 Start가 제대로 호출되는지 여부를 검증하고 싶다.
TEST(CarTest, Go) {
	TestEngine engine;
	Car car(&engine);

	EXPECT_CALL(engine, Start);

	car.Go();
}














