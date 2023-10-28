#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string& s1, string& s2)
{
	if (s1.length() < s2.length())
	{
		return true;
	}
	else if (s1.length() == s2.length())
	{
		return s1 < s2;
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
	int classNum;
	string name;
	cin >> N>>M;
	vector<string>* v = new vector<string>[N];
	while (true)
	{
		cin >> classNum >> name;
		if (classNum == 0 && name == "0")
		{
			break;
		}
		else
		{
			if (v[classNum - 1].size() != M)
			{
				v[classNum - 1].push_back(name);
			}
		}
	}
	for (int i = 0; i < N; i += 2)
	{
		sort(v[i].begin(), v[i].end(), cmp);
		for (int j = 0; j < v[i].size(); j++)
		{
			cout << i+1 <<" " << v[i].at(j) << "\n";
		}
	}
	for (int i = 1; i < N; i += 2)
	{
		sort(v[i].begin(), v[i].end(), cmp);
		for (int j = 0; j < v[i].size(); j++)
		{
			cout << i + 1 << " " << v[i].at(j) << "\n";
		}
	}
	return 0;
}