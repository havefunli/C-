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

		T& operator[](size_t i) {
			assert(i < size());

			return _start[i];
		}

		const T& operator[](size_t i) const {
			assert(i < size());

			return _start[i];
		}

		// 扩容函数
		void reserve(size_t n) {
			if (n > capacity()) {
				size_t old_size = size();

				T* temp = new T[n];
				//memcpy(temp, _start, size() * sizeof(T));
				for (int i = 0; i < size(); i++) {
					temp[i] = _start[i];
				}
				delete[] _start;
				
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

		vector(int n, const T& val = T()) {
			reserve(n);
			for (size_t i = 0; i < n; i++) {
				push_back(val);
			}
		}

		template<class InputIterator>
		vector(InputIterator start, InputIterator end) {
			while (start != end) {
				push_back(*start);
				start += 1;
			}
		}

		vector(initializer_list<T> il) {
			reserve(il.size());
			for (auto e : il) {
				push_back(e);
			}
		}

		// 拷贝构造
		vector(const vector<T>& v) {
			reserve(v.capacity());
			for (auto e : v) {
				push_back(e);
			}
		}

		// swap函数
		void swap(vector<T>& v) {
			std::swap(_start, v._start);
			std::swap(_end, v._end);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		// 赋值运算符重载
		vector<T>& operator=(vector<T> v) {
			swap(v);

			return *this;
		}

		// 析构元素
		~vector() {
			delete[] _start;
			_start = _end = _end_of_storage = nullptr;
		}

		// 插入元素
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

		// 尾插
		void push_back(const T& val) {
			insert(end(), val);
		}

		// 删除元素
		iterator erase(iterator pos) {
			assert((pos >= _start) && (pos < _end));

			iterator it = pos + 1;
			while (it != _end) {
				*(it - 1) = *it;
				it += 1;
			}
			_end -= 1;

			return pos;
		}

		// 尾删
		iterator pop_back() {
			return erase(_end - 1);
		}

	private:
		iterator _start = nullptr;
		iterator _end = nullptr;
		iterator _end_of_storage = nullptr;
	};
}