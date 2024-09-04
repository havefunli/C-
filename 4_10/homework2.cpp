#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// ����һ������
typedef struct Node {
	// �洢��ֵ
	int val;
	// ָ����һ���ڵ�
	struct Node* next;
}Node;

// ����һ��n�����ȵ�����
Node* init_linked_list(int n, vector<int>& num) {
	// ��ʼ��ͷ�ڵ�
	Node* head = (Node*)malloc(sizeof(Node));

	// head��nextָ��NULL
	head->next = NULL;

	// �����µ�ָ��ָ��headͬ���ĵ�ַ�����ⶪʧhead
	Node* cur = (Node*)malloc(sizeof(Node));
	cur = head;

	// ѭ�������ڵ�
	while (n--) {
		// β�巨��������
		Node* new_list = (Node*)malloc(sizeof(Node));
		new_list->val = num.front();
		num.erase(num.begin());
		new_list->next = cur->next;
		cur->next = new_list;
		cur = new_list;
	}

	// ����head
	return head;
}

double cal_similarity(Node* A, Node* B) {
	Node* head_A = A->next;
	Node* head_B = B->next;

	float num = 0;
	int den_1 = 0;
	int den_2 = 0;

	while (head_A != NULL && head_B != NULL) {
		int A_val = head_A->val;
		int B_val = head_B->val;

		num += (A_val * B_val);
		den_1 += (A_val * A_val);
		den_2 += (B_val * B_val);

		head_A = head_A->next;
		head_B = head_B->next;
	}

	double result = num / (sqrt(den_1) * sqrt(den_2));

	return result;
}

void sorted(vector<float>& arr) {
	int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // ���� arr[j] �� arr[j + 1]
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ������
//int main() {
//	int n = 0;
//	cout << "������ά�ȣ�";
//	cin >> n;
//
//	vector<int> num_1;
//	vector<int> num_2;
//
//	cout << "������" << n << "�����ָ�A����";
//	for (int i = 0; i < n; i++) {
//		int num;
//		cin >> num;
//		num_1.push_back(num);
//	}
//
//	cout << "������" << n << "�����ָ�B����";
//	for (int i = 0; i < n; i++) {
//		int num;
//		cin >> num;
//		num_2.push_back(num);
//	}
//
//	// ���� && ��ʼ������
//	Node* A = init_linked_list(n, num_1);
//	Node* B = init_linked_list(n, num_2);
//
//	double result = cal_similarity(A, B);
//	cout << "���ս���ǣ�" << result << endl;
//}

int main() {
	int n = 0;
	cout << "������ά�ȣ�";
	cin >> n;

	vector<int> num_1;
	vector<int> num_2;
	vector<int> num_3;
	vector<int> num_4;
	vector<int> num_5;

	cout << "������" << n << "�����ָ�A����";
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		num_1.push_back(num);
	}

	cout << "������" << n << "�����ָ�B����";
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		num_2.push_back(num);
	}

	cout << "������" << n << "�����ָ�C����";
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		num_3.push_back(num);
	}

	cout << "������" << n << "�����ָ�D����";
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		num_4.push_back(num);
	}

	cout << "������" << n << "�����ָ�E����";
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		num_5.push_back(num);
	}


	vector<float> result;
	// ���� && ��ʼ������
	Node* A = init_linked_list(n, num_1);
	Node* B = init_linked_list(n, num_2);
	Node* C = init_linked_list(n, num_3);
	Node* D = init_linked_list(n, num_4);
	Node* E = init_linked_list(n, num_5);

	Node* list[5] = { A, B, C, D, E };
	for (int i = 0; i < 5; i++) {
		for (int k = i + 1; k < 5; k++) {
			result.push_back(cal_similarity(list[i], list[k]));
		}
	}

	sorted(result);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << ' ';
}



#include <iostream>
#include <stack>
#include <string>

bool isMatching(char opening, char closing) {
	return (opening == '(' && closing == ')') ||
		(opening == '[' && closing == ']') ||
		(opening == '{' && closing == '}');
}

//bool isParenthesesMatched(const std::string& str) {
//	std::stack<char> stk;
//	for (char ch : str) {
//		if (ch == '(' || ch == '[' || ch == '{') {
//			stk.push(ch);
//		}
//		else if (ch == ')' || ch == ']' || ch == '}') {
//			if (stk.empty() || !isMatching(stk.top(), ch)) {
//				return false;  // ���Ų�ƥ��
//			}
//			stk.pop();
//		}
//	}
//	return stk.empty();  // ����ƥ��
//}
//
//int main() {
//	std::string input;
//	std::cout << "��������ı��ʽ: ";
//	std::cin >> input;
//
//	if (isParenthesesMatched(input)) {
//		std::cout << "�������ƥ��." << std::endl;
//	}
//	else {
//		std::cout << "������Ų�ƥ��." << std::endl;
//	}
//
//	return 0;
//}


#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// ��������������ȼ�
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

//// ִ����������
//int applyOp(int a, int b, char op) {
//    switch (op) {
//    case '+': return a + b;
//    case '-': return a - b;
//    case '*': return a * b;
//    case '/': return a / b;
//    }
//    return 0;
//}
//
//// �����������ʽ��ֵ
//int evaluate(string expression) {
//    stack<int> values;
//    stack<char> ops;
//    for (int i = 0; i < expression.length(); i++) {
//        if (expression[i] == ' ')
//            continue;
//        else if (expression[i] == '(')
//            ops.push(expression[i]);
//        else if (isdigit(expression[i])) {
//            int val = 0;
//            while (i < expression.length() && isdigit(expression[i])) {
//                val = (val * 10) + (expression[i] - '0');
//                i++;
//            }
//            values.push(val);
//            i--;
//        }
//        else if (expression[i] == ')') {
//            while (!ops.empty() && ops.top() != '(') {
//                int val2 = values.top();
//                values.pop();
//                int val1 = values.top();
//                values.pop();
//                char op = ops.top();
//                ops.pop();
//                values.push(applyOp(val1, val2, op));
//            }
//            ops.pop();
//        }
//        else {
//            while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i])) {
//                int val2 = values.top();
//                values.pop();
//                int val1 = values.top();
//                values.pop();
//                char op = ops.top();
//                ops.pop();
//                values.push(applyOp(val1, val2, op));
//            }
//            ops.push(expression[i]);
//        }
//    }
//    while (!ops.empty()) {
//        int val2 = values.top();
//        values.pop();
//        int val1 = values.top();
//        values.pop();
//        char op = ops.top();
//        ops.pop();
//        values.push(applyOp(val1, val2, op));
//    }
//    return values.top();
//}
//
//int main() {
//    string expr;
//    cout << "��������������ʽ: ";
//    getline(cin, expr);
//    cout << "Result: " << evaluate(expr) << endl;
//    return 0;
//}



