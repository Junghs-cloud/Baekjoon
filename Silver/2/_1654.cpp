#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
long long* arr;
long long answer;

void binarySearch(long long left, long long right)
{
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long fragmentCount = 0;
		for (int i = 0; i < N; i++)
		{
			fragmentCount += arr[i] / mid;
		}
		if (fragmentCount >= M)
		{
			left = mid + 1;
			answer = mid;
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

	cin >> N >> M;
	arr = new long long[N];
	for (int i=0;i<N;i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	binarySearch(1, arr[N-1]);
	cout << answer << "\n";
	return 0;
}