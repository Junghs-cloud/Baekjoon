#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int quality;
	long long currentQuality = 0;
	cin >> N >> M;
	priority_queue<int, vector<int>, less<int>> q;
	pair<int, int>* conditions = new pair<int, int>[M];
	for (int i = 0; i < N; i++)
	{
		cin >> quality;
		q.push(quality);
	}
	for (int i = 0; i < M; i++)
	{
		cin >> conditions[i].first >> conditions[i].second;
	}
	for (int i = 0; i < M; i++)
	{
		while (!q.empty() && currentQuality < conditions[i].second)
		{
			int currentBest = q.top();
			q.pop();
			currentQuality += currentBest + conditions[i].first;
		}
	}
	while (!q.empty())
	{
		currentQuality += q.top() + conditions[M - 1].first;
		q.pop();
	}
	if (currentQuality >= conditions[M - 1].second)
	{
		cout << currentQuality << "\n";
	}
	else
	{
		cout << -1 << "\n";
	}
	return 0;
}