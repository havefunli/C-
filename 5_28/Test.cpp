#include "stack_queue.h"

void test_1() {
	LQ::stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	cout << st.size() << endl;

	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}
void test_2() {
	LQ::queue<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	cout << st.size() << endl;

	while (!st.empty()) {
		cout << st.front() << " ";
		st.pop();
	}
	cout << endl;
}

int main() {
	// test_1();
	test_2();
	return -1;
}