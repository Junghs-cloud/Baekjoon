#include <iostream>
#include <algorithm>
using namespace std;
int* arr;
int N, M;
int answer = 0;
void binarySearch(int left, int right)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int index = lower_bound(arr, arr + N, mid) - arr;
		long long sum = 0;
		for (int i = index; i < N; i++)
		{
			sum += (arr[i]-mid);
		}
		if (sum == M)
		{
			answer = mid;
			break;
		}
		else if (sum < M)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
			answer = mid;
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
	sort(arr, arr + N);
	binarySearch(0, arr[N - 1]);
	cout << answer << "\n";
	return 0;
}