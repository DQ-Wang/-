#include<iostream>
using namespace std;
typedef struct  LNode
{
	int data;
	 LNode* next;
}LinkList,LNode;

int search(LinkList* list, int k)
{
	LNode* p = list->next; //����2����㣬p��q��k-1)��λ�ã���q�ߵ�β��ʱ��pΪ������k��
	LNode* q = list->next;
	int count = 0;
	while (q != 0)
	{
		if (count < k)
		{
			count++;
		}
		else
		{
			p = p->next;//��q��p֮�����kʱ������һ���ƶ�
		}
		q = q->next;
	}
	if (count < k)
	{
		return 0;
	}
	else
	{
		cout << p->data;
		return 1;
	}
}
int main()
{
	LinkList* list = new LNode;
	list->next = NULL;
	int n;
	cin >> n;
	LNode* tail = list;
	for (int i = 0; i < n; i++)
	{
		int value;
		cin >> value;
		LNode* node = new LNode;
		node->data = value;
		node->next = NULL;
		tail->next = node;
		tail = node;
	}
	int k;
	cin >> k;
	if (!search(list, k))
	{
		cout << "error" << endl;

	}
	system("pause");
	return 0;
}