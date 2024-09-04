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
	// ���캯��
	BST(){}

	template<class Iterator>
	BST(Iterator first, Iterator last) {
		while (first != last) {
			push(*first);
			first++;
		}
	}
	
	// �Ķ������ļ���ȡ��
	void read_file(string file = PATH);

	// ɾ�����н��
	void clear(Node*& node);
	// �������� --- ʹ�ú���������ͷſռ�
	~BST();

	// �����µ�Ԫ��
	void push(const int& val);

	// ɾ��Ԫ��
	void pop(const int& val);

	// �������
	void in_order();

	// ƽ�����ҳ���
	int calculateASL(Node* root, int depth, int& counts);
	void ASL();

	// ����ľ���ʵ��
	Node* insert(Node* node, const int& val);

	// ��������ľ���ʵ��
	void really_in_order(Node* node);

	// Ѱ��ĳ��Ԫ���Ƿ����
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
