#include <iostream>
using namespace std;

int binarySearch(int start, int end, int target, long long* arr)
{
	int left = start;
	int right = end;
	int answer = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] <= target)
		{
			left = mid + 1;
			answer = max(answer, mid);
		}
		else
		{
			right = mid - 1;
		}
	}
	return answer;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, T;
	cin >> N >> M;
	long long* sums = new long long[N+1];
	sums[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> T;
		sums[i] = sums[i-1] + T;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> T;
		cout << binarySearch(0, N, T, sums) << "\n";
	}
	return 0;
}