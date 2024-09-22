#include<iostream>
using namespace std;

typedef struct LNode
{
    char data;  // 将数据类型修改为 char
    LNode* next;
} LNode;

int length(LNode* list)
{
    LNode* p = list;
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

LNode* search(LNode* l1, LNode* l2)
{
    int len1 = (length(l1->next));
    int len2 = (length(l2->next));
    LNode* p = l1->next;
    LNode* q = l2->next;
    if (len1 > len2)
    {
        for (int i = 0; i < len1 - len2; i++)
        {
            p = p->next;
        }
    }
    else
    {
        for (int i = 0; i < len2 - len1; i++)
        {
            q = q->next;
        }
    }
    while (p && q)
    {
        if (p->data == q->data)
        {
            return p;
        }
        p = p->next;
        q = q->next;
    }
    return NULL;
}
int main()
{
    // 创建链表 l1 和 l2（头节点）
    LNode* l1 = new LNode;
    l1->next = NULL;
    LNode* l2 = new LNode;
    l2->next = NULL;

    // 手动设置一个交叉节点以测试
    LNode* common = new LNode;
    common->data = 'i';
    common->next = new LNode;
    common->next->data = 'n';
    common->next->next = new LNode;
    common->next->next->data = 'g';
    common->next->next->next = NULL;

    // 设置链表 l1 的部分数据
    LNode* p1 = new LNode;
    p1->data = 'l';
    p1->next = new LNode;
    p1->next->data = 'o';
    p1->next->next = common;  // 链表 l1 与链表 l2 在 common 处相交
    l1->next = p1;

    // 设置链表 l2 的部分数据
    LNode* p2 = new LNode;
    p2->data = 'b';
    p2->next = new LNode;
    p2->next->data = 'e';
    p2->next->next = common;  // 链表 l2 与链表 l1 在 common 处相交
    l2->next = p2;

    // 调用 search 函数，寻找第一个公共节点
    LNode* intersection = search(l1, l2);
    if (intersection)
    {
        cout << "第一个公共节点的字符是: " << intersection->data << endl;
    }
    else
    {
        cout << "没有公共节点" << endl;
    }

    return 0;
}