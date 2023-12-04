#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int num;
	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> N;
	for (int i = 0; i < N * N; i++)
	{
		cin >> num;
		pq.push(num);
		if (pq.size() > N)
		{
			pq.pop();
		}
	}
	cout << pq.top() << "\n";
	return 0;
}