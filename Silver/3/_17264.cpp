#include <iostream>
#include <map>
using namespace std;

int main()
{
	int N, P;
	int winPoint, losePoint, iron;
	int currentPoint = 0;
	bool canEscape = false;
	string player;
	string WL;
	map<string, string> m;
	map<string, string>::iterator it;
	cin >> N >> P;
	cin >> winPoint >> losePoint >> iron;
	for (int i = 0; i < P; i++)
	{
		cin >> player >> WL;
		m.insert({player, WL});
	}
	for (int i = 0; i < N; i++)
	{
		cin >> player;
		it = m.find(player);
		if (it == m.end())
		{
			currentPoint -= losePoint;
		}
		else
		{
			if (it->second == "W")
			{
				currentPoint += winPoint;
			}
			else
			{
				currentPoint -= losePoint;
			}
		}
		if (currentPoint < 0)
		{
			currentPoint = 0;
		}
		if (currentPoint >= iron)
		{
			canEscape = true;
		}
	}
	if (canEscape == true)
	{
		cout << "I AM NOT IRONMAN!!" << "\n";
	}
	else
	{
		cout << "I AM IRONMAN!!"<< "\n";
	}
	return 0;
}