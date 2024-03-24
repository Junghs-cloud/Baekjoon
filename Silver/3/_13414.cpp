#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int>& p1, pair<string, int>& p2)
{
	if (p1.second < p2.second)
	{
		return true;
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

	int N, M;
	string str;
	cin >> N >> M;
	map<string, int> m;
	map<string, int>::iterator it;
	vector<pair<string, int>> v;
	for (int i = 0; i < M; i++)
	{
		cin >> str;
		it = m.find(str);
		if (it == m.end())
		{
			m.insert({ str, i });
		}
		else
		{
			it->second=i;
		}
	}
	for (it = m.begin(); it != m.end(); it++)
	{
		v.push_back(make_pair(it->first, it->second));
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < min(N, (int)v.size()); i++)
	{
		cout << v.at(i).first << "\n";
	}
	return 0;
}