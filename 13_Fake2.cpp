#include <string>

class User {
	std::string name;
	int age;
public:
	User(const std::string& n, int a) : name(n), age(a) {}

	std::string GetName() const {
		return name;
	}

	int GetAge() const {
		return age;
	}
};
struct IDatabase {
	virtual ~IDatabase() {}

	virtual void SaveUser(const std::string& name, User* user) = 0;
	virtual User* LoadUser(const std::string& name) = 0;
};

class UserManager {
	IDatabase* database;
public:
	UserManager(IDatabase* p) : database(p) {}

	void Save(User* p) {
		database->SaveUser(p->GetName(), p);
	}

	User* Load(const std::string& name) {
		return database->LoadUser(name);
	}

	bool IsExist(const std::string& name) {
		return Load(name) != nullptr;
	}
};
//---------
#include <gmock/gmock.h>
#include <map>

// 문제: IDatabase의 구현체가 아직 준비되지 않았다.

class FakeDatabase : public IDatabase {
	std::map<std::string, User*> data;
public:
	MOCK_METHOD(void, SaveUser, (const std::string& name, User* user), (override));
	MOCK_METHOD(User*, LoadUser, (const std::string& name), (override));

	FakeDatabase() {
		ON_CALL(*this, SaveUser).WillByDefault([this](const std::string& name, User* user) {
			SaveUserImpl(name, user);
		});
		ON_CALL(*this, LoadUser).WillByDefault([this](const std::string& name) {
			return LoadUserImpl(name);
		});
	}

private:
	void SaveUserImpl(const std::string& name, User* user) {
		data[name] = user;
	}

	User* LoadUserImpl(const std::string& name) {
		return data[name];
	}
};

static bool operator==(const User& lhs, const User& rhs) {
	return lhs.GetName() == rhs.GetName() &&
		lhs.GetAge() == rhs.GetAge();
}
static bool operator!=(const User& lhs, const User& rhs) {
	return !(lhs == rhs);
}

static std::ostream& operator<<(std::ostream& os, const User& user) {
	return os << "User{name=" << user.GetName() << ", age=" << user.GetAge() << "}"; 
}

using testing::NiceMock;

TEST(UserManagerTest, Load) {
	NiceMock<FakeDatabase> db;
	UserManager manager(&db);
	std::string name = "test_name";
	int age = 100;
	User expected(name, age);
	
	manager.Save(&expected);
	User* actual = manager.Load(name);

	ASSERT_NE(actual, nullptr);
	EXPECT_EQ(*actual, expected) << "Load 하였을 때";
}

TEST(UserManagerTest, Load2) {
	NiceMock<FakeDatabase> db;
	UserManager manager(&db);
	std::string name = "test_name";
	int age = 100;
	User expected(name, age);

	EXPECT_CALL(db, SaveUser);
	EXPECT_CALL(db, LoadUser);
	
	manager.Save(&expected);
	User* actual = manager.Load(name);
}

TEST(UserManagerTest, IsExist) {
	NiceMock<FakeDatabase> db;
	UserManager manager(&db);
	std::string name = "test_name";
	int age = 100;
	User expected(name, age);
	
	manager.Save(&expected);

	EXPECT_TRUE(manager.IsExist(name)) << "Save 하였을 때";
}

