#include "BST.h"

string PATH = "./NUMS.txt";
BST bt;

void Main_menu() {
	cout << "-------------------" << endl;
	cout << "-------1 BST-------" << endl;
	cout << "-------2 AVL-------" << endl;
	cout << "-------0 退出------" << endl;
	cout << "-------------------" << endl;
}

void BST_Menu() {
	cout << "------------------------" << endl;
	cout << "-------1 文件读取-------" << endl;
	cout << "-------2 手动输入-------" << endl;
	cout << "-------3 中序遍历-------" << endl;
	cout << "-------4 A  S  L--------" << endl;
	cout << "-------5 删除元素-------" << endl;
	cout << "-------0 退    出-------" << endl;
	cout << "------------------------" << endl;
}

Node* BST::insert(Node* node, const int& val) {
	if (node == nullptr) {
		node = new Node(val);
	}

	if (node->_val > val) {
		node->_left = insert(node->_left, val);
	}
	else if(node->_val < val) {
		node->_right = insert(node->_right, val);
	}

	return node;
}

void BST::push(const int& val) {
	// 将加入的数据保存到原数组
	if (find(val)) {
		cout << val << " 已经存在于二叉排序树中 ！！！" << endl;
		return;
	}

	if (_root == nullptr) {
		_root = new Node(val);
		_arr.push_back(val);
		return;
	}

	_arr.push_back(val);
	
	insert(_root, val);
}

void BST::clear(Node*& node) {
	// 递归结束条件
	if (node == nullptr) return;

	clear(node->_left);
	clear(node->_right);

	// 释放节点空间
	delete node;
	node = nullptr;
}

void BST::read_file(string file) {
	ifstream input_File(file);
	if (!input_File.is_open()) {
		cout << " 文件打开失败" << endl;
	}

	int num;
	while (input_File >> num) {
		push(num);
	}

	input_File.close();
	cout << "读取成功！！！" << endl;
}

BST::~BST() {
	clear(_root);
}

void BST::really_in_order(Node* node) {
	if (node == nullptr) return;

	really_in_order(node->_left);
	cout << node->_val << " ";
	really_in_order(node->_right);
}


void BST::in_order() {
	really_in_order(_root);
	cout << endl;
}

int BST::calculateASL(Node* node, int depth, int& counts) {
	if (node == nullptr) return 0;

	counts++;
	return depth + calculateASL(node->_left, depth + 1, counts) + calculateASL(node->_right, depth + 1, counts);
}

void BST::ASL() {
	assert(_arr.size() != 0);

	int counts = 0;
	int depth = 1;
	cout << "ASL: " << calculateASL(_root, depth, counts) / counts << endl;
}

void BST::pop(const int& val) {
	assert(_arr.size() != 0);

	if (!find(val)) {
		cout << "不包含此元素" << endl;
		return;
	}

	// 释放该元素
	_arr.erase(std::find(_arr.begin(), _arr.end(), val));
	clear(_root); // 删除二叉树

	vector<int> temp = _arr;
	_arr.clear();

	for (auto& e : temp) {
		push(e);
	}

	cout << "删除成功！！！" << endl;
	in_order();
}

void init_bst() {
	int num = 0;
	while (num != -1) {
		cout << "请输入元素(输入-1结束)：";
		cin >> num;
		bt.push(num);
	}
	cout << "s初始化成功！！！" << endl;
}

void del_val() {
	int num = 0;
	cout << "输出想要删除的元素：";
	cin >> num;
	bt.pop(num);
}

bool BST::is_exist(Node* node, const int& val) {
	if (node == nullptr) return false;

	if (node->_val == val) return true;
	if (node->_val > val) return is_exist(node->_left, val);
	else return is_exist(node->_right, val);
}

bool BST::find(const int& val) {
	return is_exist(_root, val);
}

void Build_BST() {
	int choice = 0;
	do {
		BST_Menu();

		cin >> choice;
		system("cls");

		switch (choice) {
		case 1:
			bt.read_file();
			break;
		case 2:
			init_bst();
			break;
		case 3:
			bt.in_order();
			break;
		case 4:
			bt.ASL();
			break;
		case 5:
			del_val();
			break;
		}
	} while (choice);
}