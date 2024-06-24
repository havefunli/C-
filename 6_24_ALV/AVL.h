#pragma once
#include <iostream>
using namespace std;
#pragma once

namespace myAVL {
	template<class K, class V>
	struct AVLreeNode {
		// ����,���׽ڵ�
		AVLreeNode* _left;
		AVLreeNode* _right;
		AVLreeNode* _parent;
		pair<K, V> _kv;
		// ƽ������
		int _bf;

		// ���캯��
		AVLreeNode(const pair<K, V>& kv)
			:_left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _bf(0)
			, _kv(kv)
		{}
	};

	template<class K, class V>
	class AVL {
		typedef AVLreeNode<K, V> Node;
	public:
		// ��ʼ������
		AVL() {}

		// ��������
		~AVL() {
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

			// ����ƽ������
			subR->_bf = parent->_bf = 0;
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

			// ����ƽ������
			subL->_bf = parent->_bf = 0;
		}

		// ����������
		void RotateLR(Node* parent) {
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			// ����
			RotateL(subL);
			// ����
			RotateR(parent);

			// ����ƽ������,�������
			int bf = subLR->_bf;
			subLR->_bf = 0;
			if (bf == 1) {
				parent->_bf = 0;
				subL->_bf = -1;
			}
			else if (bf == -1) {
				parent->_bf = 1;
				subL->_bf = 0;
			}
			else {
				parent->_bf = subL->_bf = 0;
			}
		}

		// ����������
		void RotateRL(Node* parent) {
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			// ����
			RotateR(subR);
			// ����
			RotateL(parent);

			// ����ƽ������,�������
			int bf = subRL->_bf;
			subRL->_bf = 0;
			if (bf == 1) {
				subR->_bf = 0;
				parent->_bf = -1;
			}
			else if (bf == -1) {
				parent->_bf = 0;
				subR->_bf = 1;
			}
			else {
				parent->_bf = subR->_bf = 0;
			}
		}

		// ���뺯��
		pair<Node*, bool> insert(pair<K, V> kv) {
			// �����ڵ�Ϊ�գ�ֱ�ӹ��췵��
			if (_root == nullptr) {
				_root = new Node(kv);
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

			// ����ƽ������
			while (parent) {
				if (parent->_left == cur) { (parent->_bf)--; } // ����߲���ƽ�����Ӽ�һ�෴��һ
				else { (parent->_bf)++; }

				// ��Ϊ 0 ��ƽ�⣬�˳�
				if (parent->_bf == 0) { break; }
				
				// ����
				if (parent->_bf == 2 && cur->_bf == 1) {
					RotateL(parent);
					break;
				}
				// ����
				else if (parent->_bf == -2 && cur->_bf == -1) { 
					RotateR(parent); 
					break;
				}
				// ����������
				else if (parent->_bf == -2 && cur->_bf == 1) {
					RotateLR(parent);
					break;
				}
				// ������������
				else if (parent->_bf == 2 && cur->_bf == -1) {}

				// ����ָ���ָ��
				cur = parent;
				parent = cur->_parent;
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
				if(leftMax->_left) leftMax->_left->_parent = leftParent; // �ú��Ӳ�Ϊ��
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