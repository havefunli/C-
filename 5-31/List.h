#pragma once
#pragma once
#include <list>
#include <vector>
#include <assert.h>
#include <iostream>
using namespace std;

namespace my_list {

	template<class T>
	struct Node {
		// 初始化
		Node(const T& val = T()) {
			_val = val;
			_prev = _next = nullptr;
		}

		// 成员变量
		T _val;
		Node* _prev;
		Node* _next;
	};

	template<class T, class Ref, class Ptr>
	struct ListIterator {
		typedef Node<T> Node;
		typedef ListIterator<T, Ref, Ptr> iterator;

		// 初始化
		ListIterator(Node* const node) {
			_node = node;
		}

		// *
		Ref operator*() {
			return _node->_val;
		}

		// ++前置
		iterator operator++() {
			_node = _node->_next;
			return _node;

			// return _node->next; 这样做的话，_node指针本身的指向并未变化，所以引发死循环
		}
		// 后置++
		iterator operator++(int) {
			Node* temp = _node;
			_node = _node->_next;
			return temp;
		}

		// --前置
		iterator operator--() {
			_node = _node->_prev;
			return _node;
		}
		// 后置--
		iterator operator--(int) {
			Node* temp = _node;
			_node = _node->_prev;
			return temp;
		}

		// ==
		bool operator==(iterator it) {
			return _node == it._node;
		}
		// != 
		bool operator!=(iterator it) {
			return _node != it._node;
		}

		// 成员变量
		Node* _node;
	};

	template<class iterator, class Ref, class Ptr>
	struct Reverse_iterator{
		typedef Reverse_iterator<iterator, Ref, Ptr> r_iterator;

		Reverse_iterator(iterator it) {
			_it = it;
		}

		// *
		Ref operator*() {
			iterator temp = _it;
			return *(--temp);
		}

		// ++前置
		r_iterator operator++() {
			_it--;
			return _it;
		}
		// 后置++
		iterator operator++(int) {
			iterator temp = _it;
			_it--;
			return temp;
		}

		// --前置
		iterator operator--() {
			_it++;
			return _it;
		}
		// 后置--
		iterator operator--(int) {
			iterator temp = _it;
			_it++;
			return temp;
		}

		// ==
		bool operator==(r_iterator rit) {
			return _it == rit._it;
		}
		// != 
		bool operator!=(r_iterator rit) {
			return _it != rit._it;
		}

		iterator _it;
	};

	template<class T>
	class list {
		typedef Node<T> Node;
	public:
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;
		typedef Reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef Reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;

		//迭代器
		iterator begin() {
			return _head->_next;
		}
		iterator end() {
			return _head;
		}
		const_iterator begin() const {
			return _head->_next;
		}
		const_iterator end() const {
			return _head;
		}
		reverse_iterator rbegin() {
			return end();
		}
		reverse_iterator rend() {
			return begin();
		}


		// 返回大小
		size_t size() const {
			return _size;
		}

		// 清除函数
		void clear() {
			iterator it = begin();
			while (it != _head) {
				it = erase(it);
			}
		}

		// 析构函数
		~list() {
			clear();
			delete _head;
			_head = nullptr;
		}

		// 构造函数
		list()
			:_head(new Node)
		{
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}

		template<class InputIterator>
		list(InputIterator first, InputIterator last)
			:_head(new Node)
		{
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;

			while (first != last) {
				push_back(*first);
				first++;
			}
		}

		// 拷贝构造函数
		list(list<T>& lt)
			:_head(new Node)
		{
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;

			for (auto e : lt) {
				push_back(e);
			}
		}

		// 赋值重载
		list<T>& operator=(list<T> lt) {
			clear();
			for (auto e : lt) {
				push_back(e);
			}

			return *this;
		}

		// 插入函数
		void insert(iterator pos, const T& val) {
			Node* cur = pos._node;
			Node* node = new Node(val);
			Node* prev = cur->_prev;

			node->_next = cur;
			cur->_prev = node;
			prev->_next = node;
			node->_prev = prev;

			_size += 1;
		}

		// 头插
		void push_front(const T& val) {
			insert(begin(), val);
		}

		// 尾插
		void push_back(const T& val) {
			insert(end(), val);
		}

		// 删除函数
		iterator erase(iterator pos) {
			Node* node = pos._node;
			Node* prev = node->_prev;
			Node* next = node->_next;

			prev->_next = next;
			next->_prev = prev;
			_size -= 1;

			return next;
		}

		// 尾删
		void pop_back() {
			erase(--end());
		}

		// 头删
		void pop_front() {
			erase(begin());
		}

	private:
		Node* _head;
		size_t _size;
	};

	template<class T>
	class Test {
	public:
		Test() {
			val = 1;
		}
		void Print1();

	private:
		T val;
	};
}