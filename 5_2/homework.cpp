//#include "stdio.h"
//#include "malloc.h"
////二叉树 结点 
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
////中序 遍历 
//void inorder(blink bt)
//{
//	if (bt != NULL)//中序 左根右 
//	{
//		printf("(");
//		inorder(bt->lchild); //左
//		printf("%c", bt->data);//根
//		inorder(bt->rchild); //右 
//		printf(")");
//	}
//
//	return;
//}
//
////先序遍历 
//void preorder(blink bt)
//{
//	/*
//	依照test_one
//	*/
//
//	if (bt != NULL)//中序 左根右 
//	{
//		printf("%c", bt->data);//根
//		preorder(bt->lchild); //左
//		preorder(bt->rchild); //右
//
//	}
//
//	return;
//}
//
////后序遍历 
//void postorder(blink bt)
//{
//	if (bt != NULL)//中序 左根右 
//	{
//		postorder(bt->lchild); //左
//		postorder(bt->rchild); //右
//		printf("%c", bt->data);//根
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
//	blink root = NULL;//根 结点
//
//	root = create_binary();
//	printf("\n先 中 后序遍历  二叉树\n");
//	preorder(root);//先序遍历  二叉树 
//	printf("\n");
//	inorder(root);//中序遍历  二叉树 
//	printf("\n");
//	postorder(root);//后序 遍历 二叉树 
//
//	printf("\n");
//	free(FreeTree(root));//释放 空间
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
//// 二叉树节点的结构
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//};
//
//// 层序遍历二叉树
//void levelOrder(TreeNode* root) {
//    if (root == nullptr) return;
//
//    queue<TreeNode*> q;
//    q.push(root);
//
//    while (!q.empty()) {
//        int levelSize = q.size(); // 当前层的节点数量
//
//        // 遍历当前层的所有节点
//        for (int i = 0; i < levelSize; ++i) {
//            TreeNode* node = q.front();
//            q.pop();
//            cout << node->val << " ";
//
//            // 将当前节点的子节点（如果有）加入队列
//            if (node->left) q.push(node->left);
//            if (node->right) q.push(node->right);
//        }
//
//        cout << endl;
//    }
//}
//
//int main() {
//    // 创建一个示例二叉树
//    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(3);
//    root->left->left = new TreeNode(4);
//    root->left->right = new TreeNode(5);
//    root->right->left = new TreeNode(6);
//    root->right->right = new TreeNode(7);
//
//    cout << "层序遍历结果：" << endl;
//    levelOrder(root);
//
//    return 0;
//}

#include<iostream>  
#include<cmath> // 用于 std::ceil  

#define N 4  
int time; // 时间片  

struct node {
    char jcbh; // 进程名称  
    int tsysj; // 进程所需时间  
    int sysj; // 进程剩余时间  
};

void torun(node jc[]) {
    int nt = 0;
    double ans1 = 0, ans2 = 0;

    // 定义队列  
    node q[N];
    int hh = 0, tt = -1;

    // 将进程入队列  
    for (int i = 0; i < N; ++i) {
        q[++tt] = jc[i];
    }

    std::cout << "进程依次为:";
    while (hh <= tt) {
        // 记录当前时间  
        nt += time;

        // 取出队头进程  
        node tmp = q[(hh++) % N];
        int ts = tmp.tsysj;

        // 执行一个时间片的时间  
        tmp.sysj -= time;

        // 判断是否执行完  
        // 未执行完重新入队列  
        if (tmp.sysj > 0) q[(++tt) % N] = tmp;
        else {
            // 计算平均周转时间时，需要向上取整，因为进程可能在某个时间片之后立即完成  
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

    std::cout << "\n平均周转时间=" << ans1 << " 平均带权周转时间=" << ans2 << std::endl;
    return;
}

int main() {
    node jc[N];

    // 初始化各进程  
    jc[0].jcbh = 'A';
    jc[0].tsysj = jc[0].sysj = 20;

    jc[1].jcbh = 'B';
    jc[1].tsysj = jc[1].sysj = 10;

    jc[2].jcbh = 'C';
    jc[2].tsysj = jc[2].sysj = 15;

    jc[3].jcbh = 'D';
    jc[3].tsysj = jc[3].sysj = 5;

    std::cout << "当时间片为1ms时\n";
    time = 1;
    torun(jc);

    std::cout << "\n当时间片为5ms时\n";
    time = 5;
    torun(jc);

    return 0;
}
