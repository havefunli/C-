#pragma once
#include <iostream>
#include <map>
using namespace std;

namespace myMap {
	template<class K, class V>
	struct BSTreeNode {
		// 左右节点
		BSTreeNode* _left; 
		BSTreeNode* _right;
		pair<K, V> _kv;

		// 构造函数
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
		// 初始化函数
		Map() {}


		// 析构函数
		~Map() {
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

		// 插入函数
		pair<Node*, bool> insert(pair<K, V> kv) {
			// 若根节点为空，直接构造返回
			if (_root == nullptr) {
				_root = new Node(kv);
				return {_root, true};
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
				else if(cur->_kv.first ==  kv.first) { // 和节点的值相同，退出
					return { cur, false };
				}
			}

			cur = new Node(kv); 
			if (parent->_kv.first > kv.first) { // 根据值的大小选择插入父节点的位置
				parent->_left = cur;
			}
			else {
				parent->_right = cur;
			}
			return { cur, true };
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
				if (cur == _root) _root = cur->_left;
				else {
					if (parent->_left == cur) parent->_left = cur->_left;
					else parent->_right = cur->_left;
				}
				delete cur;
				return true;
			}
			// 右孩子不为空
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
				Node* leftParent = cur; // 记录父节点便于后续删除
				Node* leftMax = cur->_left;
				
				while (leftMax->_right != nullptr) {
					leftParent = leftMax;
					leftMax = leftMax->_right;
				}
				// 将删除结点的左节点(如果有托付给父节点)
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
		// 申明根节点
		Node* _root = nullptr;
	};
}