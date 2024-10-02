#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	string name, X, Y;
	cin >> N;
	map<string, set<string>> m;
	map<string, int> indexes;
	map<string, set<string>>::iterator it;
	vector<string> family;
	pair<string, int>* inDegree = new pair<string, int>[N];
	vector<string>* childs = new vector<string>[N];
	queue<pair<string, int>> q;
	for (int i = 0; i < N; i++)
	{
		cin >> name;
		set<string> s;
		m.insert({ name, s });
		indexes.insert({ name, i });
		inDegree[i] = pair(name, 0);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> X >> Y;
		int xIndex = indexes[X];
		int yIndex = indexes[Y];
		childs[yIndex].push_back(X);
		inDegree[xIndex].second++;
	}
	for (int i = 0; i < N; i++)
	{
		if (inDegree[i].second == 0)
		{
			q.push(pair(inDegree[i].first, i));
			family.push_back(inDegree[i].first);
		}
	}
	while (!q.empty())
	{
		pair<string, int> current = q.front();
		int index = current.second;
		for (int i = 0; i < childs[index].size(); i++)
		{
			string  child = childs[index].at(i);
			int childIndex = indexes[child];
			inDegree[childIndex].second--;
			if (inDegree[childIndex].second == 0)
			{
				q.push(pair(child, childIndex));
				m[current.first].insert(child);
			}
		}
		q.pop();
	}
	sort(family.begin(), family.end());
	cout << family.size() << "\n";
	for (int i = 0; i < family.size(); i++)
	{
		if (i != family.size()-1)
		{
			cout << family.at(i) << " ";
		}
		else
		{
			cout << family.at(i)<<"\n";
		}
	}
	for (it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << " "<<it->second.size();
		for (set<string>::iterator iter = it->second.begin(); iter != it->second.end(); iter++)
		{
			cout << " " << *iter;
		}
		cout << "\n";
	}
	return 0;
}