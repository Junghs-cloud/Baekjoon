#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int F, R, N, a, b;
		cin >> F >> R >> N;
		vector<int>* offices = new vector<int>[F];
		int answer = 2 * F + R + 1;
		for (int i = 0; i < N; i++)
		{
			cin >> a >> b;
			offices[a - 1].push_back(b);
		}
		for (int i = 0; i < F; i++)
		{
			if (offices[i].size() == 0)
			{
				continue;
			}
			sort(offices[i].begin(), offices[i].end());
			int minDistance = min(2 * (R - offices[i].front() + 1), 2 * offices[i].back());
			for (int j = 0; j < offices[i].size() - 1; j++)
			{
				minDistance = min(minDistance, 2 * offices[i].at(j) + 2 * (R - offices[i].at(j + 1) + 1));
			}
			answer += minDistance;
		}
		cout << answer << "\n";
	}
	return 0;
}