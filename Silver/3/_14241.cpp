#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, size;
	int answer = 0;
	cin >> N;
	priority_queue<int, vector<int>, less<int>> pq;
	for (int i = 0; i < N; i++)
	{
		cin >> size;
		pq.push(size);
	}
	while (pq.size() != 1)
	{
		int firstSlime = pq.top();
		pq.pop();
		int secondSlime = pq.top();
		pq.pop();
		pq.push(firstSlime + secondSlime);
		answer += firstSlime * secondSlime;
	}
	cout << answer << "\n";
	return 0;
}