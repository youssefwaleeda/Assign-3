#include <iostream>
using namespace std;
const int SIZE = 10;

template <typename T>
class Queue {
private:
	int array[SIZE];
	int top = 0;

public:
	Queue() { top = -1; };

	int isEmpty() {
		if (top == -1)
			return 1;
		else
			return 0;
	}

	int isFull() {
		if (top == (SIZE - 1))
			return 1;
		else
			return 0;
	}

	int push(int a) {
		if (isFull)
			return 0;
		++top;
		array[top] = a;
		return a;
	}

	int pop() {
		int temp;
		if (isEmpty())
			return 0;
		temp = array[top];
		--top;
		return temp;
	};
	void printInfo() {
		for (int i = top; i >= top; i++) {
			cout << array[i] << " ";
			cout << endl;
		}
	}
};