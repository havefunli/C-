#pragma once
#include <iostream>
#include <map>
using namespace std;

namespace myMap {
	template<class K, class V>
	struct BSTreeNode {
		// ���ҽڵ�
		BSTreeNode* _left; 
		BSTreeNode* _right;
		pair<K, V> _kv;

		// ���캯��
		BSTreeNode(const pair<K, V>& kv)
			:_left(nullptr)
			,_right(nullptr)
			,_kv(kv)
		{}
	};

	template<class K, class V>
	class Map {
		typedef BSTreeNode<K, V> Node;
	public:
		// ��ʼ������
		Map() {}


		// ��������
		~Map() {
			clear(_root);
			_root = nullptr;
		}

		// �������
		void clear(Node* node) {
			if (node == nullptr) return;

			clear(node->_left);
			clear(node->_right);
			delete node;
		}

		// ���뺯��
		pair<Node*, bool> insert(pair<K, V> kv) {
			// �����ڵ�Ϊ�գ�ֱ�ӹ��췵��
			if (_root == nullptr) {
				_root = new Node(kv);
				return {_root, true};
			}
			
			// ����һ�����ڵ�ʱ��ָ��ȽϵĽڵ�
			Node* parent = _root;
			Node* cur = _root;
			while (cur) {
				parent = cur; // ���¸��ڵ�
				if (cur->_kv.first > kv.first) { // �Ƚ��С��ȥ���
					cur = cur->_left;
				}
				else if (cur->_kv.first < kv.first) { // �Ƚڵ��ȥ�ұ�
					cur = cur->_right;
				}
				else if(cur->_kv.first ==  kv.first) { // �ͽڵ��ֵ��ͬ���˳�
					return { cur, false };
				}
			}

			cur = new Node(kv); 
			if (parent->_kv.first > kv.first) { // ����ֵ�Ĵ�Сѡ����븸�ڵ��λ��
				parent->_left = cur;
			}
			else {
				parent->_right = cur;
			}
			return { cur, true };
		}

		// �������
		void inOrder() {
			_InOrder(_root);
			cout << endl;
		}

		// ���Һ���
		Node* find(const K& key) {
			if (_root == nullptr) return nullptr;

			Node* cur = _root;
			while (cur) {
				if (cur->_kv.first > key) cur = cur->_left;
				else if (cur->_kv.first < key) cur = cur->_right;
				else return cur;
			}

			return nullptr;
		}

		V& operator[](const K& key) {
			auto ret = insert({ key, V() }); // ��ȡ����ֵ
			Node* node = ret.first; // ��ȡ���ָ��
			return node->_kv.second; // ����ֵ������
		}

		bool erase(const K& key) {
			if (_root == nullptr) return false;

			Node* parent = _root;
			Node* cur = _root;
			while (cur) {
				parent = cur; // ���¸��ڵ�
				if (cur->_kv.first > key) { // �ȸýڵ�С
					cur = cur->_left;
				}
				else if (cur->_kv.first < key) { // �ȸýڵ��
					cur = cur->_right;
				}
				else { // �ҵ��ýڵ�
					break;
				}
			}
			// �ýڵ㲻����
			if (cur == nullptr) return false;
			// Ҷ�ӽ��Ĵ���
			if (cur->_left == nullptr && cur->_right == nullptr) {
				if (cur == _root) _root = nullptr; // �Ƿ��Ǹ��ڵ�

				if (parent->_left == cur) parent->_left = nullptr;
				else parent->_right = nullptr;

				delete cur;
				return true;
			}
			// ���Ӳ�Ϊ��
			else if (cur->_left != nullptr && cur->_right == nullptr) {
				if (cur == _root) _root = cur->_left;
				else {
					if (parent->_left == cur) parent->_left = cur->_left;
					else parent->_right = cur->_left;
				}
				delete cur;
				return true;
			}
			// �Һ��Ӳ�Ϊ��
			else if (cur->_left == nullptr && cur->_right != nullptr) {
				if (cur == _root) _root = cur->_right;
				else {
					if (parent->_left == cur) parent->_left = cur->_right;
					else parent->_right = cur->_right;
				}
				delete cur;
				return true;
			}
			else {
				Node* leftParent = cur; // ��¼���ڵ���ں���ɾ��
				Node* leftMax = cur->_left;
				
				while (leftMax->_right != nullptr) {
					leftParent = leftMax;
					leftMax = leftMax->_right;
				}
				// ��ɾ��������ڵ�(������и������ڵ�)
				if (leftParent->_left == leftMax) leftParent->_left = leftMax->_left;
				else leftParent->_right = leftMax->_left;
				swap(cur->_kv, leftMax->_kv);

				delete leftMax;
			}
		}

	private:
		void _InOrder(Node* node) {
			if (node == nullptr) return;

			_InOrder(node->_left);
			cout << "(" << node->_kv.first << ", " << node->_kv.second << ")" << " ";
			_InOrder(node->_right);
		}
		// �������ڵ�
		Node* _root = nullptr;
	};
}