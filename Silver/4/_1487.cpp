#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* buy = new int[N];
	int* deliver = new int[N];
	int minBuy = 1000000;
	int maxBuy = 0;
	long long maxCost = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> buy[i] >> deliver[i];
		if (buy[i] < minBuy)
		{
			minBuy = buy[i];
		}
		if (buy[i] > maxBuy)
		{
			maxBuy = buy[i];
		}
	}
	int answer = 0;
	for (int i = minBuy; i <= maxBuy; i++)
	{
		long long currentCost = 0;
		for (int j = 0; j < N; j++)
		{
			if (i <= buy[j] && (i - deliver[j] > 0))
			{
				currentCost += i - deliver[j];
			}
		}
		if (currentCost > maxCost)
		{
			maxCost = currentCost;
			answer = i;
		}
	}
	cout << answer << "\n";
	return 0;
}