#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int convert(int a, int b)
{
	int answer = 0;
	int c = a * b;
	string s = to_string(c);
	for (int i = 0; i < s.length(); i++)
	{
		answer += s.at(i) - 48;
	}
	return answer;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, num;
	cin >> N;
	map<int, int> m;
	map<int, int>::iterator it;
	map<int, int>::iterator iter;
	int answer = 0;
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
		for (iter = it; iter != m.end(); iter++)
		{
			if (it == iter && iter->second != 1)
			{
				answer = max(answer, convert(it->first, it->first));
			}
			else if (it != iter)
			{
				answer = max(answer, convert(it->first, iter->first));
			}
		}
	}
	cout << answer << "\n";
	return 0;
}