#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <string>
#include<iostream>
#include<assert.h>
using namespace std;

namespace my_Space
{
	class String
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin();
		iterator end();

		const_iterator begin() const;
		const_iterator end() const;

		//string();
		String(const char* str = "");
		String(const String& s);
		String& operator=(const String& s);
		~String();

		const char* c_str() const;

		size_t size() const;
		char& operator[](size_t pos);
		const char& operator[](size_t pos) const;

		void reserve(size_t n);

		void push_back(char ch);
		void append(const char* str);

		String& operator+=(char ch);
		String& operator+=(const char* str);

		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* str);
		void erase(size_t pos = 0, size_t len = npos);

		size_t find(char ch, size_t pos = 0);
		size_t find(const char* str, size_t pos = 0);

		void swap(string& s);
		string substr(size_t pos = 0, size_t len = npos);

		bool operator<(const string& s) const;
		bool operator>(const string& s) const;
		bool operator<=(const string& s) const;
		bool operator>=(const string& s) const;
		bool operator==(const string& s) const;
		bool operator!=(const string& s) const;
		
		void clear();

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		const static size_t npos;
	};

	istream& operator>> (istream& is, String& str);
	ostream& operator<< (ostream& os, const String& str);
}

