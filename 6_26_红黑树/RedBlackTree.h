#pragma once
#include <iostream>
using namespace std;

enum Color {
	RED,
	BLACK
};

namespace myRBTree {
	template<class K, class V>
	struct RBTreeNode {
		// ����,���׽ڵ�
		RBTreeNode* _left;
		RBTreeNode* _right;
		RBTreeNode* _parent;
		pair<K, V> _kv;
		// ��ɫ
		Color _col;

		// ���캯��
		RBTreeNode(const pair<K, V>& kv)
			: _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _kv(kv)
			, _col(RED)
		{}
	};

	template<class K, class V>
	class RBTree {
		typedef RBTreeNode<K, V> Node;
	public:
		// ��ʼ������
		RBTree() {}

		// ��������
		~RBTree() {
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

		// ��������
		void RotateL(Node* parent) {
			Node* subR = parent->_right; // ����
			Node* subRL = subR->_left; // �������֧
			// �������ָ֧��ԭ���ĸ��ڵ�
			parent->_right = subRL;
			if (subRL) subRL->_parent = parent;
			// �����µĸ��ڵ��ԭ���Ĺ�ϵ
			Node* ppNode = parent->_parent; // ���ڵ�ĸ��ڵ�
			parent->_parent = subR;
			subR->_left = parent; // ���ڵ��Ϊ�ӽڵ�
			// �µĸ��ڵ�ĸ��ڵ�
			if (parent == _root) {
				_root = subR;
				_root->_parent = nullptr;
			}
			else {
				subR->_parent = ppNode;
				if (ppNode->_left == parent) ppNode->_left = subR;
				else ppNode->_right = subR;
			}

			// �������ڵ����ɫ
			subR->_col = BLACK;
			parent->_col = RED;
		}

		// ��������
		void RotateR(Node* parent) {
			Node* subL = parent->_left; // ����
			Node* subLR = subL->_right; // �����ҷ�֧
			// �����ҷ�ָ֧��ԭ���ĸ��ڵ�
			parent->_left = subLR;
			if (subLR) subLR->_parent = parent;
			// �����µĸ��ڵ��ԭ���Ĺ�ϵ
			Node* ppNode = parent->_parent; // ���ڵ�ĸ��ڵ�
			parent->_parent = subL;
			subL->_right = parent; // ���ڵ��Ϊ�ӽڵ�
			// �µĸ��ڵ�ĸ��ڵ�
			if (parent == _root) {
				_root = subL;
				_root->_parent = nullptr;
			}
			else {
				subL->_parent = ppNode;
				if (ppNode->_left == parent) ppNode->_left = subL;
				else ppNode->_right = subL;
			}

			// �������ڵ����ɫ
			subL->_col = BLACK;
			parent->_col = RED;
		}

		// ����������
		void RotateLR(Node* parent) {
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			// ����
			RotateL(subL);
			// ����
			RotateR(parent);

			// �������ڵ����ɫ
			subLR->_col = BLACK;
			parent->_col = RED;
		}

		// ����������
		void RotateRL(Node* parent) {
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			// ����
			RotateR(subR);
			// ����
			RotateL(parent);

			// �������ڵ����ɫ
			subRL->_col = BLACK;
			parent->_col = RED;
		}

		// ���뺯��
		pair<Node*, bool> insert(pair<K, V> kv) {
			// �����ڵ�Ϊ�գ�ֱ�ӹ��췵��
			if (_root == nullptr) {
				_root = new Node(kv);
				_root->_col = BLACK;
				return { _root, true };
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
				else if (cur->_kv.first == kv.first) { // �ͽڵ��ֵ��ͬ���˳�
					return { cur, false };
				}
			}

			cur = new Node(kv);
			pair<Node*, bool> ret(cur, true);

			cur->_parent = parent; // ���¸��ڵ�ָ��
			if (parent->_kv.first > kv.first) { // ����ֵ�Ĵ�Сѡ����븸�ڵ��λ��
				parent->_left = cur;
			}
			else {
				parent->_right = cur;
			}

			// ����������ɫ
			while (parent && parent->_col == RED) {
				Node* grandparent = parent->_parent; // �游�ڵ�
				Node* uncle = grandparent->_left; // Ѱ��������
				if (grandparent->_left == parent) uncle = grandparent->_right;

				// uncle ��������ɫΪ��ɫ
				if (uncle && uncle->_col == RED) {
					uncle->_col = parent->_col = BLACK;
					grandparent->_col = RED;
					// ���½��
					cur = grandparent;
					parent = cur->_parent;
				}
				else {
					// ����������
					if (grandparent->_left == parent) {
						if (cur == parent->_left) { 
							RotateR(grandparent); 
							break;
						}
						// ������������
						else { 
							RotateLR(grandparent); 
							break;
						}
					}
					// ����������
					else {
						if (cur == parent->_right) {
							RotateL(grandparent);
							break;
						}
						else {
							RotateRL(grandparent);
							break;
						}
					}
				}
				// ������ڵ����ɫ�����ı�
				_root->_col = BLACK;
			}

			return ret;
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
				if (cur == _root) {
					_root = cur->_left;
					_root->_parent = nullptr;
				}
				else {
					cur->_left->_parent = parent;
					if (parent->_left == cur) parent->_left = cur->_left;
					else parent->_right = cur->_left;
				}
				delete cur;
				return true;
			}
			// �Һ��Ӳ�Ϊ��
			else if (cur->_left == nullptr && cur->_right != nullptr) {
				if (cur == _root) {
					_root = cur->_right;
					_root->_parent = nullptr;
				}
				else {
					cur->_right->_parent = parent;
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
				if (leftMax->_left) leftMax->_left->_parent = leftParent; // �ú��Ӳ�Ϊ��
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
