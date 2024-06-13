#include <iostream>
using namespace std;

//class A {
//public:
//	virtual void Func1() {
//		cout << "This is Func1." << endl;
//	}
//
//	virtual void Func2() {
//		cout << "This is Func2." << endl;
//	}
//
//	int _a = 0;
//};
//
//class B : public A{
//public:
//	virtual void Func1() {
//		cout << "This is Func1, but in B." << endl;
//	}
//
//	virtual void Func3() {
//		cout << "This is Func3, but in B." << endl;
//	}
//
//	int _b = 0;
//};
//
//void test_1() {
//	A a;
//	B b;
//}
//
//int main() {
//	test_1();
//	return 0;
//}

class Solution {
public:
    TreeNode* FindLeftMax(TreeNode* node) {
        if (node->right == nullptr) return node;
        else return FindLeftMax(node->right);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;

        TreeNode* parent = root;
        TreeNode* child = root;
        while (child != nullptr && child->val != key) {
            parent = child;
            if (child->val > key) {
                child = child->left;
            }
            else {
                child = child->right;
            }
        }

        if (parent == nullptr) return root;
        if (child->left == nullptr && child->right == nullptr) {
            parent->left = child->left;
        }
        else if (child->left != nullptr && child->right == nullptr) {
            parent->left = child->left;
        }
        else if (child->left == nullptr && child->right != nullptr) {
            parent->right = child->right;
        }
        else {
            TreeNode* leftMax = FindLeftMax(child);
            swap(parent->val, leftMax->val);
            child = leftMax;
        }

        delete child;
        return root;
    }
};