#pragma once
#include "stdio.h"
#include "malloc.h"
#include <iostream>
#include <stack>
#include <queue>
using namespace std;


typedef struct AVLNode
{
    int data = 0;//���ֵ
    int depth = 0;//���
    struct AVLNode* father = NULL;//�����
    struct AVLNode* lchild = NULL, * rchild = NULL;//���ҽ��
} AVLNode, * AVLTree; //���ṹ��

int count_depth(AVLTree& T)//������������
{
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        int l = count_depth(T->lchild);//���������
        int r = count_depth(T->rchild);//���������
        return T->depth = max(l, r) + 1;//�������
    }
}

int get_balance(AVLTree T)//��ȡ���
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

int count_balance(AVLTree T)//����ƽ������
{
    if (!T)
    {
        return 0;
    }
    else
    {
        return get_balance(T->lchild) - get_balance(T->rchild);//ƽ�����ӵ����������������֮��
    }
}

AVLTree LL_rotate(AVLTree T)
{
    AVLTree parent = NULL, son;//son��㼴Ϊ��ת����
    parent = T->father;//��ȡʧ����ĸ��ڵ�
    son = T->lchild;//��ȡʧ���������
    if (son->rchild != NULL)//����son����Һ��ӵĸ�ָ��
        son->rchild->father = T;
    T->lchild = son->rchild;//ʧ��������ӱ��Ϊson���Һ���
    //T���ӽ��������
    count_depth(T);//����ʧ����������Ϣ
    son->rchild = T;//ʧ������son���Һ���
    son->father = parent;//����son�ĸ����Ϊԭʧ����ĸ���㣬����������
    //���ʧ���㲻�Ǹ���㣬����¸��ڵ�
    if (parent != NULL)
    {
        //������ڵ��������ʧ���㣬ָ�����ڸ��º���º���son
        if (parent->lchild == T)
            parent->lchild = son;
        else //���ڵ���Һ�����ʧ����
            parent->rchild = son;
    }
    T->father = son;//����ʧ����ĸ���
    count_depth(son);//����son���ĸ߶���Ϣ
    return son;
}



AVLTree RR_rotate(AVLTree T)
{
    AVLTree parent = NULL, son;//son��㼴Ϊ��ת����
    parent = T->father;//��ȡʧ����ĸ��ڵ�
    son = T->rchild;//��ȡʧ������Һ���
    if (son->lchild != NULL)//����son������ӵĸ�ָ��
        son->lchild->father = T;
    T->rchild = son->lchild;//ʧ������Һ��ӱ��Ϊson������
    //T���ӽ��������
    count_depth(T);//����ʧ����ĸ߶���Ϣ
    son->lchild = T;//ʧ������son���Һ���
    son->father = parent;//����son�ĸ����Ϊԭʧ����ĸ���㣬����������
    //���ʧ���㲻�Ǹ���㣬����¸��ڵ�
    if (parent != NULL)
    {
        //������ڵ��������ʧ���㣬ָ�����ڸ��º���º���son
        if (parent->lchild == T)
            parent->lchild = son;
        else //���ڵ���Һ�����ʧ����
            parent->rchild = son;
    }
    T->father = son;//����ʧ����ĸ���
    count_depth(son);//����son���ĸ߶���Ϣ
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

AVLTree AVLchange(AVLTree& T, AVLTree S)//����Ϊƽ�������
{
    int balance = 0;//ƽ������
    while (S)
    {
        count_depth(T);//�������
        balance = count_balance(S);//����ƽ������
        if (balance > 1 || balance < -1)
        {
            if (balance > 1)//L��
            {
                if (count_balance(S->lchild) > 0)//LL��
                {
                    S = LL_rotate(S);
                }
                else  //LR��
                {
                    S = LR_rotate(S);
                }
            }
            if (balance < 1)//R��
            {
                if (count_balance(S->rchild) < 0) //RR��
                    S = RR_rotate(S);
                else //RL��
                    S = RL_rotate(S);
            }
            if (S->father == NULL)//������ڵ㣬�˳�ѭ��
            {
                T = S;//����Ϊ�µĸ��ڵ�
                break;
            }
        }
        S = S->father;//һ��һ�����ϵ���
    }
    return T;
}

AVLTree InsertAVL(AVLTree& T, int e, AVLTree parent)
{
    if (!T)//�ҵ�������λ��
    {
        AVLNode* S;
        S = new AVLNode;
        S->data = e;
        S->father = parent;
        S->lchild = S->rchild = NULL;
        T = S;
        return S;
    }
    else if (e < T->data)//��������
    {
        return InsertAVL(T->lchild, e, T);
    }
    else if (e > T->data)//��������
    {
        return InsertAVL(T->rchild, e, T);
    }
    return NULL;//�ý���Ѵ���
}

AVLTree Insert(AVLTree& T, int e)
{
    AVLNode* S;
    S = new AVLNode;
    S = InsertAVL(T, e, NULL);//������
    count_depth(T);//���������Ϣ
    T = AVLchange(T, S);//����Ϊƽ�������
    return T;
}

// AVL���ĳ�ʼ��
void creativetree(AVLTree& T)
{
    T = NULL;
    int num = 0;
    while(num != -1)
    {
        cout << "������Ԫ��(���� -1 ����)��";
        cin >> num;
        T = Insert(T, num);
    }
}

// ������� AVL
void in_order_AVL(AVLTree& T){
    if (T == nullptr) return;

    in_order_AVL(T->lchild);
    cout << T->data << " ";
    in_order_AVL(T->rchild);
}

AVLTree avl;

// AVL���˵�
void AVL_Menu() {
    cout << "------------------------" << endl;
    cout << "-------1 ��ʼ����-------" << endl;
    cout << "-------2 �������-------" << endl;
    cout << "-------3 A  S  L--------" << endl;
    cout << "-------0 ��    ��-------" << endl;
    cout << "------------------------" << endl;
}

// ����AVL����AVL
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