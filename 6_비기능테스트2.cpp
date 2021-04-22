#include <gtest/gtest.h>

// 객체의 메모리 누수를 판단하는 목적으로 테스트를 이용할 수 있습니다.
// 1) 제품 코드에 미리 정의되어야 하는 코드가 있습니다.
//  => new / delete 연산자 재정의가 필요합니다.

//  Image* image = new Image;
//   1) 메모리 할당 - operator new        - *
//   2) 생성자 함수 호출
//
//  delete image;
//   2) 메모리 해지 - operator delete    - *
// 2) 조건부 컴파일 등을 통해 테스트에서만 적용되도록 하는 것이 좋습니다.

//-------
class Image {
public:
#ifdef GTEST_LEAK_TEST
	static int allocCount;

	void* operator new(size_t size) {
		++allocCount;
		return malloc(size);
	}

	void operator delete(void* p, size_t) {
		--allocCount;
		free(p);
	}
#endif

	void Draw() {
		printf("Image draw\n");
	}
};

#ifdef GTEST_LEAK_TEST
int Image::allocCount = 0;
#endif

void DrawImage() {
	Image* p1 = new Image; 
	Image* p2 = new Image;
	Image* p3 = new Image;
	// image->Draw();
	
	delete p2;
	delete p3;
}
//------

//---------
class ImageTest : public testing::Test {
protected:
#ifdef GTEST_LEAK_TEST
	int alloc;
#endif

	ImageTest() {
#ifdef GTEST_LEAK_TEST
		alloc = 0;
#endif
	}

	void SetUp() override {
#ifdef GTEST_LEAK_TEST
		alloc = Image::allocCount;
#endif
	}

	void TearDown() override {
#ifdef GTEST_LEAK_TEST
		int diff = Image::allocCount - alloc;
		EXPECT_EQ(diff, 0) << diff << " Object(s) leaks";
#endif
	}
};

TEST_F(ImageTest, DrawImage) {
	DrawImage();
}













