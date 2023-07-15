#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	string temp;
	cin >> str;
	map<string, int> m;
	for (int i = 0; i < (signed) str.length(); i++)
	{
		for (int j = 1; j <= (signed) str.length() - i; j++)
		{
			temp = str.substr(i, j);
			if (m.find(temp) == m.end())
			{
				m.insert({ temp, 1 });
			}
		}
	}
	cout << m.size() << "\n";
	return 0;
}