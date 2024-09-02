#pragma once
#include <iostream>
using namespace std;

namespace BST {
	// 定义结点
	template<class T>
	struct TreeNode {
		TreeNode(const T& val)
			:val(val)
			,left(nullptr)
			,right(nullptr)
		{}

		T val;
		TreeNode* left;
		TreeNode* right;
	};

	template<class T>
	class BSTree {
		typedef TreeNode<T> Node;
	public:
		BSTree() {}

		Node* find(const T& val) {
			if (_root == nullptr) return nullptr;

			Node* _cur = _root;
			while (_cur) {
				if (_cur->val > val) {
					_cur = _cur->left;
				}
				else if (_cur->val < val) {
					_cur = _cur->right;
				}
				else {
					return _cur;
				}
			}
			return nullptr;
		}

		Node* FindLeftMax(Node* node) {
			if (node->right == nullptr) return node;
			else return FindLeftMax(node->right);
		}

		bool insert(const T& val) {
			if (_root == nullptr) {
				_root = new Node(val);
				return true;
			}
			else {
				Node* parent = _root;
				Node* cur = _root;
				while (cur != nullptr) {
					parent = cur;
					if (cur->val > val) {
						cur = cur->left;
					}
					else if (cur->val < val) {
						cur = cur->right;
					}
					else {
						return false;
					}
				}

				Node* newNode = new Node(val);
				if (parent->val > val) parent->left = newNode;
				else parent->right = newNode;
				return true;
			}
		}

		Node* erase(const T& key) {
			if (_root == nullptr) return _root;

			Node* parent = _root;
			Node* child = _root;
			while (child != nullptr && child->val != key) {
				parent = child;
				if (child->val > key) {
					child = child->left;
				}
				else {
					child = child->right;
				}
			}

			if (child->left == nullptr) {
				if (parent->left == child) parent->left = child->right;
				else parent->right = child->right;
			}
			else if (child->right == nullptr) {
				if (parent->left == child) parent->left = child->left;
				else parent->right = child->left;
			}
			else {
				Node* leftMax = child->left;
				Node* leftMaxparent = child;
				while (leftMax->right) {
					leftMaxparent = leftMax;
					leftMax = leftMax->right;
				}
				if (leftMaxparent->left == leftMax) leftMaxparent->left = leftMax->left;
				else leftMaxparent->right = leftMax->left;
				swap(leftMax->val, child->val);
				child = leftMax;
			}


			delete child;
			child = nullptr;
			return _root;
		}

		void InOrder() {
			_InOrder(_root);
			cout << endl;
		}

	private:
		void _InOrder(Node* node) {
			if (node == nullptr) return;

			_InOrder(node->left);
			cout << node->val << " ";
			_InOrder(node->right);
		}
		Node* _root;
	};
}

