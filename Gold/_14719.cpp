#include <iostream>
using namespace std;
bool** world;
int* lastBlockPos;
int H, W;

bool isCurrentBlockOneAndNextBlockZero(int i, int j)
{
	if (j < W - 1 && world[i][j] == true && world[i][j + 1] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isNextBlockOne(int i, int j)
{
	if (j < W - 1 && world[i][j + 1] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int blockHeight;
	int waterCount = 0;
	bool isConcave = false;
	cin >> H >> W;
	world = new bool*[H];
	lastBlockPos = new int[H];
	for (int i = 0; i < H; i++)
	{
		world[i] = new bool[W];
	}
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			world[i][j] = false;
		}
		lastBlockPos[i] = 0;
	}
	for (int i = 0; i < W; i++)
	{
		cin >> blockHeight;
		if (blockHeight <= H)
		{
			for (int j = 0; j < blockHeight; j++)
			{
				world[j][i] = true;
				lastBlockPos[j] = i;
			}
		}
	}
	for (int i = 0; i < H; i++)
	{
		isConcave = false;
		for (int j = 0; j < W; j++)
		{
			if (lastBlockPos[i] == j)
			{
				break;
			}
			if (isConcave == false)
			{
				if (isCurrentBlockOneAndNextBlockZero(i, j))
				{
					isConcave = true;
				}

			}
			else
			{
				if (world[i][j] == true)
				{
					if (isNextBlockOne(i, j))
					{
						isConcave = false;
					}
				}
				else
				{
					waterCount++;
				}
			}
		}
	}
	cout << waterCount << "\n";
	return 0;
}