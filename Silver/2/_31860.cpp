#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, K, D;
	int satisfaction = 0;
	priority_queue<int, vector<int>, less<int>> pq;
	vector<int> answer;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> D;
		pq.push(D);
	}
	while (!pq.empty())
	{
		int top = pq.top();
		satisfaction = satisfaction/2 + top;
		answer.push_back(satisfaction);
		pq.pop();
		int next = top - M;
		if (next > K)
		{
			pq.push(next);
		}
	}
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer.at(i) << "\n";
	}
	return 0;
}