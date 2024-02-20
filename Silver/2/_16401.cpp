#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int* arr;
long long answer;

void binarySearch(int left, int right)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (mid == 0)
		{
			mid++;
		}
		int index = lower_bound(arr, arr + M, mid) - arr;
		long long canGive = 0;
		for (int i = index; i < M; i++)
		{
			canGive += arr[i] / mid;
		}
		if (canGive >= N)
		{
			left = mid + 1;
			answer = mid;
		}
		if (canGive < N)
		{
			right = mid - 1;
			if (mid == 1)
			{
				break;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	arr = new int[M];
	for (int i = 0; i < M; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + M);
	binarySearch(0, 1000000001);
	cout << answer << "\n";
	return 0;
}