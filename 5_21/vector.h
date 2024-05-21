#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
using namespace std;

namespace my_Vector {
	
	template<class T>
	class vector {
	public:
		// 定义迭代器
		typedef T* iterator;
		typedef const T* const_iterator;

		// 返回迭代器
		iterator begin() {
			return _start;
		}
		iterator end() {
			return _end;
		}
		const_iterator begin() const {
			return _start;
		}
		const_iterator end() const {
			return _end;
		}

		// 返回vector的size
		size_t size() const {
			return _end - _start;
		}

		// 返回vector的capacity
		size_t capacity() const {
			return _end_of_storage - _start;
		}

		// 扩容函数
		void reserve(size_t n) {
			if (n > capacity()) {
				size_t old_size = size();

				T* temp = new T[n];
				memcpy(temp, _start, size() * sizeof(T));
				
				_start = temp;
				_end = _start + old_size;
				_end_of_storage = _start + n;
			}
		}

		// 打印函数
		void Print() {
			for (auto e : *this) {
				cout << e << " ";
			}
			cout << endl;
		}

		// 构造函数
		vector() {
			_start = nullptr;
			_end = nullptr;
			_end_of_storage = nullptr;
		}

		template<class InputIterator>
		vector(InputIterator start, InputIterator end) {
			while (start != end) {
				push_back(*start);
				start += 1;
			}
		}

		iterator insert(iterator pos, const T& val) {
			assert((pos <= _end) && (pos >= _start));

			if (_end == _end_of_storage) {
				size_t len = pos - _start;

				size_t new_capacity = capacity() > 0 ? capacity() * 2 : 4;
				reserve(new_capacity);

				pos = _start + len;
			}

			iterator end = _end;
			while (pos != end) {
				*end = *(end - 1);
				end -= 1;
			}

			*pos = val;
			_end += 1;

			return pos;
		}

		void push_back(const T& val) {
			insert(end(), val);
		}

	private:
		iterator _start;
		iterator _end;
		iterator _end_of_storage;
	};
}