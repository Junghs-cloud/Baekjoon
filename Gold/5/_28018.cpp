#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, S, E, Q, num;
	cin >> N;
	int* answer = new int[1000001];
	priority_queue<int, vector<int>, greater<>> startPQ;
	priority_queue<int, vector<int>, greater<>> endPQ;
	for (int i = 0; i < N; i++)
	{
		cin >> S >> E;
		startPQ.push(S);
		endPQ.push(E);
	}
	answer[0] = 0;
	while (startPQ.top() == 0)
	{
		answer[0]++;
	}
	for (int i = 1; i < 1000001; i++)
	{
		answer[i] = answer[i - 1];
		while (!startPQ.empty() && startPQ.top() == i)
		{
			answer[i]++;
			startPQ.pop();
		}
		while (!endPQ.empty() && i == endPQ.top() + 1)
		{
			answer[i]--;
			endPQ.pop();
		}
	}
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		cin >> num;
		cout << answer[num] << "\n";
	}
	return 0;
}