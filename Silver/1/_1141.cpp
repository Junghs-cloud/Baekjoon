#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(const string& s1,const  string& s2)
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
	vector<string>* dict = new vector<string>[N];
	int maxSize = 0;
	for (int i = 0; i < N;i++)
	{
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < N; i++)
	{
		string currentString = v.at(i);
		for (int j = i-1; j >=0; j--)
		{
			string compareString = v.at(j);
			if (currentString.find(compareString) == string::npos)
			{
				bool check = true;
				for (int k = 0; k < dict[i].size(); k++)
				{
					if (dict[i].at(k).find(compareString) == 0)
					{
						check = false;
					}
				}
				if (check == true)
				{
					dict[i].push_back(compareString);
				}
				
			}
			else
			{
				if (currentString.find(compareString) != 0)
				{
					bool check = true;
					for (int k = 0; k < dict[i].size(); k++)
					{
						if (dict[i].at(k).find(compareString) == 0)
						{
							check = false;
						}
					}
					if (check == true)
					{
						dict[i].push_back(compareString);
					}
				}
			}
		}
		dict[i].push_back(currentString);
		if ((signed) dict[i].size() > maxSize)
		{
			maxSize = (signed) dict[i].size();
		}
	}
	cout << maxSize << "\n";
	return 0;
}