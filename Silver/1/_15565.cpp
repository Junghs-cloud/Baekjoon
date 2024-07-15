#include <iostream>
#include <algorithm>
#define MAX 987654321
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N>>K;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int start = 0;
	int end = 0;
	int lionCount = 0;
	int minLength = MAX;
	while (start < N)
	{
		while (end < N && lionCount !=K)
		{
			if (arr[end] == 1)
			{
				lionCount++;
			}
			end++;
		}
		if (lionCount == K)
		{
			minLength = min(minLength, end - start);
		}
		if (arr[start] == 1)
		{
			lionCount--;
		}
		start++;
	}
	if (minLength == MAX)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << minLength << "\n";
	}
	return 0;
}