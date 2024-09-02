#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <assert.h>
using namespace std;

extern string PATH;

struct Node {
	Node(int val = int()) {
		_val = val;
	}

	int _val = 0;
	Node* _left = nullptr;
	Node* _right = nullptr;
};

class BST {
public:
	// 构造函数
	BST(){}

	template<class Iterator>
	BST(Iterator first, Iterator last) {
		while (first != last) {
			push(*first);
			first++;
		}
	}
	
	// 阅读本地文件读取树
	void read_file(string file = PATH);

	// 删除所有结点
	void clear(Node*& node);
	// 析构函数 --- 使用后序遍历来释放空间
	~BST();

	// 加入新的元素
	void push(const int& val);

	// 删除元素
	void pop(const int& val);

	// 中序遍历
	void in_order();

	// 平均查找长度
	int calculateASL(Node* root, int depth, int& counts);
	void ASL();

	// 插入的具体实现
	Node* insert(Node* node, const int& val);

	// 中序遍历的具体实现
	void really_in_order(Node* node);

	// 寻找某个元素是否存在
	bool find(const int& val);
	bool is_exist(Node* node, const int& val);

private:
	Node* _root = nullptr;
	vector<int> _arr;
};

extern BST bt;

void del_val();
void init_bst();

void BST_Menu();
void Main_menu();

void Build_BST();
