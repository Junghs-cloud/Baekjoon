#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	int start, end;
	cin >> N>>K;
	int* arr = new int[N];
	int* sum = new int[N];
	sum[0] = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i < N; i++)
	{
		int absNum = abs(arr[i] - arr[i-1]);
		sum[i] = sum[i - 1] + absNum;
	}
	for (int k = 0; k < K; k++)
	{
		cin >> start >> end;
		if (sum[end - 1] - sum[start - 1] < 0)
		{
			cout << 0 << "\n";
		}
		else
		{
			cout << sum[end - 1] - sum[start - 1] << "\n";
		}
	}
	return 0;
}