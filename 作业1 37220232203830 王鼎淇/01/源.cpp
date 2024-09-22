#include<iostream>
using namespace std;
int findit(int* a, int n)
{
	int* p = new int[n];//创建一个动态数组用于表示前n个正整数是否出现。
	memset(p, 0, n);
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0 && a[i] <= n)
		{
			p[a[i] - 1] == 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (p[i] == 0)
		{
			return i + 1;
			
		}
	}
	return n + 1;
}

int main()
{
	int a[4] = { -5,3,2,3 };
	cout << findit(a, 4);
	system("pause");
	return 0;
}
