#include <iostream>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int j = 0; j < T; j++)
	{
		int answer = 1;
		int N;
		cin >> N;
		string genre, name;
		map<string, int> m;
		map<string, int>::iterator it;
		for (int i = 0; i < N; i++)
		{
			cin >> name >> genre;
			it = m.find(genre);
			if (it == m.end())
			{
				m.insert({ genre, 2 });
			}
			else
			{
				it->second++;
			}
		}
		for (it = m.begin(); it != m.end(); it++)
		{
			answer *= it->second;
		}
		answer--;
		cout << answer << "\n";
	}
	return 0;
}