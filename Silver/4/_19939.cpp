#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	if (N < K)
	{
		cout << -1 << "\n";
	}
	else
	{
		int sum = 0;
		for (int i = 1; i <= K; i++)
		{
			sum += i;
		}
		if (N < sum)
		{
			cout << -1 << "\n";
		}
		else
		{
			while (sum < N)
			{
				sum += K;
			}
			if (sum == N)
			{
				cout << K - 1 << "\n";
			}
			else
			{
				cout << K << "\n";
			}
		}
	}
	return 0;
}