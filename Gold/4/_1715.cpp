#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	long long input;
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	long long answer = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		pq.push(input);
	}
	while (pq.size() != 1)
	{
		long long a = pq.top();
		pq.pop();
		long long b = pq.top();
		pq.pop();
		answer += (a + b);
		pq.push(a + b);
	}
	cout << answer << "\n";
	return 0;
}