#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
long long N, T;

pair<long long, long long>* arr;
long long answer = 987654321;
void binarySearch(long long start, long long end)
{
	long long left = start;
	long long right = end;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long maxValue = 0;
		for (int i = 0; i < N; i++)
		{
			maxValue += min(arr[i].second, mid);
		}
		if (maxValue < T)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
			answer = min(answer, mid);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> T;
	arr = new pair<long long, long long>[N];
	long long minSum = 0;
	long long maxSum = 0;
	long long maxOfMin = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first >> arr[i].second;
		minSum += arr[i].first;
		maxSum += arr[i].second;
		maxOfMin = max(maxOfMin, arr[i].first);
	}
	sort(arr, arr + N);
	if (minSum > T || maxSum < T)
	{
		cout << -1 << "\n";
	}
	else
	{
		binarySearch(maxOfMin, 1000000000);
		cout << answer << "\n";
	}
	return 0;
}