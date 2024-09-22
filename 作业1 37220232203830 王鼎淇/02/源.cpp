#include<iostream>
#include<math.h>
using namespace std;
int dist(int a, int b, int c)
{
	return abs(a - b) + abs(a - c) + abs(b - c);
}

int min(int a, int b, int c)
{
	if (a < b && a < c) return a;
	else if (b < a && b< c) return b;
	else return c;
}

int findit(int* a, int* b, int* c, int lens1, int lens2, int lens3)
{
	int i = 0, j = 0, k = 0;
	int max = 1000;
	int ans = 0;
	while (i < lens1 && j < lens2 && k < lens3)
	{
		ans = dist(a[i], b[j], c[k]);
		if (ans < max)
		{
			max = ans;
		}

		if (a[i] == min(a[i], b[j], c[k])) i++;
		else if (b[j] == min(a[i], b[j], c[k])) j++;
		else k++;
	}
	return max;
}

int main()
	{
	int a[3] = { -1,0,9 };
	int b[4] = { -25,-10,10,11 };
	int c[5] = { 2,9,17,30,41 };
	cout << findit(a, b, c, 3, 4, 5);
	system("pause");
	return 0;
	}