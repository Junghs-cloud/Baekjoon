#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;
		int* arr = new int[N];
		long long answer = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + N);
		for (int i = 1; i < N; i++)
		{
			for (int j = 0; j < i; j++)
			{
				int diff = arr[i] - arr[j];
				if (binary_search(arr + i + 1, arr + N, arr[i] + diff))
				{
					answer++;
				}
			}
		}
		cout << answer << "\n";
	}
	return 0;
}