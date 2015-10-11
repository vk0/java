class A {
public:
	A() {
		init();
	}
	void init() {
		crash();
	}
	virtual void crash() = 0;
};

class B : public A {
public:
	B() : A() {}
	virtual void crash() {
		//something
	}
};

int main() {
	B b;
}
