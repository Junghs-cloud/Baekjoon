#include <iostream>
using namespace std;
int N, M;
int* arr;
long long answer = 1000000000001;

void binarySearch(long long start, long long end)
{
	long long left = start;
	long long right = end;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++)
		{
			sum += mid / arr[i];
		}
		if (sum >= M)
		{
			right = mid - 1;
			answer = min(answer, mid);
		}
		else
		{
			left = mid + 1;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	binarySearch(1, 1000000000000);
	cout << answer << "\n";
	return 0;
}