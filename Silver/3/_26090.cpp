#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	int answer = 0;
	long long* sum = new long long[N+1];
	bool* isPrime = new bool[1000001];
	for (int i = 0; i < 1000001; i++)
	{
		isPrime[i] = true;
	}
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i < 1000001; i++)
	{
		for (int j = 2 * i; j < 1000001; j += i)
		{
			isPrime[j] = false;
		}
	}
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sum[0] = 0;
	for (int i = 1; i < N+1; i++)
	{
		sum[i] = sum[i - 1] + arr[i-1];
	}
	for (int length = 2; length < N+1; length++)
	{
		if (isPrime[length] == true)
		{
			for (int j = 0; j < N; j++)
			{
				if (j + length <= N)
				{
					int hap = sum[j + length] - sum[j];
					if (isPrime[hap] == true)
					{
						answer++;
					}
				}
			}
		}
	}
	cout << answer << "\n";
	return 0;
}