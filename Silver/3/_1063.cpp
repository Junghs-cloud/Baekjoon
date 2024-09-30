#include <iostream>
#include <utility>
using namespace std;

pair<int, int> move(string dir, pair<int, int> pos)
{
	pair<int, int> tempPos = pos;
	if (dir == "R")
	{
		tempPos.first++;
	}
	else if (dir == "L")
	{
		tempPos.first--;
	}
	else if (dir == "B")
	{
		tempPos.second--;
	}
	else if (dir == "T")
	{
		tempPos.second++;
	}
	else if (dir == "RT")
	{
		tempPos.second++;
		tempPos.first++;
	}
	else if (dir == "LT")
	{
		tempPos.second++;
		tempPos.first--;
	}
	else if (dir == "RB")
	{
		tempPos.second--;
		tempPos.first++;
	}
	else
	{
		tempPos.second--;
		tempPos.first--;
	}
	return tempPos;
}

bool isInBoard(pair<int, int> pos)
{
	if (pos.first >= 0 && pos.first <= 7 && pos.second >= 0 && pos.second <= 7)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string convertToChessBoardPos(pair<int, int> pos)
{
	string chessBoardPos = "";
	chessBoardPos += pos.first + 65;
	chessBoardPos += pos.second + 49;
	return chessBoardPos;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string king, stone;
	string dir;
	pair<int, int> kingPos;
	pair<int, int> stonePos;
	int N;
	cin >> king >> stone >> N;
	kingPos.first = king.at(0) - 65;
	kingPos.second = king.at(1) - 49;
	stonePos.first = stone.at(0) - 65;
	stonePos.second = stone.at(1) - 49;
	for (int i = 0; i < N; i++)
	{
		cin >> dir;
		pair<int, int> kingTempPos = move(dir, kingPos);
		if (isInBoard(kingTempPos))
		{
			if (kingTempPos == stonePos)
			{
				pair<int, int> tempStonePos = move(dir, stonePos);
				if (isInBoard(tempStonePos))
				{
					kingPos = kingTempPos;
					stonePos = tempStonePos;
				}
			}
			else
			{
				kingPos = kingTempPos;
			}
		}
	}
	cout << convertToChessBoardPos(kingPos) << "\n";
	cout<< convertToChessBoardPos(stonePos) << "\n";
	return 0;
}