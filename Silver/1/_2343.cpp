#include <iostream>
using namespace std;
int N, M;
int* arr;
int answer;
void binarySearch(int left, int right)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int blurayCount = 0;
		int currentTime = 0;
		int maxTime = 0;
		bool flag = false;
		for (int i = 0; i < N; i++)
		{
			if (arr[i] > mid)
			{
				flag = true;
				break;
			}
			currentTime += arr[i];
			if (currentTime > mid)
			{
				blurayCount++;
				currentTime -= arr[i];
				if (currentTime > maxTime)
				{
					maxTime = currentTime;
				}
				currentTime = arr[i];
			}
		}
		if (flag == true)
		{
			left = mid + 1;
			continue;
		}
		blurayCount++;
		if (currentTime > maxTime)
		{
			maxTime = currentTime;
		}
		if (blurayCount < M)
		{
			right = mid - 1;
			if (answer > maxTime)
			{
				answer = maxTime;
			}
		}
		else if (blurayCount > M)
		{
			left = mid + 1;
		}
		else
		{
			if (answer > maxTime)
			{
				answer = maxTime;
			}
			right = mid - 1;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N>>M;
	arr = new int[N];
	answer = 1000000000;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	binarySearch(1, 1000000);
	cout << answer << "\n";
	return 0;
}