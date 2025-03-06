#include <iostream>
using namespace std;
int N;
int* arr;

int getGCD(int x, int y)
{
	if (y == 0)
	{
		return x;
	}
	else
	{
		return getGCD(y, x % y);
	}
}

int getRangeGCD(int left, int right)
{
	if (left == right)
	{
		return arr[left];
	}
	else
	{
		int gcd = getGCD(arr[left], arr[right]);
		for (int i = left + 1; i < right; i++)
		{
			gcd = getGCD(arr[i], gcd);
		}
		return gcd;
	}
}

int divide(int N, int left, int right)
{
	if (N == 1)
	{
		return arr[left];
	}
	int leftEnd = left + N / 2 - 1;
	int rightRangeCount = N - N / 2;
	int leftDivide = getRangeGCD(left, leftEnd) + divide(rightRangeCount, leftEnd + 1, right);
	int rightDivide = divide(N/2, left, leftEnd) + getRangeGCD(leftEnd + 1, right);

	return max(leftDivide, rightDivide);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int answer = divide(N, 0, N - 1);
	cout << answer << "\n";
	return 0;
}