#include<iostream>

using namespace std;
typedef struct LNode
{
	int data;
	LNode* next;
};

LNode* remove(LNode* l)
{
	bool flag[100] = { false};            //布尔类型判断是否出现

	LNode* q = l;
	LNode* p =l ->next;
	while (p!=NULL)
	{
		int value = p->data > 0 ? p->data : -1 * p->data;
		if(flag[value])//避免了用fabs
		{
			q->next = p->next;
			delete p;
			p = q->next;
		}
		else
		{
			flag[value] = true;
			q = p;
			p = p->next;
		}
	}
	return l;

}



int main()
{
	LNode* l = new LNode;
	l->next = NULL;
	LNode* tail = l;
	int n,m;
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++)
	{
		int value;
		cin >> value;
		LNode* p = new LNode;
		p->data = value;
		p->next = NULL;
		tail->next = p;
		tail = p;

	}

	LNode* list = remove(l);
	LNode* q = list->next;
	while (q)
	{
		cout << q->data << endl;
		q = q->next;
	}
	system("pause");
	return 0;
}