#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int>& p1, pair<string, int>& p2)
{
	if (p1.second > p2.second)
	{
		return true;
	}
	else if (p1.second == p2.second)
	{
		if (p1.first.length() > p2.first.length())
		{
			return true;
		}
		else if (p1.first.length() == p2.first.length())
		{
			return p1.first < p2.first;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	int N, M;
	cin >> N >> M;
	vector<pair<string, int>> v;
	map<string, int> m;
	map<string, int>::iterator it;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		if (str.length() < M)
		{
			continue;
		}
		else
		{
			it = m.find(str);
			if (it == m.end())
			{
				m.insert({ str,1 });
			}
			else
			{
				it->second++;
			}
		}
	}
	for (it = m.begin(); it != m.end(); it++)
	{
		v.push_back(make_pair(it->first, it->second));
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i).first << "\n";
	}
	return 0;
}