#include "BST.h"

string PATH = "./NUMS.txt";
BST bt;

void Main_menu() {
	cout << "-------------------" << endl;
	cout << "-------1 BST-------" << endl;
	cout << "-------2 AVL-------" << endl;
	cout << "-------0 �˳�------" << endl;
	cout << "-------------------" << endl;
}

void BST_Menu() {
	cout << "------------------------" << endl;
	cout << "-------1 �ļ���ȡ-------" << endl;
	cout << "-------2 �ֶ�����-------" << endl;
	cout << "-------3 �������-------" << endl;
	cout << "-------4 A  S  L--------" << endl;
	cout << "-------5 ɾ��Ԫ��-------" << endl;
	cout << "-------0 ��    ��-------" << endl;
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
	// ����������ݱ��浽ԭ����
	if (find(val)) {
		cout << val << " �Ѿ������ڶ����������� ������" << endl;
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
	// �ݹ��������
	if (node == nullptr) return;

	clear(node->_left);
	clear(node->_right);

	// �ͷŽڵ�ռ�
	delete node;
	node = nullptr;
}

void BST::read_file(string file) {
	ifstream input_File(file);
	if (!input_File.is_open()) {
		cout << " �ļ���ʧ��" << endl;
	}

	int num;
	while (input_File >> num) {
		push(num);
	}

	input_File.close();
	cout << "��ȡ�ɹ�������" << endl;
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
		cout << "��������Ԫ��" << endl;
		return;
	}

	// �ͷŸ�Ԫ��
	_arr.erase(std::find(_arr.begin(), _arr.end(), val));
	clear(_root); // ɾ��������

	vector<int> temp = _arr;
	_arr.clear();

	for (auto& e : temp) {
		push(e);
	}

	cout << "ɾ���ɹ�������" << endl;
	in_order();
}

void init_bst() {
	int num = 0;
	while (num != -1) {
		cout << "������Ԫ��(����-1����)��";
		cin >> num;
		bt.push(num);
	}
	cout << "s��ʼ���ɹ�������" << endl;
}

void del_val() {
	int num = 0;
	cout << "�����Ҫɾ����Ԫ�أ�";
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