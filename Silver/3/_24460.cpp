#include <iostream>
#include <algorithm>
using namespace std;
int** arr;
int sortArr[] = { 0, 0, 0, 0 };

int getSecond(int a, int b, int c, int d)
{
	sortArr[0] = a;
	sortArr[1] = b;
	sortArr[2] = c;
	sortArr[3] = d;
	sort(sortArr, sortArr + 4);
	return sortArr[1];
}

int divide(int length, int startX, int startY)
{
	if (length == 1)
	{
		return arr[startX][startY];
	}
	else if (length == 2)
	{
		return getSecond(arr[startX][startY], arr[startX][startY + 1], arr[startX + 1][startY], arr[startX + 1][startY + 1]);
	}
	else
	{
		int nextLength = length / 2;
		int a = divide(nextLength, startX, startY);
		int b = divide(nextLength, startX, startY + nextLength);
		int c = divide(nextLength, startX + nextLength, startY);
		int d = divide(nextLength, startX + nextLength, startY + nextLength);
		return getSecond(a, b, c, d);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	arr = new int* [N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << divide(N, 0, 0) << "\n";
	return 0;
}