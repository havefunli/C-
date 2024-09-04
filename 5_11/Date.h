#pragma once

#include <iostream>
using namespace std;

// �������أ������ú�������ͬ��������ͬ�ĺ�������
// ��������أ����Զ������Ϳ���ʹ����������������������Ϊ����ǿ�ɶ���
// ���ͬһ��������ؿ��Թ��ɺ�������

class Date {
public:

	int getMonthDay(int year, int month) {
		static int MonthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2) {
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
				return 29;
			}
			else {
				return 28;
			}
		}

		return MonthDay[month];
	}

	Date(const int year = 1, const int month = 1, const int day = 1);

	Date(const Date& origin);

	~Date();

	void Print() const;

	Date operator=(const Date& D);

	// ==
	bool operator==(const Date& D) const;

	// >
	bool operator>(const Date& D) const;

	// >= 
	bool operator>=(const Date& D) const;

	// <
	bool operator<(const Date& D) const;

	// <=
	bool operator<=(const Date& D) const;

	// != 
	bool operator!=(const Date& D) const;

	// += / +
	Date& operator+=(const int day);
	Date operator+(const int day);

	// -= / -
	Date& operator-=(const int day);
	Date operator-(const int day);

	// Date++ / ++Date
	Date& operator++(int);
	Date& operator++();

	// Date-- / --Date
	Date& operator--(int);
	Date& operator--();

	// d1 - d2;
	int operator-(const Date& right) const;

private:
	int _year;
	int _month;
	int _day;
};