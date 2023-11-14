#include <iostream>
#include <set>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	char game;
	string name;
	cin >> N >> game;
	set<string> s;
	set<string>::iterator it;
	set<string> currentGame;
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> name;
		it = s.find(name);
		if (it == s.end())
		{
			currentGame.insert(name);
			if (game == 'Y' && currentGame.size() == 1)
			{
				s.insert(name);
				currentGame.clear();
				answer++;
			}
			else if (game == 'F' && currentGame.size()==2)
			{
				for (set<string>::iterator iter = currentGame.begin(); iter != currentGame.end(); iter++)
				{
					s.insert(*iter);
				}
				currentGame.clear();
				answer++;
			}
			else if (game == 'O' && currentGame.size() == 3)
			{
				for (set<string>::iterator iter = currentGame.begin(); iter != currentGame.end(); iter++)
				{
					s.insert(*iter);
				}
				currentGame.clear();
				answer++;
			}
		}
		else
		{
			continue;
		}
	}
	cout << answer << "\n";
	return 0;
}