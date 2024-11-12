#include <iostream>
#include <deque>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	deque<int> dq;
	for (int i = 1; i <= N; i++)
	{
		dq.push_back(i);
	}
	for (long long level = 1; level < N; level++)
	{
		long long counts = level * level * level;
		int nextPos = counts % dq.size() - 1;
		if (nextPos < 0)
		{
			nextPos = dq.size() - 1;
		}
		if (nextPos >= dq.size())
		{
			nextPos -= dq.size();
		}
		for (int i = 0; i < nextPos; i++)
		{
			int temp = dq.front();
			dq.pop_front();
			dq.push_back(temp);
		}
		dq.pop_front();
	}
	cout << dq.front() << "\n";
	return 0;
}