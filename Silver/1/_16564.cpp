#include <iostream>
#include <algorithm>
using namespace std;
int N, K;
int* arr;
int answer;

void binarySearch(int left, int right)
{
	while (left <= right)
	{
		int targetLevel = (left + right) / 2;
		int index = upper_bound(arr, arr + N, targetLevel) - arr;
		long long currentLevelUp = 0;
		for (int i = 0; i < index; i++)
		{
			currentLevelUp += targetLevel - arr[i];
		}
		if (currentLevelUp == K)
		{
			answer = targetLevel;
			return;
		}
		else if (currentLevelUp < K)
		{
			answer = targetLevel;
			left = targetLevel + 1;
		}
		else
		{
			right = targetLevel - 1;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	binarySearch(arr[0], 1000000001);
	cout << answer << "\n";
	return 0;
}