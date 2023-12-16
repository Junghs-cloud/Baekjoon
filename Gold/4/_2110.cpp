#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int* arr;
int answer = 0;

void binarySearch(int left, int right)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int count = 1;
		int prev = arr[0];
		for (int i = 1; i < N; i++)
		{
			if (arr[i] - prev >= mid)
			{
				count++;
				prev = arr[i];
			}
		}
		if (count >= M)
		{
			left = mid + 1;
			if (mid > answer)
			{
				answer = mid;
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

	cin >> N>>M;
	arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	binarySearch(1, arr[N-1]-arr[0]);
	cout << answer << "\n";
	return 0;
}