// 3_스위트픽스쳐2.cpp
#include <string>
#include <unistd.h> // sleep

class Database {
public:
	// 가정: Connect() / Disconnect()가 느리다.
	void Connect() { sleep(2); }
	void Disconnect() { sleep(2); }

	void Login(const std::string& id, const std::string& password) {}
	void Logout() {}

	bool IsLogin() { return true; }
};

//--------------------
#include <gtest/gtest.h>

// 문제점: 픽스쳐를 설치하거나 해체하는 과정으로 인해 "느린 테스트"의 문제가 발생하였다.
//  해결방법 => 스위트 픽스쳐(Suite Fixture)
//
//  문제점: 스위트 픽스쳐 설치 / 해체의 기능을 이용하면 
//           더 이상 독립적인 테스트 케이스가 아닙니다.
//         "신선한 픽스쳐 전략" -> "공유 픽스쳐 전략"
//
//         각각의 테스트 케이스는 더 빠르게 동작하지만, 공유 픽스쳐가 망가지면, 
//         "변덕스러운 테스트" 문제가 발생할 수 있습니다.
//         => 공유 픽스쳐의 상태에 따라서 테스트의 결과가 변경됩니다.
//          "신뢰성"에 문제가 생깁니다.

#if 0
//----------
<Suite Fixture SetUp> - static
DatabaseTest* ts = new DatabaseTest;
ts->SetUp();
ts->Login();
ts->TearDown();
delete ts;

DatabaseTest* ts = new DatabaseTest;
ts->SetUp();
ts->Logout();
ts->TearDown();
delete ts;
<Suite Fixture TearDown> - static
//----------
#endif

// 25TC * 4 = 100 sec
//  - Slow Test(느린 테스트): 테스트 냄새
//  : 테스트가 느려서 테스트를 수행하는 개발자의 생산성을 떨어뜨린다.
//    테스트가 느려서 코드가 변경되어도 테스트를 수행하지 않는다.

class DatabaseTest : public testing::Test {
protected:
	// 1.10 이전
#if 0
	static void SetUpTestCase() {
		printf("SetUpTestCase\n");
	}
	static void TearDownTestCase() {
		printf("TearDownTestCase\n");
	}
#endif
	// 1.10 이후
	static void SetUpTestSuite() {
		printf("SetUpTestSuite\n");
		database = new Database;
		database->Connect();
	}
	static void TearDownTestSuite() {
		printf("TearDownTestSuite\n");
		database->Disconnect();
		delete database;
	}

	static Database* database;
	// DatabaseTest() : database(nullptr) {}

	void SetUp() override {
		// database = new Database;
		// database->Connect();
	}

	void TearDown() override {
		// database->Disconnect();
		// delete database;
	}
};

Database* DatabaseTest::database = nullptr;

TEST_F(DatabaseTest, Login) {
	database->Login("test_id", "test_password");
	
	ASSERT_TRUE(database->IsLogin()) << "로그인 하였을 때";
}

TEST_F(DatabaseTest, Logout) {
	database->Login("test_id", "test_password");
	database->Logout();
	
	ASSERT_FALSE(database->IsLogin()) << "로그아웃 하였을 때";
}

