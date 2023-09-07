#include <iostream>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	string str;
	cin >> N;
	map<string, int> m;
	map<string, int> ::iterator it;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		bool check = false;
		for (int j = 0; j < str.length(); j++)
		{
			char firstLetter = str.at(0);
			str = str.substr(1, str.length() - 1) + firstLetter;
			it = m.find(str);
			if (it != m.end())
			{
				check = true;
				break;
			}
		}
		if (check == false)
		{
			m.insert({ str, 1 });
		}
	}
	cout << m.size() << "\n";
	return 0;
}