#include <iostream>
#include <algorithm>
using namespace std;
int* arr;
int N, M;
int maxCost;
int maxIndex;
void binarySearch(int left, int right)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int currentSum = 0;
		for (int i = 0; i < N; i++)
		{
			if (arr[i] > mid )
			{
				currentSum += mid;
			}
			else
			{
				currentSum += arr[i];
			}
		}
		if (currentSum <= M)
		{
			left = mid+ 1;
			if (currentSum >= maxCost)
			{
				maxCost = currentSum;
				maxIndex = mid;
			}
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

	cin >> N;
	arr = new int[N];
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + N);
	cin >> M;
	if (M >= sum)
	{
		cout << arr[N - 1];
	}
	else
	{
		binarySearch(1, M);
		cout << maxIndex << "\n";
	}
	return 0;
}