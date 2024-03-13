#include <iostream>
#include <algorithm>
using namespace std;
int* arr;
int* distArr;
int N, M, L;
int minAnswer = 0;

void binarySearch(int left, int right)
{
	minAnswer = L;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int counts = 0;
		for (int i = 0; i < N+1; i++)
		{
			if (distArr[i] > mid)
			{
				counts += distArr[i] / mid;
				if (distArr[i] % mid == 0)
				{
					counts--;
				}
			}
		}
		if (counts <= M)
		{
			right = mid - 1;
			minAnswer = min(mid, minAnswer);
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

	cin >> N>>M>>L;
	arr = new int[N];
	distArr = new int[N + 1];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	distArr[0] = arr[0];
	for (int i = 1; i < N; i++)
	{
		distArr[i] = abs(arr[i] - arr[i - 1]);
	}
	distArr[N] = L - arr[N - 1];
	binarySearch(1, L);
	cout << minAnswer << "\n";
	return 0;
}