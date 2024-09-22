#include<iostream>
using namespace std;
void revers(int a[], int left, int right)
{
	int i = left, j = right;
	while (i < j)
	{
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		i++; j--;
	}
}

	void shift(int a[], int p, int n)
	{
		if (p > 0 && p < n)
		{
			revers(a, 0, n - 1);
			revers(a, 0, n - p - 1);
			revers(a, n - p, n - 1);
		}
	}

	int main()
	{
		int a[100] = { 0 };
		int n, p;
		cin >> n >> p;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		shift(a, p, n);

		for (int i = 0; i < n; i++)
		{
			cout<<a[i]<<" ";
		}

		system("pause");
		return 0;

}