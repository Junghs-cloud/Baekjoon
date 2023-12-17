#include <iostream>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	map<long long, int> m;
	map<long long, int>::iterator it;
	long long num;
	long long max = 0;
	long long answer = 0;
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
		}
	}
	for (it = m.begin(); it != m.end(); it++)
	{
		if (it->second > max)
		{
			max = it->second;
			answer = it->first;
		}
	}
	cout << answer << "\n";
	return 0;
}