#include<iostream>
using namespace std;

int findmain(int* a, int n)
{
	int count[100] = { 0 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] == a[j])
			{
				count[i]++;
			}
		}
		if (count[i] > n / 2)
		{
			return a[i];
		}
	}
	return -1;
}

int main()
{
	int a[100], n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << findmain(a, n);
	system("pause");
	return 0;
}