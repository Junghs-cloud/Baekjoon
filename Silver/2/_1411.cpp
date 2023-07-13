#include <iostream>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	string str;
	int matchCount = 0;
	cin >> N;
	string* strings = new string[N];
	map<char, char>::iterator it1;
	map<char, char>::iterator it2;
	for (int i = 0; i < N; i++)
	{
		cin >> strings[i];
		for (int j = 0; j < i; j++)
		{
			if (strings[i] == strings[j])
			{
				continue;
			}
			map<char, char> m1;
			map<char, char> m2;
			bool isMatched = true;
			for (int k = 0; k < strings[i].size(); k++)
			{
				it1 = m1.find(strings[i].at(k));
				it2 = m2.find(strings[j].at(k));
				if (it1 == m1.end() && it2 == m2.end())
				{
					m1.insert({strings[i].at(k), strings[j].at(k)});
					m2.insert({ strings[j].at(k), strings[i].at(k) });
				}
				else if (it1 != m1.end() && it2 != m2.end())
				{
					if (it1->second == it2->first && it2->second == it1->first)
					{
						continue;
					}
					else
					{
						isMatched = false;
						break;
					}
				}
				else
				{
					isMatched = false;
					break;
				}
			}
			if (isMatched == true)
			{
				matchCount++;
			}
		}
	}
	cout << matchCount << "\n";
	return 0;
}