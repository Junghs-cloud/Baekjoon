#include <iostream>
#include <algorithm>
using namespace std;
int S, C;
int* arr;
long long length = 0;

void binarySearch(long long left, long long right)
{
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long make = 0;
		for (int i = 0; i < S; i++)
		{
			make += arr[i] / mid;
		}
		if (make >= C)
		{
			left = mid + 1;
			length = max(length, mid);
		}
		else
		{
			right = mid - 1;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long sum = 0;
	cin >> S >> C;
	arr = new int[S];
	for (int i = 0; i < S; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	binarySearch(1, 1000000000000000);
	cout << sum - (length * C) << "\n";
	return 0;
}