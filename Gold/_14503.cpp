#include <iostream>
using namespace std;

struct robot
{
	int posX;
	int posY;
	int dir;
};

int** room;
int N, M;
int cleanNum = 0;
robot r;

bool isInInside()
{
	if (r.posX > 0 && r.posX < N - 1 && r.posY < M - 1 && r.posY > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool canClean4dir()
{
	if (room[r.posX + 1][r.posY] == 0 || room[r.posX - 1][r.posY] == 0 || room[r.posX][r.posY + 1] == 0 || room[r.posX][r.posY - 1] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void rotateAndMoveForward()
{
	r.dir--;
	if (r.dir == -1)
	{
		r.dir = 3;
	}
	if (r.dir == 0 && room[r.posX - 1][r.posY] == 0)
	{
		r.posX--;
	}
	if (r.dir == 1 && room[r.posX][r.posY + 1] == 0)
	{
		r.posY++;
	}
	if (r.dir == 2 && room[r.posX + 1][r.posY] == 0)
	{
		r.posX++;
	}
	if (r.dir == 3 && room[r.posX][r.posY - 1] == 0)
	{
		r.posY--;
	}
}

void clean()
{
	while (true)
	{
		if (room[r.posX][r.posY] == 0)
		{
			room[r.posX][r.posY] = 2;
			cleanNum++;
		}
		if (isInInside())
		{
			if (canClean4dir())
			{
				rotateAndMoveForward();
			}
			else
			{
				if (r.dir == 0 && room[r.posX+1][r.posY] != 1)
				{
					r.posX++;
				}
				else if (r.dir == 1 && room[r.posX][r.posY - 1] != 1)
				{
					r.posY--;
				}
				else if (r.dir == 2 && room[r.posX - 1][r.posY] != 1)
				{
					r.posX--;
				}
				else if (r.dir == 3 && room[r.posX][r.posY + 1] != 1)
				{
					r.posY++;
				}
				else
				{
					break;
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	room = new int*[N];
	cin >> r.posX >> r.posY >> r.dir;
	for (int i = 0; i < N; i++)
	{
		room[i] = new int[M];
		for (int j = 0; j < M; j++)
		{
			cin >> room[i][j];
		}
	}
	clean();
	cout << cleanNum << "\n";
	return 0;
}