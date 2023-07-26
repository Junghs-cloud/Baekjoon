#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N, K;
	cin >> N>> K;
	int* arr = new int[N];
	priority_queue<int> pq;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i < N; i++)
	{
		pq.push(arr[i] - arr[i - 1]);
	}
	long long cost = arr[N - 1] - arr[0];
	for (int i = 0; i < K-1; i++)
	{
		cost -= pq.top();
		pq.pop();
	}
	cout << cost << "\n";
	return 0;
}