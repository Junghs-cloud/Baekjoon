#include <iostream>
using namespace std;
int N, M;
int* arr;
int minMoney;

void binarySearch(int low, int high)
{
	while (low <= high)
	{
		int mid = (low + high) / 2;
		int count = 0;
		int currentMoney = 0;
		for (int i = 0; i < N; i++)
		{
			if (currentMoney < arr[i])
			{
				currentMoney = mid;
				count++;
				currentMoney -=arr[i];
			}
			else
			{
				currentMoney -= arr[i];
			}
		}
		if (count > M)
		{
			low = mid + 1;
		}
		else
		{
			minMoney = mid;
			high = mid - 1;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	arr = new int[N];
	int maxDayMoney = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (arr[i] > maxDayMoney)
		{
			maxDayMoney = arr[i];
		}
	}
	binarySearch(maxDayMoney, 1000000001);
	cout << minMoney << "\n";
	return 0;
}