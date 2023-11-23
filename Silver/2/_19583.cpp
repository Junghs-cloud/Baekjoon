#include <iostream>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string start;
	string end1, end2;
	string time;
	string nickname;
	int answer = 0;
	cin >> start>>end1>>end2;
	map<string, bool> m;
	map<string, bool>::iterator it;
	while (true)
	{
		cin >> time >> nickname;
		if (cin.eof() == 1)
		{
			break;
		}
		if (time <= start)
		{
			m.insert({ nickname, false });
		}
		if (end1 <= time && time <= end2)
		{
			it = m.find(nickname);
			if (it != m.end())
			{
				it->second = true;
			}
		}
	}
	for (it = m.begin(); it != m.end(); it++)
	{
		if (it->second == true)
		{
			answer++;
		}
	}
	cout << answer << "\n";
	return 0;
}