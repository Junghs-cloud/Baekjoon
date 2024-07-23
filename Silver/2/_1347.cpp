#include <iostream>
using namespace std;
char** maze = new char* [120];
int currentPosX = 60;
int currentPosY = 60;

void moveTo(int directionPos)
{
	if (directionPos == 0)
	{
		currentPosX++;
	}
	else if (directionPos == 1)
	{
		currentPosY++;
	}
	else if (directionPos == 2)
	{
		currentPosX--;
	}
	else
	{
		currentPosY--;
	}
	maze[currentPosX][currentPosY] = '.';
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	string str;
	string directions[] = { "south", "east", "north", "west" };
	int row1 = 60;
	int row2 = 60;
	int col1 = 60;
	int col2 = 60;
	int directionPos = 0;
	cin >> N;

	for (int i = 0; i < 120; i++)
	{
		maze[i] = new char[120];
		for (int j = 0; j < 120; j++)
		{
			maze[i][j] = '!';
		}
	}
	if (N != 0)
	{
		cin >> str;
		maze[currentPosX][currentPosY] = '.';
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == 'L')
			{
				directionPos++;
				if (directionPos == 4)
				{
					directionPos = 0;
				}
			}
			else if (str[i] == 'R')
			{
				directionPos--;
				if (directionPos == -1)
				{
					directionPos = 3;
				}
			}
			else
			{
				moveTo(directionPos);
			}
		}
		for (int i = 0; i < 120; i++)
		{
			for (int j = 0; j < 120; j++)
			{
				if (maze[i][j] == '.')
				{
					row1 = min(row1, i);
					row2 = max(row2, i);
					col1 = min(col1, j);
					col2 = max(col2, j);
				}
			}
		}
		for (int i = row1; i <= row2; i++)
		{
			for (int j = col1; j <= col2; j++)
			{
				if (maze[i][j] == '!')
				{
					cout << "#";
				}
				else
				{
					cout << maze[i][j];
				}
			}
			cout << "\n";
		}
	}
	else
	{
		cout << "." << "\n";
	}
	return 0;
}