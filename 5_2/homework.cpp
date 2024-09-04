//#include "stdio.h"
//#include "malloc.h"
////������ ��� 
//struct node {
//	char data;
//	struct node* lchild, * rchild;
//}bnode;
//
//typedef struct node* blink;
//
//
//blink create_binary()
//{
//	blink bt;
//	char ch;
//	ch = getchar();
//	if (ch == '#')
//	{
//		bt = NULL;
//	}
//	else
//	{
//		bt = (blink)malloc(sizeof(bnode));
//
//		bt->data = ch;
//		bt->lchild = NULL;
//		bt->rchild = NULL;
//		bt->lchild = create_binary();
//		bt->rchild = create_binary();
//
//	}
//	return bt;
//}
//
////���� ���� 
//void inorder(blink bt)
//{
//	if (bt != NULL)//���� ����� 
//	{
//		printf("(");
//		inorder(bt->lchild); //��
//		printf("%c", bt->data);//��
//		inorder(bt->rchild); //�� 
//		printf(")");
//	}
//
//	return;
//}
//
////������� 
//void preorder(blink bt)
//{
//	/*
//	����test_one
//	*/
//
//	if (bt != NULL)//���� ����� 
//	{
//		printf("%c", bt->data);//��
//		preorder(bt->lchild); //��
//		preorder(bt->rchild); //��
//
//	}
//
//	return;
//}
//
////������� 
//void postorder(blink bt)
//{
//	if (bt != NULL)//���� ����� 
//	{
//		postorder(bt->lchild); //��
//		postorder(bt->rchild); //��
//		printf("%c", bt->data);//��
//	}
//
//	return;
//}
//
//
//
//blink FreeTree(blink T)
//{
//	if (T)
//	{
//		FreeTree(T->lchild);           
//		FreeTree(T->rchild);          
//
//		free(T);              
//		T = NULL;                     
//	}
//
//	return T; 
//
//}
//
//void homework_1() {
//	blink root = NULL;//�� ���
//
//	root = create_binary();
//	printf("\n�� �� �������  ������\n");
//	preorder(root);//�������  ������ 
//	printf("\n");
//	inorder(root);//�������  ������ 
//	printf("\n");
//	postorder(root);//���� ���� ������ 
//
//	printf("\n");
//	free(FreeTree(root));//�ͷ� �ռ�
//}
//
//int main(){
//	homework_1();
//}

//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//// �������ڵ�Ľṹ
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//};
//
//// �������������
//void levelOrder(TreeNode* root) {
//    if (root == nullptr) return;
//
//    queue<TreeNode*> q;
//    q.push(root);
//
//    while (!q.empty()) {
//        int levelSize = q.size(); // ��ǰ��Ľڵ�����
//
//        // ������ǰ������нڵ�
//        for (int i = 0; i < levelSize; ++i) {
//            TreeNode* node = q.front();
//            q.pop();
//            cout << node->val << " ";
//
//            // ����ǰ�ڵ���ӽڵ㣨����У��������
//            if (node->left) q.push(node->left);
//            if (node->right) q.push(node->right);
//        }
//
//        cout << endl;
//    }
//}
//
//int main() {
//    // ����һ��ʾ��������
//    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(3);
//    root->left->left = new TreeNode(4);
//    root->left->right = new TreeNode(5);
//    root->right->left = new TreeNode(6);
//    root->right->right = new TreeNode(7);
//
//    cout << "������������" << endl;
//    levelOrder(root);
//
//    return 0;
//}

#include<iostream>  
#include<cmath> // ���� std::ceil  

#define N 4  
int time; // ʱ��Ƭ  

struct node {
    char jcbh; // ��������  
    int tsysj; // ��������ʱ��  
    int sysj; // ����ʣ��ʱ��  
};

void torun(node jc[]) {
    int nt = 0;
    double ans1 = 0, ans2 = 0;

    // �������  
    node q[N];
    int hh = 0, tt = -1;

    // �����������  
    for (int i = 0; i < N; ++i) {
        q[++tt] = jc[i];
    }

    std::cout << "��������Ϊ:";
    while (hh <= tt) {
        // ��¼��ǰʱ��  
        nt += time;

        // ȡ����ͷ����  
        node tmp = q[(hh++) % N];
        int ts = tmp.tsysj;

        // ִ��һ��ʱ��Ƭ��ʱ��  
        tmp.sysj -= time;

        // �ж��Ƿ�ִ����  
        // δִ�������������  
        if (tmp.sysj > 0) q[(++tt) % N] = tmp;
        else {
            // ����ƽ����תʱ��ʱ����Ҫ����ȡ������Ϊ���̿�����ĳ��ʱ��Ƭ֮���������  
            ans1 += std::ceil(static_cast<double>(nt) / N);

            switch (tmp.jcbh) {
            case 'A': ans2 += nt / static_cast<double>(ts) / N; break;
            case 'B': ans2 += nt / static_cast<double>(ts) / N; break;
            case 'C': ans2 += nt / static_cast<double>(ts) / N; break;
            case 'D': ans2 += nt / static_cast<double>(ts) / N; break;
            }
        }

        std::cout << tmp.jcbh;
    }

    std::cout << "\nƽ����תʱ��=" << ans1 << " ƽ����Ȩ��תʱ��=" << ans2 << std::endl;
    return;
}

int main() {
    node jc[N];

    // ��ʼ��������  
    jc[0].jcbh = 'A';
    jc[0].tsysj = jc[0].sysj = 20;

    jc[1].jcbh = 'B';
    jc[1].tsysj = jc[1].sysj = 10;

    jc[2].jcbh = 'C';
    jc[2].tsysj = jc[2].sysj = 15;

    jc[3].jcbh = 'D';
    jc[3].tsysj = jc[3].sysj = 5;

    std::cout << "��ʱ��ƬΪ1msʱ\n";
    time = 1;
    torun(jc);

    std::cout << "\n��ʱ��ƬΪ5msʱ\n";
    time = 5;
    torun(jc);

    return 0;
}
