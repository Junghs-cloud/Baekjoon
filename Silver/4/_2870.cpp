#include <iostream>
#include <algorithm>
#include <vector>
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

	int N;
	string str;
	cin >> N;
	vector<string> v;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		string token = "";
		for (int j = 0; j < str.length(); j++)
		{
			if (str.at(j) >= 48 && str.at(j) <= 57)
			{
				if (token == "0" && str.at(j) == '0')
				{
					continue;
				}
				token += str.at(j);
			}
			else
			{
				if (token != "")
				{
					if (token.length() != 1 && token.at(0) == '0')
					{
						token = token.substr(1);
					}
					v.push_back(token);
					token = "";
				}
			}
		}
		if (token != "")
		{
			if (token.length() != 1 && token.at(0) == '0')
			{
				token = token.substr(1);
			}
			v.push_back(token);
			token = "";
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << "\n";
	}
	return 0;
}