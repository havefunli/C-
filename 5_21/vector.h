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
		// ���������
		typedef T* iterator;
		typedef const T* const_iterator;

		// ���ص�����
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

		// ����vector��size
		size_t size() const {
			return _end - _start;
		}

		// ����vector��capacity
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

		// ���ݺ���
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

		// ��ӡ����
		void Print() {
			for (auto e : *this) {
				cout << e << " ";
			}
			cout << endl;
		}

		// ���캯��
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

		// ��������
		vector(const vector<T>& v) {
			reserve(v.capacity());
			for (auto e : v) {
				push_back(e);
			}
		}

		// swap����
		void swap(vector<T>& v) {
			std::swap(_start, v._start);
			std::swap(_end, v._end);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		// ��ֵ���������
		vector<T>& operator=(vector<T> v) {
			swap(v);

			return *this;
		}

		// ����Ԫ��
		~vector() {
			delete[] _start;
			_start = _end = _end_of_storage = nullptr;
		}

		// ����Ԫ��
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

		// β��
		void push_back(const T& val) {
			insert(end(), val);
		}

		// ɾ��Ԫ��
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

		// βɾ
		iterator pop_back() {
			return erase(_end - 1);
		}

	private:
		iterator _start = nullptr;
		iterator _end = nullptr;
		iterator _end_of_storage = nullptr;
	};
}