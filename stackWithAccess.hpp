#include <cstddef>
#include <memory>

struct stackElem {
	std::unique_ptr<stackElem> ptr;
	int val;
};

class stack {
private:
	std::unique_ptr<stackElem> top;
	size_t size;
	static const size_t max_size = 1000;
public:
	stack();
	~stack();
	void push(int v);
	int pop();
	int& operator[] (size_t index);
	const int& operator[] (size_t index) const;
	const size_t getSize() const;
};

struct stackfElem {
	std::unique_ptr<stackfElem> ptr;
	float val;
};

class stackf {
private:
	std::unique_ptr<stackfElem> top;
	size_t size;
	static const size_t max_size = 1000;
public:
	stackf();
	~stackf();
	void push(float v);
	float pop();
	float& operator[] (size_t index);
	const float& operator[] (size_t index) const;
	const size_t getSize() const;
};
