#include <iostream>
#include <queue>
using namespace std;

int main()
{
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	long long N, M;
	long long card;
	long long smallestSum = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> card;
		pq.push(card);
	}
	for (int i = 0; i < M; i++)
	{
		long long first = pq.top();
		pq.pop();
		long long second = pq.top();
		pq.pop();
		long long sum = first + second;
		pq.push(sum);
		pq.push(sum);
	}
	while (!pq.empty())
	{
		smallestSum += pq.top();
		pq.pop();
	}
	cout << smallestSum << "\n";
	return 0;
}