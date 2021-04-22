
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
		// engine->Start();
		// ...
	}
};

//----------
#include <gtest/gtest.h>

// 테스트 전용 하위 클래스 패턴(Test Specific Subclass Pattern)
//  의도: SUT의 클래스가 테스트를 위한 기능을 제공하지 있지 않다면,
//        테스트 코드 안에서 자식 클래스를 통해 해당 기능을 제공하면 됩니다.
//        => 기능을 재사용(virtual 함수)
class TestEngine : public Engine {
	bool isStart;
public:
	TestEngine() : isStart(false) {}

	void Start() override {
		Engine::Start();     // 부모의 기능을 재사용한다.
		isStart = true;
		// printf("TestEngine Start\n");
	}

	bool IsStart() const {
		return isStart;
	}
};

// Car의 Go를 호출하였을 때, Engine의 Start가 제대로 호출되는지 여부를 검증하고 싶다.
TEST(CarTest, Go) {
	// Engine engine;
	TestEngine engine;
	Car car(&engine);

	car.Go();

	// engine 객체에 상태를 검증하기 위한 기능이 제공되지 않는다.
	EXPECT_TRUE(engine.IsStart()) << "Car가 Go 했을 때";
}














