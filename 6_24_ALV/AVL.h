#pragma once
#include <iostream>
using namespace std;
#pragma once

namespace myAVL {
	template<class K, class V>
	struct AVLreeNode {
		// 左右,父亲节点
		AVLreeNode* _left;
		AVLreeNode* _right;
		AVLreeNode* _parent;
		pair<K, V> _kv;
		// 平衡因子
		int _bf;

		// 构造函数
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
		// 初始化函数
		AVL() {}

		// 析构函数
		~AVL() {
			clear(_root);
			_root = nullptr;
		}

		// 清除函数
		void clear(Node* node) {
			if (node == nullptr) return;

			clear(node->_left);
			clear(node->_right);
			delete node;
		}

		// 左旋函数
		void RotateL(Node* parent) {
			Node* subR = parent->_right; // 旋点
			Node* subRL = subR->_left; // 旋点左分支
			// 处理左分支指向原来的父节点
			parent->_right = subRL;
			if (subRL) subRL->_parent = parent;
			// 处理新的父节点和原来的关系
			Node* ppNode = parent->_parent; // 父节点的父节点
			parent->_parent = subR; 
			subR->_left = parent; // 父节点变为子节点
			// 新的父节点的父节点
			if (parent == _root) {
				_root = subR;
				_root->_parent = nullptr;
			}
			else {
				subR->_parent = ppNode;
				if (ppNode->_left == parent) ppNode->_left = subR;
				else ppNode->_right = subR;
			}

			// 更新平衡因子
			subR->_bf = parent->_bf = 0;
		}

		// 右旋函数
		void RotateR(Node* parent) {
			Node* subL = parent->_left; // 旋点
			Node* subLR = subL->_right; // 旋点右分支
			// 处理右分支指向原来的父节点
			parent->_left = subLR;
			if (subLR) subLR->_parent = parent;
			// 处理新的父节点和原来的关系
			Node* ppNode = parent->_parent; // 父节点的父节点
			parent->_parent = subL;
			subL->_right = parent; // 父节点变为子节点
			// 新的父节点的父节点
			if (parent == _root) {
				_root = subL;
				_root->_parent = nullptr;
			}
			else {
				subL->_parent = ppNode;
				if (ppNode->_left == parent) ppNode->_left = subL;
				else ppNode->_right = subL;
			}

			// 更新平衡因子
			subL->_bf = parent->_bf = 0;
		}

		// 左旋再右旋
		void RotateLR(Node* parent) {
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			// 左旋
			RotateL(subL);
			// 右旋
			RotateR(parent);

			// 更新平衡因子,三种情况
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

		// 右旋再左旋
		void RotateRL(Node* parent) {
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			// 右旋
			RotateR(subR);
			// 左旋
			RotateL(parent);

			// 更新平衡因子,三种情况
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

		// 插入函数
		pair<Node*, bool> insert(pair<K, V> kv) {
			// 若根节点为空，直接构造返回
			if (_root == nullptr) {
				_root = new Node(kv);
				return { _root, true };
			}

			// 定义一个父节点时刻指向比较的节点
			Node* parent = _root;
			Node* cur = _root;
			while (cur) {
				parent = cur; // 更新父节点
				if (cur->_kv.first > kv.first) { // 比结点小，去左边
					cur = cur->_left;
				}
				else if (cur->_kv.first < kv.first) { // 比节点大，去右边
					cur = cur->_right;
				}
				else if (cur->_kv.first == kv.first) { // 和节点的值相同，退出
					return { cur, false };
				}
			}

			cur = new Node(kv);
			pair<Node*, bool> ret(cur, true);

			cur->_parent = parent; // 更新父节点指针
			if (parent->_kv.first > kv.first) { // 根据值的大小选择插入父节点的位置
				parent->_left = cur;
			}
			else {
				parent->_right = cur;
			}

			// 更新平衡因子
			while (parent) {
				if (parent->_left == cur) { (parent->_bf)--; } // 在左边插入平衡因子减一相反加一
				else { (parent->_bf)++; }

				// 若为 0 则平衡，退出
				if (parent->_bf == 0) { break; }
				
				// 左旋
				if (parent->_bf == 2 && cur->_bf == 1) {
					RotateL(parent);
					break;
				}
				// 右旋
				else if (parent->_bf == -2 && cur->_bf == -1) { 
					RotateR(parent); 
					break;
				}
				// 左旋再右旋
				else if (parent->_bf == -2 && cur->_bf == 1) {
					RotateLR(parent);
					break;
				}
				// 先右旋再左旋
				else if (parent->_bf == 2 && cur->_bf == -1) {}

				// 更新指针的指向
				cur = parent;
				parent = cur->_parent;
			}

			return ret;
		}

		// 中序遍历
		void inOrder() {
			_InOrder(_root);
			cout << endl;
		}

		// 查找函数
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
			auto ret = insert({ key, V() }); // 获取返回值
			Node* node = ret.first; // 获取结点指针
			return node->_kv.second; // 返回值的引用
		}

		bool erase(const K& key) {
			if (_root == nullptr) return false;

			Node* parent = _root;
			Node* cur = _root;
			while (cur) {
				parent = cur; // 更新父节点
				if (cur->_kv.first > key) { // 比该节点小
					cur = cur->_left;
				}
				else if (cur->_kv.first < key) { // 比该节点大
					cur = cur->_right;
				}
				else { // 找到该节点
					break;
				}
			}
			// 该节点不存在
			if (cur == nullptr) return false;
			// 叶子结点的处理
			if (cur->_left == nullptr && cur->_right == nullptr) {
				if (cur == _root) _root = nullptr; // 是否是根节点

				if (parent->_left == cur) parent->_left = nullptr;
				else parent->_right = nullptr;

				delete cur;
				return true;
			}
			// 左孩子不为空
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
			// 右孩子不为空
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
				Node* leftParent = cur; // 记录父节点便于后续删除
				Node* leftMax = cur->_left;

				while (leftMax->_right != nullptr) {
					leftParent = leftMax;
					leftMax = leftMax->_right;
				}
				// 将删除结点的左节点(如果有托付给父节点)
				if(leftMax->_left) leftMax->_left->_parent = leftParent; // 该孩子不为空
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

		// 声明根节点
		Node* _root = nullptr;
	};
}