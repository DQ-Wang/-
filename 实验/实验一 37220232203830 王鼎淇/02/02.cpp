#include<iostream>
using namespace std;

int findmid(int* a, int* b, int n)
{
	int s1 = 0, s2 = 0, d1 = n - 1, d2 = n - 1;//s表示指针首地址，d表示尾地址
	while (s1 != d1 || s2 != d2) 
	{
		int mid1 = (s1 + d1) / 2;
		int mid2 = (s2 + d2) / 2;
		if (a[mid1] == b[mid2]) return a[mid1];
		else if (a[mid1] < b[mid2])
		{
			if ((d1 - s1 + 1) % 2 == 0) //若a为偶数序列，则根据定义再取首地址时要加一位
			{
				s1 = mid1 + 1;
				d2 = mid2;
			}
			else
			{
				s1 = mid1;
				d2 = mid2;
			}
		}
		else 
		{
			if ((d2 - s2 + 1) % 2 == 0)
			{
				d1 = mid1;
				s2 = mid2 + 1;
			}
			else
			{
				d1 = mid1;
				s2 = mid2;
			}
		}
		
	}
	return a[s1] < b[s2] ? a[s1] : b[s2];
}
int main()
{
	int a[4] = { 1,5,8,9 };
	int b[4] = { 2,4,6,7 };
	cout << findmid(a, b, 4);
	system("pause");
	return 0;
}