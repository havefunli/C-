#pragma once
#include "stdio.h"
#include "malloc.h"
#include <iostream>
#include <stack>
#include <queue>
using namespace std;


typedef struct AVLNode
{
    int data = 0;//结点值
    int depth = 0;//深度
    struct AVLNode* father = NULL;//父结点
    struct AVLNode* lchild = NULL, * rchild = NULL;//左右结点
} AVLNode, * AVLTree; //结点结构体

int count_depth(AVLTree& T)//计算各结点的深度
{
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        int l = count_depth(T->lchild);//左子树深度
        int r = count_depth(T->rchild);//右子树深度
        return T->depth = max(l, r) + 1;//更新深度
    }
}

int get_balance(AVLTree T)//读取深度
{
    if (T)
    {
        return T->depth;
    }
    else
    {
        return 0;
    }
}

int count_balance(AVLTree T)//计算平衡因子
{
    if (!T)
    {
        return 0;
    }
    else
    {
        return get_balance(T->lchild) - get_balance(T->rchild);//平衡因子等于左右子树的深度之差
    }
}

AVLTree LL_rotate(AVLTree T)
{
    AVLTree parent = NULL, son;//son结点即为旋转中心
    parent = T->father;//获取失衡结点的父节点
    son = T->lchild;//获取失衡结点的左孩子
    if (son->rchild != NULL)//设置son结点右孩子的父指针
        son->rchild->father = T;
    T->lchild = son->rchild;//失衡结点的左孩子变更为son的右孩子
    //T的子结点更新完毕
    count_depth(T);//更新失衡结点的深度信息
    son->rchild = T;//失衡结点变成son的右孩子
    son->father = parent;//设置son的父结点为原失衡结点的父结点，连接整颗树
    //如果失衡结点不是根结点，则更新父节点
    if (parent != NULL)
    {
        //如果父节点的左孩子是失衡结点，指向现在更新后的新孩子son
        if (parent->lchild == T)
            parent->lchild = son;
        else //父节点的右孩子是失衡结点
            parent->rchild = son;
    }
    T->father = son;//设置失衡结点的父亲
    count_depth(son);//更新son结点的高度信息
    return son;
}



AVLTree RR_rotate(AVLTree T)
{
    AVLTree parent = NULL, son;//son结点即为旋转中心
    parent = T->father;//获取失衡结点的父节点
    son = T->rchild;//获取失衡结点的右孩子
    if (son->lchild != NULL)//设置son结点左孩子的父指针
        son->lchild->father = T;
    T->rchild = son->lchild;//失衡结点的右孩子变更为son的左孩子
    //T的子结点更新完毕
    count_depth(T);//更新失衡结点的高度信息
    son->lchild = T;//失衡结点变成son的右孩子
    son->father = parent;//设置son的父结点为原失衡结点的父结点，连接整颗树
    //如果失衡结点不是根结点，则更新父节点
    if (parent != NULL)
    {
        //如果父节点的左孩子是失衡结点，指向现在更新后的新孩子son
        if (parent->lchild == T)
            parent->lchild = son;
        else //父节点的右孩子是失衡结点
            parent->rchild = son;
    }
    T->father = son;//设置失衡结点的父亲
    count_depth(son);//更新son结点的高度信息
    return son;
}

AVLTree LR_rotate(AVLTree T)
{
    RR_rotate(T->lchild);
    return LL_rotate(T);
}

AVLTree RL_rotate(AVLTree T)
{
    LL_rotate(T->rchild);
    return RR_rotate(T);
}

AVLTree AVLchange(AVLTree& T, AVLTree S)//调整为平衡二叉树
{
    int balance = 0;//平衡因子
    while (S)
    {
        count_depth(T);//计算深度
        balance = count_balance(S);//计算平衡因子
        if (balance > 1 || balance < -1)
        {
            if (balance > 1)//L型
            {
                if (count_balance(S->lchild) > 0)//LL型
                {
                    S = LL_rotate(S);
                }
                else  //LR型
                {
                    S = LR_rotate(S);
                }
            }
            if (balance < 1)//R型
            {
                if (count_balance(S->rchild) < 0) //RR型
                    S = RR_rotate(S);
                else //RL型
                    S = RL_rotate(S);
            }
            if (S->father == NULL)//到达根节点，退出循环
            {
                T = S;//更新为新的根节点
                break;
            }
        }
        S = S->father;//一层一层往上调整
    }
    return T;
}

AVLTree InsertAVL(AVLTree& T, int e, AVLTree parent)
{
    if (!T)//找到结点插入位置
    {
        AVLNode* S;
        S = new AVLNode;
        S->data = e;
        S->father = parent;
        S->lchild = S->rchild = NULL;
        T = S;
        return S;
    }
    else if (e < T->data)//向左搜索
    {
        return InsertAVL(T->lchild, e, T);
    }
    else if (e > T->data)//向右搜索
    {
        return InsertAVL(T->rchild, e, T);
    }
    return NULL;//该结点已存在
}

AVLTree Insert(AVLTree& T, int e)
{
    AVLNode* S;
    S = new AVLNode;
    S = InsertAVL(T, e, NULL);//插入结点
    count_depth(T);//更新深度信息
    T = AVLchange(T, S);//调整为平衡二叉树
    return T;
}

// AVL树的初始化
void creativetree(AVLTree& T)
{
    T = NULL;
    int num = 0;
    while(num != -1)
    {
        cout << "请输入元素(输入 -1 结束)：";
        cin >> num;
        T = Insert(T, num);
    }
}

// 中序遍历 AVL
void in_order_AVL(AVLTree& T){
    if (T == nullptr) return;

    in_order_AVL(T->lchild);
    cout << T->data << " ";
    in_order_AVL(T->rchild);
}

AVLTree avl;

// AVL树菜单
void AVL_Menu() {
    cout << "------------------------" << endl;
    cout << "-------1 初始化树-------" << endl;
    cout << "-------2 中序遍历-------" << endl;
    cout << "-------3 A  S  L--------" << endl;
    cout << "-------0 退    出-------" << endl;
    cout << "------------------------" << endl;
}

// 计算AVL树的AVL
int calculate_AVL_ASL(AVLTree& avl, int depth, int& counts) {
    if (avl == nullptr) return 0;

    counts++;
    return depth + calculate_AVL_ASL(avl->lchild, depth + 1, counts) + calculate_AVL_ASL(avl->rchild, depth + 1, counts);
}

void avl_ASL(AVLTree& avl) {
    int counts = 0;
    int depth = 1;
    cout << "ASL: " << calculate_AVL_ASL(avl, depth, counts) / counts << endl;
}

void Build_AVL() {
    int choice = 0;
    do {
        AVL_Menu();

        cin >> choice;
        system("cls");

        switch (choice) {
        case 1:
            creativetree(avl);
            break;
        case 2:
            in_order_AVL(avl);
            cout << endl;
            break;
        case 3:
            avl_ASL(avl);
            break;
        }
    } while (choice);
}