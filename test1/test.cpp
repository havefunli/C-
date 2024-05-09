#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;

struct Book {
    string id;
    string name;
    double price;
};
typedef struct LinkNode {
    Book data;
    struct LinkNode* next;
} LinkNode, * LinkList;

string head_1, head_2, head_3;
int length;

Status InitList_L(LinkList& L) {
    L = NULL;
    return OK;
}

Status CreateList(LinkList& L) {
    LinkList p;
    L = new LinkNode;
    L->next = NULL;
    length = 0;
    fstream file;
    file.open("book.txt");
    if (!file) {
        cout << "δ�ҵ�����ļ����޷��򿪣�" << endl;
        exit(ERROR);
    }
    file >> head_1 >> head_2 >> head_3;
    while (!file.eof()) {
        p = new LinkNode;
        file >> p->data.id >> p->data.name >> p->data.price;
        p->next = L->next;
        L->next = p;
        length++;
    }
    file.close();
    return OK;
}

LinkNode* GetElem(LinkList L, int i) {
    LinkList p = L;
    for (int j = 0; j < i; j++) {
        p = p->next;
    }
    return p;
}

Status ListInsert(LinkList& L, int i, Book e)
{
    LinkList p = L;
    LinkList q = new LinkNode;
    if (i<1 || i>length + 1)
        return ERROR;
    for (int j = 0; j < i - 1; j++) {
        p = p->next;
    }
    q->data.id = e.id;
    q->data.name = e.name;
    q->data.price = e.price;
    //cout<<q->data.name<<endl;
    //cout<<e.name;
    q->next = p->next;
    p->next = q;
    length++;
    return OK;
}

Status ListDelete(LinkList& L, int i) {
    LinkList p = L, q;
    if (i<1 || i>length)
        return ERROR;
    for (int j = 0; j < i - 1; j++)
        p = p->next;
    q = p->next;
    p->next = p->next->next;
    delete q;
    return OK;
}

void OutputLinkList(LinkList& L) {
    LinkList p = L->next;
    while (p) {
        cout << "��ţ�" << p->data.id << " ������" << p->data.name << " �۸�" << p->data.price << endl;
        p = p->next;
    }
}

int main() {
    int a, choose;
    Book e;
    LinkList L = new LinkNode();
    LinkList p = L;
   
    cout << "1. ����\n";
    cout << "2. ����\n";
    cout << "3. ����\n";
    cout << "4. ɾ��\n";
    cout << "5. ���\n";
    cout << "0. �˳�\n\n";

    choose = -1;
    while (choose != 0) {
        cout << "��ѡ��:";
        cin >> choose;
        switch (choose) {
        case 1: //����һ������
            if (InitList_L(L))
                cout << "�ɹ���������!\n\n";
            break;
        case 2: //ʹ��ǰ/��巨��������
            CreateList(L);
            cout << "���� book.txt ��Ϣ���\n\n";
            break;
        case 3: //����Ĳ���
            cout << "�������������ֱ��������λ�ú���ֵ�������Ϣ�����&����&�۸�:";
            cin >> a;
            cin >> e.id >> e.name >> e.price;
            cout << e.name << endl;
            if (ListInsert(L, a, e))
                cout << "����ɹ�.\n\n";
            else
                cout << "����ʧ��!\n\n";
            break;
        case 4: //�����ɾ��
            cout << "��������Ҫɾ�����鼮��λ��:";
            cin >> a;
            if (ListDelete(L, a))
                cout << "ɾ���ɹ�!\n\n";
            else
                cout << "ɾ��ʧ��!\n\n";
            break;
        case 5: //��������
            cout << "��ǰͼ��ϵͳ��Ϣ����:\n";
            p = L->next;
            if (p)
                OutputLinkList(L);
            else
                cout << "û��ͼ����Ϣ!\n\n";
            break;
        }
    }
    return 0;
}