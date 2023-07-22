#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int S, K;
	cin >> S >> K;
	long long** arr = new long long*[K];
	for (int i = 0; i < K; i++)
	{
		arr[i] =new long long[S+1];
	}
	for (int i = 0; i < K;i++)
	{
		for (int j = 0; j < S + 1; j++)
		{
			arr[i][j] = 0;
		}
	}
	for (int i = 0;i < S + 1; i++)
	{
		arr[0][i] = i;
	}
	for (int i = 1; i < K; i++)
	{
		for (int j = i; j < S + 1; j++)
		{
			for (int k = 0; k < j; k++)
			{
				arr[i][j] = max(arr[i - 1][k] * (j - k), arr[i][j]);
			}
		}
	}
	cout << arr[K - 1][S]<<"\n";
	return 0;
}