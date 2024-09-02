#include "List.h"

void test_1() {
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);

	auto it = lt.begin();
	*it += 1;
	
	for (auto e : lt) {
		cout << e << " ";
	}
	cout << endl;
}

void test_2() {
	my_list::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);

	lt.push_front(4);
	lt.push_front(5);
	lt.push_front(6);

	my_list::list<int>::iterator it = lt.begin();
	my_list::list<int>::iterator end = lt.end();
	for (auto e : lt) {
		cout << e << " ";
	}
	cout << endl;
}

void test_3() {
	my_list::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_front(4);
	lt.push_front(5);
	lt.push_front(6);

	lt.pop_back();
	lt.pop_back();
	lt.pop_front();
	lt.pop_front();

	for (auto e : lt) {
		cout << e << " ";
	}
	cout << endl;
}

void test_4(){
	my_list::list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);

	my_list::list<int> lt2;
	lt2 = lt1;
	for (auto e : lt2) {
		cout << e << " ";
	}
	cout << endl;
}

void test_5() {
	my_list::list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	
	const my_list::list<int> lt2 = lt1;

	my_list::list<int>::const_iterator it = lt2.begin();
	cout << *it << endl;
}

void test_6() {
	my_list::list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);

	my_list::list<int> lt2(lt1.begin(), lt1.end());
	for (auto e : lt2) {
		cout << e << " ";
	}
	cout << endl;
}

void test_7() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	auto it = v.begin();

	cout << *it << endl;
}

void test_8() {
	my_list::list<int> lt;
	lt.push_front(1);
	lt.push_front(2);
	lt.push_front(3);
	for (auto e : lt) {
		cout << e << " ";
	}
	cout << endl;

	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);
	for (auto e : lt) {
		cout << e << " ";
	}
	cout << endl;
	
	lt.pop_back();
	lt.pop_back();
	lt.pop_back();
	for (auto e : lt) {
		cout << e << " ";
	}
	cout << endl;
}

void test_9() {
	list<int> lt;
	lt.push_front(1);
	lt.push_front(2);
	lt.push_front(3);

	list<int>::const_iterator it = lt.begin();
	it++;
	cout << *it << endl;
}

int main() {
	// test_1();
	// test_2();
	// test_3();
	// test_4();
	// test_5();
	// test_6();
	// test_7();
	// test_8();
	test_9();
	return 0;
}