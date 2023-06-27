#include <iostream>
#include <algorithm>
using namespace std;

struct stockInfo
{
	int day;
	int stockPrice;
};

bool compare(const stockInfo& s1, const stockInfo& s2)
{
	if (s1.stockPrice > s2.stockPrice)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T, N;
	stockInfo* stockArray;
	int* dayArray;
	long long sum = 0;
	int pivot = 0;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		stockArray = new stockInfo[N];
		dayArray = new int[N + 1];
		sum = 0;
		pivot = 1;
		dayArray[0] = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> stockArray[i].stockPrice;
			stockArray[i].day = i + 1;
			dayArray[i + 1] = stockArray[i].stockPrice;
		}
		sort(stockArray, stockArray + N, compare);
		for (int j = 0; j < N; j++)
		{
			int day = stockArray[j].day;
			int maxPrice = stockArray[j].stockPrice;
			if (day < pivot)
			{
				continue;
			}
			for (int k = pivot; k < day; k++)
			{
				sum += (long long) maxPrice - (long long) dayArray[k];
			}
			if (day == N)
			{
				break;
			}
			else
			{
				pivot = day + 1;
			}
		}
		cout << sum << "\n";
		delete[] stockArray;
		delete[] dayArray;
	}

	return 0;
}