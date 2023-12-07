#include <iostream>
#include <algorithm>
using namespace std;
int* arr;
int rightIndex;
long long answer = 0;

void binarySearch(int left, int right, int value)
{
	int firstLeft = left;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (value == arr[mid])
		{
			if (arr[firstLeft] == arr[mid])
			{
				return;
			}
			answer++;
			rightIndex = mid;
			return;
		}
		else if (arr[mid] < value)
		{
			left = mid + 1;
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

	int N;
	int x;
	cin >> N;
	arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	cin >> x;
	rightIndex = N - 1;
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		binarySearch(i, rightIndex, x - arr[i]);
	}
	cout << answer << "\n";
	return 0;
}