// 12_Stub.cpp
#include <iostream>

class NetworkException : public std::exception {
public:
	const char* what() {
		return "Bad Network State...";
	}
};

struct IConnection {
	virtual ~IConnection() {}

	virtual void Move(int x, int y) = 0;
};

class TCPConnection : public IConnection {
public:
	void Move(int x, int y) override {
		// Move 패킷을 만들어서 서버로 전송한다.
	}
};

class Player {
	IConnection* conn;
public:
	Player(IConnection* p) : conn(p) {}

	void Move(int x, int y) {
		try {
			conn->Move(x, y);
			// ....
		} catch (NetworkException& e) {
			printf("NetworkException 처리 로직\n");
			throw e;
		}
	}
};

//------------
#include <gtest/gtest.h>

// Test Stub Pattern
//  의도: '다른 컴포넌트로부터의 간접 입력'에 의존하는 로직을 독립적으로 검증하고 싶다.
//  방법: 실제 의존하는 객체를 테스트용 객체로 교체해서, SUT가 테스트하는데 필요한 결과를 보내도록 제어한다.
//  => 특수한 상황을 시뮬레이션 하고 싶다.
//    : 예외, 반환값, 시간 등의 제어가 불가능한 환경을 제어하기 위한 목적으로 사용합니다.

// 테스트 대역
class StubConnection : public IConnection {
public:
	void Move(int x, int y) override {
		throw NetworkException();
	}
};

// 의존성 주입
//  => 제품 코드를 사용하는 방식 그대로 테스트 코드를 작성할 수 있습니다.

// Player의 Move가 호출되었을 때, NetworkException이 발생한다면,
// NetworkException이 외부로 전파되는지 여부를 검증하고 싶다.
TEST(PlayerTest, Move) {
	StubConnection conn; // !!!
	Player player(&conn);

	EXPECT_THROW(player.Move(10, 20), NetworkException);
}

#if 0
TEST(PlayerTest, Move) {
	TCPConnection conn;
	Player player(&conn);

	EXPECT_THROW(player.Move(10, 20), NetworkException);
}
#endif

















