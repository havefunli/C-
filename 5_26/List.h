#pragma once
#include <list>
#include <assert.h>
#include <iostream>
using namespace std;

namespace my_list {

	template<class T>
	struct Node {
		// ��ʼ��
		Node(const T& val = T()) {
			_val = val;
			_prev = _next = nullptr;
		}

		// ��Ա����
		T _val;
		Node* _prev;
		Node* _next;
	 };

	template<class T>
	struct ListIterator {
		typedef Node<T> Node;
		typedef ListIterator<T> iterator;

		// ��ʼ��
		ListIterator(const Node*& node) {
			_node = node;
		}

		// *
		T& operator*() {
			return _node->_val;
		}

		// ++ǰ��
		iterator operator++() {
			return _node->next;
		}
		// ����++
		iterator operator++(int) {
			Node* temp = _node;
			_node = _node->next;
			return temp;
		}

		// --ǰ��
		iterator operator--() {
			return _node->prev;
		}
		// ����--
		iterator operator--(int) {
			Node* temp = _node;
			_node = _node->prev;
			return temp;
		}

		// ==
		bool operator==(iterator it) {
			return _node == it._nodel;
		}
		// != 
		bool operator!=(iterator it) {
			return !(*this == it);
		}

		// ��Ա����
		Node* _node;
	};

	template<class T>
	class list {
		 typedef Node<T> Node;
		 typedef ListIterator<T> iterator;
	public:
		
		//������
		iterator begin() {
			return _head->_next;
		}
		iterator end() {
			return _head;
		}

		// ���캯��
		list()
			:_head(new Node)
		{
			_head->next = _head;
			_head->prev = _head;
			_size = 0;
		}

		// ���뺯��
		void insert(iterator pos, const T& val) {
			Node* node = new Node(val);
			Node* prev = pos--;


		}

	private:
		Node* _head;
		size_t _size;
	};
}
 