#include <iostream>
#include <map>
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
		long long answer = -1;
		map<long long, long long> m;
		map<long long, long long>::iterator it;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> num;
			it = m.find(num);
			if (it == m.end())
			{
				m.insert({ num, 1 });
			}
			else
			{
				it->second++;
				if (it->second >= N / 2 + 1)
				{
					answer = num;
				}
			}
		}
		if (answer == -1)
		{
			cout << "SYJKGW" << "\n";
		}
		else
		{
			cout << answer << "\n";
		}
	}

	return 0;
}