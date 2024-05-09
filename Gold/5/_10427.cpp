#include <iostream>
#include <algorithm>
#define MAX 987654321
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T, N;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		int* arr = new int[N];
		long long* sum = new long long[N + 1];
		long long answer = 0;
		sum[0] = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + N);
		for (int i = 1; i < N + 1; i++)
		{
			sum[i] = sum[i - 1] + arr[i - 1];
		}
		for (int M = 1; M <= N; M++)
		{
			long long currentDayMin = MAX;
			for (int i = M; i <= N; i++)
			{
				long long currentDebt = arr[i - 1] * M;
				long long originalDebt = sum[i] - sum[i - M];
				long long additionalDebt = currentDebt - originalDebt;
				if (additionalDebt < currentDayMin)
				{
					currentDayMin = additionalDebt;
				}
			}
			answer += currentDayMin;
		}
		cout << answer << "\n";
	}
	return 0;
}