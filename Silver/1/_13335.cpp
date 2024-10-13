#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, W, L, A;
	int time = 0;
	int bridgeWeight = 0;
	cin >> N >> W >> L;
	queue<int> waitingTrucks;
	queue<pair<int, int>> inBridge;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		waitingTrucks.push(A);
	}
	while (!waitingTrucks.empty() || !inBridge.empty())
	{
		if (!inBridge.empty() && inBridge.front().second + W == time)
		{
			bridgeWeight -= inBridge.front().first;
			inBridge.pop();
		}
		if (!waitingTrucks.empty() && bridgeWeight + waitingTrucks.front() <= L)
		{
			bridgeWeight += waitingTrucks.front();
			inBridge.push(pair(waitingTrucks.front(), time));
			waitingTrucks.pop();
		}
		time++;
	}
	cout << time << "\n";
	return 0;
}