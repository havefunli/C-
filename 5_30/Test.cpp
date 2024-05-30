#include"priority_queue.h"

// 仿函数 / 函数对象
// 它的对象可以向函数一样的去使用

template<class T>
struct Less {
public:
	bool operator()(const T& left, const T& right) {
		return left < right;
	}
};

void test_1() {
	int A = 1;
	int B = 2;

	Less<int> lessfuc;
	cout << lessfuc(A, B) << endl;
	cout << lessfuc.operator()(A, B) << endl;
	cout << Less<int>()(A, B) << endl;
	cout << Less<int>().operator()(A, B) << endl;
}

void test_3() {
	LQ::priority_queue<int> pq;
	pq.push(6);
	pq.push(3);
	pq.push(1);
	pq.push(5);

	priority_queue<int> pq1;
	cout << pq1.top() << endl;
}

void test_4() {
	LQ::priority_queue<int> pq;
	pq.push(1);
	pq.push(2);
	pq.push(4);
	pq.push(4);
	pq.push(4);
	pq.push(3);
	pq.push(4);
	pq.push(5);

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

int main() {
	// test_1();
	// test_2();
	// test_3();
	test_4();

	return -1;
}