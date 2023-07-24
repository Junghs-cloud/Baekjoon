#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N;
	cin >> K;
	int* arr = new int[N];
	priority_queue<int> pq;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int i = 1; i < N; i++)
	{
		pq.push(arr[i] - arr[i - 1]);
	}
	long long length = arr[N - 1] - arr[0];
	for (int i = 0; i < K - 1; i++)
	{
		if (!pq.empty())
		{
			length -= pq.top();
			pq.pop();
		}
	}
	cout << length << "\n";
	return 0;
}