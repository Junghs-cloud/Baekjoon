#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int p, m;
	string playerName;
	int playerLevel;
	cin >> p>> m;
	vector<vector<pair<string, int>>> rooms;
	for (int i = 0; i < p; i++)
	{
		cin >> playerLevel >> playerName;
		if (i == 0)
		{
			vector<pair<string, int>> v;
			v.push_back(make_pair(playerName, playerLevel));
			rooms.push_back(v);
		}
		else
		{
			bool findRoom = false;
			for (int i = 0; i < rooms.size(); i++)
			{
				vector<pair<string, int>>& currentRoom = rooms.at(i);
				int roomLevel = currentRoom.at(0).second;
				if ((playerLevel <= roomLevel + 10 && playerLevel >= roomLevel - 10) && currentRoom.size() != m)
				{
					currentRoom.push_back(make_pair(playerName, playerLevel));
					findRoom = true;
					break;
				}
			}
			if (findRoom == false)
			{
				vector<pair<string, int>> v;
				v.push_back(make_pair(playerName, playerLevel));
				rooms.push_back(v);
			}
		}
	}
	for (int i = 0; i < rooms.size(); i++)
	{
		sort(rooms.at(i).begin(), rooms.at(i).end());
		if (rooms.at(i).size() == m)
		{
			cout << "Started!"<<"\n";
		}
		else
		{
			cout << "Waiting!" << "\n";
		}
		for (int j = 0; j < rooms.at(i).size(); j++)
		{
			cout << rooms.at(i).at(j).second << " " << rooms.at(i).at(j).first << "\n";
		}
	}
	return 0;
}