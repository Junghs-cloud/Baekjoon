#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T, N;
	long long num;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		long long answer = 0;
		cin >> N;
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		for (int i = 0; i < N; i++)
		{
			cin >> num;
			pq.push(num);
		}
		while (pq.size() > 1)
		{
			long long file1 = pq.top();
			pq.pop();
			long long file2 = pq.top();
			pq.pop();
			answer += file1 + file2;
			pq.push(file1 + file2);
		}
		cout << answer << "\n";
	}
	return 0;
}