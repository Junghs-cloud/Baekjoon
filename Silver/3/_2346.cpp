#include <iostream>
#include <deque>
#include <utility>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, num;
	cin >> N;
	deque<pair<int, int>> dq;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		dq.push_back(pair(i+1, num));
	}
	while (true)
	{
		pair<int, int> current = dq.front();
		cout << current.first << " ";
		dq.pop_front();
		if (dq.empty())
		{
			break;
		}
		if (current.second >= 0)
		{
			for (int i = 0; i < current.second - 1; i++)
			{
				pair<int, int> temp = dq.front();
				dq.pop_front();
				dq.push_back(temp);
			}
		}
		else
		{
			for (int i = 0; i <  (-current.second); i++)
			{
				pair<int, int> temp = dq.back();
				dq.pop_back();
				dq.push_front(temp);
			}
		}
	}
	return 0;
}