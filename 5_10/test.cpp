#include <iostream>
using namespace std;

// :: ?: sizeof .* . 不可以重载
// 赋值重载不要写为全局的，其他运算符重载可以
// 内联申明和定义不可以分离

class Date {
public:

	int getMonthDay(int year, int month) {
		//
	}

	Date(const int year = 0, const int month = 0, const int day = 0) {
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& origin) {
		_year = origin._year;
		_month = origin._month;
		_day = origin._day;
	}

	~Date() {
		cout << "~Date()" << endl;
	}

	void show_info() {
		cout << _year << '-' << _month << '-' << _day << endl;
	}

	Date& operator=(const Date& D) {
		_year = D._year;
		_month = D._month;
		_day = D._day;

		return *this;
	}

	bool operator==(const Date& D) {
		if ((this->_year == D._year)
			&& (this->_month == D._month)
			&& (this->_day == D._day)) return true;
		else return false;
	}

private:
	int _year;
	int _month;
	int _day;
};

// 会出现一个问题，不可以访问对象的私有变量
//bool operator==(const Date& left, const Date& right) {
//	if ((left._year == right._year)
//		&& (left._month == right._month)
//		&& (left._day == right._day)) return true;
//	else return false;
//}

int main() {
	// cout << sizeof(Date) << endl;

	// 拷贝构造，将一个存在的对象拷贝给一个初始化的对象
	Date d1(2024, 5, 1);
	Date d2(d1);

	// 赋值重载，为两个都存在的对象
	d1 = d2;
}