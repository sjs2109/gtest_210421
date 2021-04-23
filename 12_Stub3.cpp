// 11_테스트대역2.cpp
#include <string>

struct IFileSystem {
	virtual ~IFileSystem() {}

	virtual bool IsValid(const std::string& filename) = 0;
};

class FileSystem : public IFileSystem {
public:
	virtual ~FileSystem() {}

	bool IsValid(const std::string& filename) override {
		// return true;
		return false;
	}
};

class Logger {
	IFileSystem* fileSystem;
public:
	Logger(IFileSystem* p = nullptr) : fileSystem(p) { 
		if (fileSystem == nullptr) {
			fileSystem = new FileSystem;
		}
	}

	bool IsValidLogFilename(const std::string& filename) {
		//------ 단위 테스트
		size_t index = filename.find_last_of(".");
		std::string name = filename.substr(0, index);
		if (name.size() < 5) {
			return false;
		}
		//-------------------

		return fileSystem->IsValid(filename);
	}
};


//------------------
#include <gmock/gmock.h>

class StubFileSystem : public IFileSystem {
public:
	MOCK_METHOD(bool, IsValid, (const std::string& filename), (override));
};

using testing::Return;
using testing::NiceMock;

TEST(LoggerTest, IsValidLogFilename_NameLoggerThan5Chars_ReturnsTrue) {
	NiceMock<StubFileSystem> fs;
	ON_CALL(fs, IsValid).WillByDefault(Return(true));
	Logger logger(&fs);
	std::string validFilename = "valid_file_name.log";

	bool actual = logger.IsValidLogFilename(validFilename);
	
	EXPECT_TRUE(actual) << "파일명이 다섯글자 이상일 때";
}

TEST(LoggerTest, IsValidLogFilename_NameShorterThan5Chars_ReturnsFalse) {
	NiceMock<StubFileSystem> fs;
	ON_CALL(fs, IsValid).WillByDefault(Return(true));
	Logger logger(&fs);
	std::string invalidFilename = "bad.log";

	EXPECT_FALSE(logger.IsValidLogFilename(invalidFilename)) << "파일명이 다섯글자 미만일 때";
}
