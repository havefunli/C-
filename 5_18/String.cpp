#include "String.h"

namespace my_Space{
	const size_t String::npos = -1;

	// �������
	void String::clear() {
		_str[0] = '\0';
		_size = 0;
	}

	// ���ص�����
	String::iterator String::begin() {
		return _str;
	}

	String::iterator String::end() {
		return _str + _size;
	}

	String::const_iterator String::begin() const {
		return _str;
	}
	String::const_iterator String::end() const {
		return _str + _size;
	}

	// ���캯��
	String::String(const char* str)
		:_str(new char[strlen(str) + 1])
		, _size(strlen(str))
		, _capacity(strlen(str))
	{
		strcpy(_str, str);
	}

	// ��������
	String::~String() {
		delete[] _str;
		_str = nullptr;
		_size = 0;
		_capacity = 0;
	}

	// �������캯��
	String::String(const String& s) {
		_str = new char[sizeof(s._str)];
		strcpy(_str, s._str);
		_size = s._size;
		_capacity = s._capacity;
	}

	// ��ֵ���������
	String& String::operator=(const String& s) {
		if (this == &s) return *this;
		else {
			delete[] _str;
			char* temp = new char[s._capacity];
			strcpy(temp, s._str);
			_str = temp;
			_size = s._size;
			_capacity = s._capacity;
		}

		return *this;
	}

	// �����ַ���
	const char* String::c_str() const {
		return _str;
	}

	// ����size
	size_t String::size() const {
		return _size;
	}

	// �±����
	char& String::operator[](size_t pos) {
		assert(pos < _size);

		return _str[pos];
	}

	const char& String::operator[](size_t pos) const {
		assert(pos < _size);

		return _str[pos];
	}

	// ����
	void String::reserve(size_t n) {
		if (n > _capacity) {
			char* temp = new char[n + 1];
			strcpy(temp, _str);
			delete[] _str;

			_str = temp;
			_capacity = n;
		}
	}

	// β��
	void String::push_back(char ch) {
		// �жϿռ�
		if (_size == _capacity) {
			int capacity = _capacity == 0 ? 1 : _capacity;
			reserve(2 * capacity);
		}
		
		_str[_size] = ch;
		_size += 1;
		_str[_size] = '\0';
	}

	// ׷���ַ���
	void String::append(const char* str) {
		if (_size + strlen(str) + 1 > _capacity) {
			reserve(_size + strlen(str) + 1);
		}

		strcpy(_str + _size, str);
		_size += strlen(str);
	}

	// ���������
	String& String::operator+=(char ch) {
		push_back(ch);

		return *this;
	}

	String& String::operator+=(const char* str) {
		append(str);

		return *this;
	}

	istream& operator>> (istream& is, String& str) {
		str.clear();
		char ch = is.get();
		
		while (ch != ' ' && ch != '\n') {
			str += ch;
			ch = is.get();
		}

		return is;
	}

	ostream& operator<< (ostream& os, const String& str) {
		cout << str.c_str();

		return os;
	}

	 // abc\0
	void String::insert(size_t pos, char ch) {
		assert(pos <= _size);

		if (_size == _capacity) {
			reserve(_capacity * 2);
		}

		int end = _size + 1;
		while (end > pos) {
			_str[end] = _str[end - 1];
			end--;
		}
		_str[pos] = ch;
		_size += 1;
	}

	void String::insert(size_t pos, const char* str) {
		assert(pos <= _size);

		int len = strlen(str);
		if (_size + len > _capacity) {
			reserve(_size + len);
		}

		int end = _size + len;
		while (end >= pos + len) {
			_str[end] = _str[end - len];
			end--;
		}
		memcpy(_str + pos, str, len);
		_size += len;
	}

	void String::erase(size_t pos, size_t len) {
		assert(pos < _size);

		if (pos + len >= _size) {
			_str['pos'] = '\0';
			_size = pos;
		}
		else {
			strcpy(_str + pos, _str + pos + len);
			_size -= len;
		}
	}
}