#include <iostream>
using namespace std;

//// ����һ������ṹ
//typedef struct Node {
//    int val;
//    struct Node* next;
//} Node;
//
//// ��ֵ����
//void insert(Node* head, int value) {
//    // ����һ���ڵ�
//    Node* new_node = new Node();
//    new_node->val = value;
//    new_node->next = NULL;
//
//    Node* cur = head;
//    while (cur->next != NULL && cur->next->val < value) {
//        cur = cur->next;
//    }
//    new_node->next = cur->next;
//    cur->next = new_node;
//}
//
//void printlist(Node* head) {
//    Node* node = head->next;
//    while (node != NULL) {
//        cout << node->val << ' ';
//        node = node->next;
//    }
//}
//
//Node* LA_and_LB(Node* Lhead, Node* Rhead) {
//    Node* LA = Lhead->next;
//    Node* LB = Rhead->next;
//    Node* LC = new Node();
//    Node* cur = LC;
//
//    while (LA != NULL && LB != NULL) {
//        if (LA->val <= LB->val) {
//            cur->next = LA;
//            LA = LA->next;
//        }
//        else {
//            cur->next = LB;
//            LB = LB->next;
//        }
//        cur = cur->next;
//    }
//
//    cur->next = (LA != NULL) ? LA : LB;
//
//    return LC;
//}
//
//int main() {
//    Node* Lhead = new Node();
//    Lhead->next = NULL;
//
//    cout << "ΪLNode����(����-1����):" << endl;
//    while (true) {
//        int temp = 0;
//        cin >> temp;
//        if (temp == -1) break;
//        insert(Lhead, temp);
//    }
//
//    Node* Rhead = new Node();
//    Rhead->next = NULL;
//
//    cout << "ΪRNode����(����-1����):" << endl;
//    while (true) {
//        int temp = 0;
//        cin >> temp;
//        if (temp == -1) break;
//        insert(Rhead, temp);
//    }
//
//    Node* LC = LA_and_LB(Lhead, Rhead);
//    printlist(LC);
//
//    return 0;
//}




typedef struct Node {
	int val;
	struct Node* next;
}Node;

Node* init_list(int n, int s) {
	Node* head = (Node*)malloc(sizeof(Node));
	Node* cur = head;

	for (int i = 1; i < n + 1; i++) {
		cur->val = i;
		if (i != n) {
			Node* next = (Node*)malloc(sizeof(Node));
			cur->next = next;
			cur = next;
		}
	}

	cur->next = head;

	while (head->next->val != s) {
		head = head->next;
	}

	return head;
}

void Counting(Node* head, int n, int m) {
	int count = 0;

	while (count != n) {
		for (int i = 1; i < m; i++) {
			head = head->next;
		}

		cout << head->next->val << endl;
		head->next = head->next->next;
		count++;
	}
}

int main() {
	int n, m, s;
	cout << "�������ж����ˣ�";
	cin >> n;
	
	cout << "�ڼ����˿�ʼ������";
	cin >> s;

	cout << "�����ڼ��˳��У�";
	cin >> m;

	Node* head = init_list(n, s);
	Counting(head, n, m);
}

