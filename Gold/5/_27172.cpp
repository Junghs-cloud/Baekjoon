#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int cardNum;
	cin >> N;
	map<int, int> m;
	map<int, int>::iterator it;
	int* cardNums = new int[N];
	int* points = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> cardNum;
		m.insert({ cardNum, i });
		cardNums[i] = cardNum;
		points[i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= sqrt(cardNums[i]); j++)
		{
			if (cardNums[i] % j == 0)
			{
				it = m.find(j);
				if (it != m.end())
				{
					points[i]--;
					points[it->second]++;
				}
				int next = cardNums[i] / j;
				if (j != next)
				{
					it = m.find(next);
					if (it != m.end())
					{
						points[i]--;
						points[it->second]++;
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << points[i] << " ";
	}
	return 0;
}