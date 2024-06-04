#include <iostream>
#include <utility>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int x, y;
	long long answer = 0;
	cin >> N;
	cin >> x >> y;
	pair<int, int> prev = pair(x, y);
	for (int i = 1; i < N; i++)
	{
		cin >> x >> y;
		if (x > prev.second)
		{
			answer += prev.second - prev.first;
			prev = pair(x, y);
		}
		else
		{
			if (y >= prev.second)
			{
				prev.second = y;
			}
		}
	}
	answer += prev.second - prev.first;
	cout << answer << "\n";
	return 0;
}