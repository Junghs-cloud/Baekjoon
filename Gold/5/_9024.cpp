#include <iostream>
#include <algorithm>
using namespace std;
int* arr;
long long diff = 200000001;
long long answerCount = 0;
int N, K;
void binarySearch(int left, int right)
{
	int initialIndex = left-1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		long long sum = arr[mid] + arr[initialIndex];
		if (sum == K)
		{
			if (diff == 0)
			{
				answerCount++;
			}
			else
			{
				diff = 0;
				answerCount = 1;
			}
			break;
		}
		else if (sum < K)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}

		if (abs(K - sum) < diff)
		{
			diff = abs(K - sum);
			answerCount = 1;
		}
		else if (abs(K - sum) == diff)
		{
			answerCount++;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		answerCount = 0;
		diff = 200000001;
		cin >> N >> K;
		arr = new int[N];
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + N);
		for (int i = 0; i < N; i++)
		{
			binarySearch(i + 1, N-1);
		}
		cout << answerCount << "\n";
	}
	return 0;
}