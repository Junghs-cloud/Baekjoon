#include <iostream>
#include <algorithm>
using namespace std;
int N, M, L;
int* arr;
int targetCuttingCount;
int answer;

void binarySearch(int left, int right)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int cuttingCount = 0;
		int cuttingPos = 0;
		for (int i = 1; i < M + 2; i++)
		{
			if (arr[i] - cuttingPos >= mid)
			{
				cuttingCount++;
				cuttingPos = arr[i];
			}
		}
		if (cuttingCount > targetCuttingCount)
		{
			left = mid + 1;
			answer = max(answer, mid);
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

	cin >> N >> M >> L;
	arr = new int[M + 2];
	arr[0] = 0;
	for (int i = 1; i < M + 1; i++)
	{
		cin >> arr[i];
	}
	arr[M + 1] = L;
	for (int i = 0; i < N; i++)
	{
		cin >> targetCuttingCount;
		binarySearch(1, L);
		cout << answer << "\n";
		answer = 0;
	}
	return 0;
}