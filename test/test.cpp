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
        cout << "未找到相关文件，无法打开！" << endl;
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
        cout << "编号：" << p->data.id << " 书名：" << p->data.name << " 价格：" << p->data.price << endl;
        p = p->next;
    }
}

int main() {
    int a, choose;
    Book e;
    LinkList L, p;
    cout << "1. 建立\n";
    cout << "2. 输入\n";
    cout << "3. 插入\n";
    cout << "4. 删除\n";
    cout << "5. 输出\n";
    cout << "0. 退出\n\n";

    choose = -1;
    while (choose != 0) {
        cout << "请选择:";
        cin >> choose;
        switch (choose) {
        case 1: //建立一个链表
            if (InitList_L(L))
                cout << "成功建立链表!\n\n";
            break;
        case 2: //使用前/后插法创建链表
            CreateList(L);
            cout << "输入 book.txt 信息完毕\n\n";
            break;
        case 3: //链表的插入
            cout << "请输入两个数分别代表插入的位置和数值（书的信息：编号&书名&价格）:";
            cin >> a;
            cin >> e.id >> e.name >> e.price;
            cout << e.name << endl;
            if (ListInsert(L, a, e))
                cout << "插入成功.\n\n";
            else
                cout << "插入失败!\n\n";
            break;
        case 4: //链表的删除
            cout << "请输入所要删除的书籍的位置:";
            cin >> a;
            if (ListDelete(L, a))
                cout << "删除成功!\n\n";
            else
                cout << "删除失败!\n\n";
            break;
        case 5: //链表的输出
            cout << "当前图书系统信息读出:\n";
            p = L->next;
            if (p)
                OutputLinkList(L);
            else
                cout << "没有图书信息!\n\n";
            break;
        }
    }
    return 0;
}