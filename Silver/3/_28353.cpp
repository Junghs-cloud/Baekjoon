#include <iostream>
#include <algorithm>
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
	sort(arr, arr + N);
	int start = 0;
	int end = N - 1;
	int happyCount = 0;
	while (true)
	{
		if (end <= start)
		{
			break;
		}
		if (arr[start] + arr[end] <= K)
		{
			happyCount++;
			start++;
			end--;
		}
		else
		{
			end--;
		}
	}
	cout << happyCount << "\n";
	return 0;
}