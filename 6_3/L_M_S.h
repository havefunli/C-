#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

namespace mySpace{
	extern string path;

	// 图书
	class Book {
	public:
		Book(string name, string cate, string intro, double price, size_t date);

		friend ostream& operator<<(ostream&, const Book& book);

		friend void del_book();
		friend void save_File();
		friend bool Book_query();
		friend void modify_book();


		friend bool cmp_letter(const Book& left, const Book& right);
		friend bool cmp_price(const Book& left, const Book& right);
		friend bool cmp_date(const Book& left, const Book& right);
		friend void Book_sort();

	private:
		string _name; // 书名
		string _cate; // 类别
		string _intro; // 简介
		double _price; // 价格
		size_t _date; // 日期
	};
	ostream& operator<<(ostream&, const Book& book);

	extern list<Book> lt;

	void Main_menu();
	void book_menu();
	void sort_menu();

	void add_book();
	void del_book();
	void modify_book();
	void Library_management();

	void read_File();
	void save_File();

	bool Book_query();
	void Book_sort();
	void view_all_book();

	bool cmp_letter(const Book& left, const Book& right);
	bool cmp_price(const Book& left, const Book& right);
	bool cmp_date(const Book& left, const Book& right);

	void sort_by_letter();
	void sort_by_price();
	void sort_by_date();
}

