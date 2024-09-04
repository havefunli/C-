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
			int bf = subLR->_bf; // 记录该节点的平衡因子

			// 左旋
			RotateL(subL);
			// 右旋
			RotateR(parent);

			// 更新平衡因子,三种情况
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
				else if (parent->_bf == 2 && cur->_bf == -1) {
					RotateRL(parent);
					break;
				}

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

		void adjust_up_bf(Node* parent, Node* child) {
			while (parent) {
				// 记录并更新平衡因子
				int old_bf = parent->_bf;
				if (parent->_left == child) { parent->_bf++; }
				else { parent->_bf--; }
				
				// 该节点原来的的平衡因子为 0,直接退出
				if (old_bf == 0) { break; }
				
				// 判断是否需要旋转，以及旋转方式:
				if (parent->_bf == 2 || parent->_bf == -2) {
					// 如何旋转取决于，另一边孩子
					// 左旋
					if (parent->_left == child) {
						if (parent->_bf == 2 && parent->_right->_bf == 1) {
							Node* subR = parent->_right;
							RotateL(parent);
							// 更新结点
							parent = subR->_parent;
							child = subR;
							continue;
						}
						// 先右旋再左旋
						else if(parent->_bf == 2 && parent->_right->_bf == -1){
							Node* subRL = parent->_right->_left;
							RotateRL(parent);
							// 更新结点
							parent = subRL->_parent;
							child = subRL;
							continue;
						}
						// 特殊情况为 0，这种情况可以直接旋转后退出
						else if (parent->_bf == 2 && parent->_right->_bf == 0) {
							Node* subR = parent->_right;
							RotateL(parent);
							// 更新平衡因子
							subR->_bf = -1;
							subR->_left->_bf = 1;
							break;
						}
					}
					else {
						// 右旋
						if (parent->_bf == -2 && parent->_left->_bf == -1) {
							Node* subL = parent->_left;
							RotateR(parent);
							// 更新结点
							parent = subL->_parent;
							child = subL;
							continue;
						}
						// 左旋再右旋
						else if (parent->_bf == -2 && parent->_left->_bf == 1) {
							Node* subLR = parent->_left->_right;
							RotateLR(parent);
							// 更新结点
							parent = subLR->_parent;
							child = subLR;
							continue;
						}
						// 特殊情况为 0，这种情况可以直接旋转后退出
						else if (parent->_bf == -2 && parent->_left->_bf == 0) {
							Node* subL = parent->_left;
							RotateR(parent);
							// 更新平衡因子
							subL->_bf = 1;
							subL->_right->_bf = -1;
							break;
						}
					}
				}
				// 更新节点
				child = parent;
				parent = parent->_parent;
			}
		}

		bool erase(const K& key) {
			if (_root == nullptr) return false;

			Node* parent = _root;
			Node* cur = _root;
			while (cur) {
				if (cur->_kv.first > key) { // 比该节点小
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_kv.first < key) { // 比该节点大
					parent = cur;
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
				if (cur == _root) { _root = nullptr; } // 是否是根节点

				if (parent->_left == cur) { parent->_left = nullptr; }
				else { parent->_right = nullptr; }

				delete cur;
				adjust_up_bf(parent, nullptr);
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
				adjust_up_bf(parent, parent->_left);
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
				adjust_up_bf(parent, parent->_right);
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
				Node* leftMaxRight = leftMax->_left;
				if(leftMaxRight) leftMaxRight->_parent = leftParent; // 该孩子不为空
				if (leftParent->_left == leftMax) leftParent->_left = leftMaxRight;
				else leftParent->_right = leftMaxRight;
				swap(cur->_kv, leftMax->_kv);

				delete leftMax;
				adjust_up_bf(leftParent, leftMaxRight);
				return true;
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