#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
long long* arr;
long long answer = 1000000000000000001;

void binarySearch(long long left, long long right)
{
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long finished = 0;
		for (int i = 0; i < N; i++)
		{
			finished += mid / arr[i];
			if (finished > M)
			{
				break;
			}
		}
		if (finished < M)
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

	cin >> N >> M;
	arr = new long long[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	binarySearch(1, 1000000000000000001);
	cout << answer << "\n";
	return 0;
}