#pragma once
#include <assert.h>
using namespace std;

namespace Demo {
	class string {
	friend ostream& operator<<(ostream& _cout, const Demo::string& s);
	friend istream& operator>>(istream& _cin, Demo::string& s);

	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin() {
			return _str;
		}

		iterator end() {
			return _str + _size;
		}

		const_iterator begin() const {
			return _str;
		}

		const_iterator end() const {
			return _str + _size;
		}

		string(const string& s) {
			_str = new char[s._capacity + 1];
			memcpy(_str, s._str, s._size + 1);
			_size = s._size;
			_capacity = s._capacity;
		}

		string(const char* ch = "") {
			_str = new char[strlen(ch) + 1];
			memcpy(_str, ch, strlen(ch) + 1);
			_size = strlen(ch);
			_capacity = _size;
		}

		~string() {
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}

		void swap(string& s) {
			std::swap(_str, s._str);
			std::swap(_size,s._size);
			std::swap(_capacity, s._capacity);
		}

		string& operator=(string temp) {
			swap(temp);

			return *this;
		}

		const char* c_str() const {
			return _str;
		}

		size_t size() const {
			return _size;
		}

		const char& operator[](size_t pos) const {
			assert(_size > pos);

			return _str[pos];
		}

		char& operator[](size_t pos) {
			assert(_size > pos);

			return _str[pos];
		}

		void resever(size_t n) {
			if (n > _capacity) {
				char* temp = new char[n + 1];

				memcpy(temp, _str, _size + 1);
				delete[] _str;
				_str = temp;
				_capacity = n;
			}
		}

		void resize(size_t n, char ch = '\0') {
			if (n < _size) {
				_size = n;
				_str[_size] = '\0';
			}
			else {
				resever(n);

				for (size_t i = _size; i < n; i++){
					_str[i] = ch;
				}
				_str[n] = '\0';
				_size = n;
			}
		}

		void push_back(char ch) {
			if (_size = _capacity) {
				resever(_capacity == 0 ? 4 : 2 * _capacity);
			}

			_str[_size++] = ch;
			_str[_size] = '\0';
		}

		void append(const char* str) {
			size_t len = strlen(str);

			if (_size + len > _capacity) {
				resever(_size + len);
			}

			memcpy(_str + _size, str, len + 1);
			_size += len;
		}

		string& operator+=(char ch) {
			push_back(ch);

			return *this;
		}

		string& operator+=(const char* s) {
			append(s);

			return *this;
		}

		void insert(size_t pos, size_t n, char ch) {
			assert(_size >= pos);

			if (_size + n > _capacity) {
				resever(_size + n);
			}

			size_t end = _size;
			while (end >= pos && end != npos) {
				_str[end + n] = _str[end];
				end--;
			}

			for (size_t i = pos; i < pos + n; i++){
				_str[i] = ch;
			}
			_size += n;
		}

		void insert(size_t pos, const char* str) {
			assert(pos <= _size);

			size_t len = strlen(str);
			if (_size + len > _capacity) {
				resever(_size + len);
			}

			size_t end = _size;
			while (end >= pos && end != npos) {
				_str[end + len] = _str[end];
				end--;
			}

			for (size_t i = 0; i < len; i++) {
				_str[i + pos] = str[i];
			}
			_size += len;
		}

		void erase(size_t pos, size_t len = npos) {
			assert(pos <= _size);

			if (len == pos || pos + len >= _size) {
				_size = pos;
				_str[_size] = '\0';
			}
			else {
				size_t end = pos + len;

				while (end <= _size) {
					_str[pos++] = _str[end++];
				}
				_size -= len;
			}
		}

		size_t find(char ch, size_t pos = 0){
			assert(pos < _size);

			for (size_t  i = pos; i < _size; i++) {
				if (ch == _str[i])
					return i;
				return npos;
			}
		}

		size_t find(const char* str, size_t pos) {
			assert(pos < _size);

			const char* ptr = strstr(_str + pos, str);
			if (str) {
				return ptr - str;
			}
			else
				return npos;
		}

		string substr(size_t pos = 0, size_t len = npos) {
			assert(pos < _size);

			size_t n = len;
			if (len == npos || pos + len > _size)
			{
				n = _size - pos;
			}

			string tmp;
			tmp.resever(n);
			for (size_t i = pos; i < pos + n; i++)
			{
				tmp += _str[i];
			}

			return tmp;
		}

		void clear() {
			_str[0] = '\0';
			_size = 0;
		}

		bool operator<(const string& s) const {
			int ret = memcmp(_str, s._str, _size < s._size ? _size : s._size);
			
			return ret == 0 ? _size < s._size : ret < 0;
		}

		bool operator==(const string& s) const
		{
			return _size == s._size
				&& memcmp(_str, s._str, _size) == 0;
		}

		bool operator<=(const string& s) const
		{
			return *this < s || *this == s;
		}

		bool operator>(const string& s) const
		{
			return !(*this <= s);
		}

		bool operator>=(const string& s) const
		{
			return !(*this < s);
		}

		bool operator!=(const string& s) const
		{
			return !(*this == s);
		}

	private:
		size_t _size;
		size_t _capacity;
		char* _str;

	public :
		const static size_t npos = -1;
	};

	ostream& operator<<(ostream& out, const string& s) {
		for (auto ch : s)
		{
			out << ch;
		}

		return out;
	}

	istream& operator>>(istream& in, string& s)
	{
		s.clear();

		char ch = in.get();
		// 处理前缓冲区前面的空格或者换行
		while (ch == ' ' || ch == '\n')
		{
			ch = in.get();
		}

		//in >> ch;
		char buff[128];
		int i = 0;

		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == 127)
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}

			//in >> ch;
			ch = in.get();
		}

		if (i != 0)
		{
			buff[i] = '\0';
			s += buff;
		}

		return in;
	}
};


