#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// 创建一个链表
typedef struct Node {
	// 存储的值
	int val;
	// 指向下一个节点
	struct Node* next;
}Node;

// 申请一个n个长度的链表
Node* init_linked_list(int n, vector<int>& num) {
	// 初始化头节点
	Node* head = (Node*)malloc(sizeof(Node));

	// head的next指向NULL
	head->next = NULL;

	// 创建新的指针指向head同样的地址，避免丢失head
	Node* cur = (Node*)malloc(sizeof(Node));
	cur = head;

	// 循环创建节点
	while (n--) {
		// 尾插法创建链表
		Node* new_list = (Node*)malloc(sizeof(Node));
		new_list->val = num.front();
		num.erase(num.begin());
		new_list->next = cur->next;
		cur->next = new_list;
		cur = new_list;
	}

	// 返回head
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
                // 交换 arr[j] 和 arr[j + 1]
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 主程序
//int main() {
//	int n = 0;
//	cout << "请输入维度：";
//	cin >> n;
//
//	vector<int> num_1;
//	vector<int> num_2;
//
//	cout << "请输入" << n << "个数字给A链表：";
//	for (int i = 0; i < n; i++) {
//		int num;
//		cin >> num;
//		num_1.push_back(num);
//	}
//
//	cout << "请输入" << n << "个数字给B链表：";
//	for (int i = 0; i < n; i++) {
//		int num;
//		cin >> num;
//		num_2.push_back(num);
//	}
//
//	// 创建 && 初始化链表
//	Node* A = init_linked_list(n, num_1);
//	Node* B = init_linked_list(n, num_2);
//
//	double result = cal_similarity(A, B);
//	cout << "最终结果是：" << result << endl;
//}

int main() {
	int n = 0;
	cout << "请输入维度：";
	cin >> n;

	vector<int> num_1;
	vector<int> num_2;
	vector<int> num_3;
	vector<int> num_4;
	vector<int> num_5;

	cout << "请输入" << n << "个数字给A链表：";
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		num_1.push_back(num);
	}

	cout << "请输入" << n << "个数字给B链表：";
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		num_2.push_back(num);
	}

	cout << "请输入" << n << "个数字给C链表：";
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		num_3.push_back(num);
	}

	cout << "请输入" << n << "个数字给D链表：";
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		num_4.push_back(num);
	}

	cout << "请输入" << n << "个数字给E链表：";
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		num_5.push_back(num);
	}


	vector<float> result;
	// 创建 && 初始化链表
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
//				return false;  // 括号不匹配
//			}
//			stk.pop();
//		}
//	}
//	return stk.empty();  // 括号匹配
//}
//
//int main() {
//	std::string input;
//	std::cout << "请输入你的表达式: ";
//	std::cin >> input;
//
//	if (isParenthesesMatched(input)) {
//		std::cout << "你的括号匹配." << std::endl;
//	}
//	else {
//		std::cout << "你的括号不匹配." << std::endl;
//	}
//
//	return 0;
//}


#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// 定义运算符的优先级
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

//// 执行算术运算
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
//// 计算算术表达式的值
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
//    cout << "输入你的算术表达式: ";
//    getline(cin, expr);
//    cout << "Result: " << evaluate(expr) << endl;
//    return 0;
//}



