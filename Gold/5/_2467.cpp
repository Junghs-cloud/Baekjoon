#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int minSum = 2000000001;
int A;
int B;
int* arr;
void binarySearch(int left, int right, int value)
{
	while (left<= right)
	{
		int mid = (left + right) / 2;
		int currentSum = value + arr[mid];
		if (arr[mid] == -value)
		{
			if (value < 0)
			{
				A = value;
				B = arr[mid];
			}
			else
			{
				A = arr[mid];
				B = value;
			}
			minSum = 0;
			return;
		}
		else
		{
			if (currentSum < 0)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
			if (abs(currentSum) < minSum)
			{
				minSum = abs(currentSum);
				if (value < arr[mid])
				{
					A = value;
					B = arr[mid];
				}
				else
				{
					A = arr[mid];
					B = value;
				}
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i < N; i++)
	{
		binarySearch(0, i - 1, arr[i]);
	}
	for (int i = 0; i < N-1; i++)
	{
		binarySearch(i + 1, N - 1, arr[i]);
	}
	cout << A << " " << B << "\n";
	return 0;
}