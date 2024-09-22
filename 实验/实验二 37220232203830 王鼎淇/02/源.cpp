#include<iostream>
using namespace std;

typedef struct LNode
{
    char data;  // �����������޸�Ϊ char
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
    // �������� l1 �� l2��ͷ�ڵ㣩
    LNode* l1 = new LNode;
    l1->next = NULL;
    LNode* l2 = new LNode;
    l2->next = NULL;

    // �ֶ�����һ������ڵ��Բ���
    LNode* common = new LNode;
    common->data = 'i';
    common->next = new LNode;
    common->next->data = 'n';
    common->next->next = new LNode;
    common->next->next->data = 'g';
    common->next->next->next = NULL;

    // �������� l1 �Ĳ�������
    LNode* p1 = new LNode;
    p1->data = 'l';
    p1->next = new LNode;
    p1->next->data = 'o';
    p1->next->next = common;  // ���� l1 ������ l2 �� common ���ཻ
    l1->next = p1;

    // �������� l2 �Ĳ�������
    LNode* p2 = new LNode;
    p2->data = 'b';
    p2->next = new LNode;
    p2->next->data = 'e';
    p2->next->next = common;  // ���� l2 ������ l1 �� common ���ཻ
    l2->next = p2;

    // ���� search ������Ѱ�ҵ�һ�������ڵ�
    LNode* intersection = search(l1, l2);
    if (intersection)
    {
        cout << "��һ�������ڵ���ַ���: " << intersection->data << endl;
    }
    else
    {
        cout << "û�й����ڵ�" << endl;
    }

    return 0;
}