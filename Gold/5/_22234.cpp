#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, T, W, M, id, leftTime, comeTime;
	int currentTime = 0;
	queue<pair<int, int>> q;
	priority_queue<pair<int, pair<int, int>>> comingCustomer;
	cin >> N >> T >> W;
	int* answers = new int[W];
	for (int i = 0; i < N; i++)
	{
		cin >> id >> leftTime;
		q.push(pair(id, leftTime));
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> id >> leftTime >> comeTime;
		comingCustomer.push(pair(-comeTime, pair(id, leftTime)));
	}
	while (!q.empty())
	{
		pair<int, int> current = q.front();
		q.pop();
		int nextTime = currentTime;
		if (current.second <= T)
		{
			nextTime = currentTime + current.second;
			while (!comingCustomer.empty() && -comingCustomer.top().first <= nextTime)
			{
				q.push(pair(comingCustomer.top().second));
				comingCustomer.pop();
			}
		}
		else
		{
			nextTime = currentTime + T;
			while (!comingCustomer.empty() && -comingCustomer.top().first <= nextTime)
			{
				q.push(pair(comingCustomer.top().second));
				comingCustomer.pop();
			}
			q.push(pair(current.first, current.second - T));
		}
		for (int i = currentTime; i < min(W, nextTime); i++)
		{
			answers[i] = current.first;
		}
		currentTime = nextTime;
	}
	for (int i = 0; i < W; i++)
	{
		cout << answers[i] << "\n";
	}
	return 0;
}