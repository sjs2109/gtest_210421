
#include <gmock/gmock.h>

struct Element {};

class Calc {
	int x;
public:
	virtual ~Calc() {}

	virtual int Add(Element x) {}
	virtual int Add(int times, Element) {}
};

class User {
public:
	void Add(Calc* p) {
		p->Add(10, Element{});
		p->Add(Element{});
	}
};
