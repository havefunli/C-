#include <iostream>
using namespace std;

// :: ?: sizeof .* . ����������
// ��ֵ���ز�ҪдΪȫ�ֵģ�������������ؿ���
// ���������Ͷ��岻���Է���

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

// �����һ�����⣬�����Է��ʶ����˽�б���
//bool operator==(const Date& left, const Date& right) {
//	if ((left._year == right._year)
//		&& (left._month == right._month)
//		&& (left._day == right._day)) return true;
//	else return false;
//}

int main() {
	// cout << sizeof(Date) << endl;

	// �������죬��һ�����ڵĶ��󿽱���һ����ʼ���Ķ���
	Date d1(2024, 5, 1);
	Date d2(d1);

	// ��ֵ���أ�Ϊ���������ڵĶ���
	d1 = d2;
}