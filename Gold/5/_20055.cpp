#include <iostream>
#include <deque>
#include <utility>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	deque<pair<bool, int>> dq;
	int N, K;
	cin >> N >> K;
	int durability;
	int step = 0;
	for (int i = 0; i < 2 * N; i++)
	{
		cin >> durability;
		dq.push_back(make_pair(false, durability));
	}
	while (true)
	{
		pair<bool, int> back = dq.back();
		dq.pop_back();
		dq.push_front(back);
		if (dq[N - 1].first == true)
		{
			dq[N - 1].first = false;
		}
		step++;
		for (int j = N - 2; j >= 0; j --)
		{
			pair<bool, int>& current = dq[j];
			pair<bool, int>& next = dq[j + 1];
			if (current.first == true && next.first == false && next.second != 0)
			{
				current.first = false;
				next.first = true;
				next.second--;
				if (j + 1 == N - 1)
				{
					next.first = false;
				}
			}
		}
		if (dq[0].second != 0)
		{
			dq[0].first = true;
			dq[0].second--;
		}
		int durability0 = 0;
		for (int i = 0; i < 2 * N; i++)
		{
			if (dq[i].second == 0)
			{
				durability0++;
			}
		}
		if (durability0 >= K)
		{
			break;
		}
	}
	cout << step << "\n";
	return 0;
}