#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
using namespace std;
int** original;
int** arr;
int N, M, D;
int* positions = new int[3];
bool* isAllocated;
int maxEliminateEnemies;
int currentSimulationEnemies;

void attack()
{
	set<pair<int, int>> attackedEnemies;
	for (int archer = 0; archer < 3; archer++)
	{
		pair<int, int> archerPos = pair(N, positions[archer]);
		pair<int, int> attackedPos = pair(N+1, M+1);
		int minDistance = 11;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int currentDistance = abs(archerPos.first - i) + abs(archerPos.second - j);
				if (arr[i][j] == 1 && currentDistance < minDistance && currentDistance <= D)
				{
					minDistance = currentDistance;
					attackedPos = pair(i, j);
				}
				else if (arr[i][j] == 1 && currentDistance == minDistance&& currentDistance <= D)
				{
					if (j < attackedPos.second)
					{
						attackedPos = pair(i, j);
					}
				}
			}
		}
		if (attackedPos != pair(N + 1, M + 1))
		{
			attackedEnemies.insert(attackedPos);
		}
	}
	for (set<pair<int, int>>::iterator it = attackedEnemies.begin(); it != attackedEnemies.end(); it++)
	{
		pair<int, int> attackedPos = *it;
		arr[attackedPos.first][attackedPos.second] = 0;
		currentSimulationEnemies++;
	}
}

void move()
{
	for (int i = N - 2; i >= 0; i--)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i + 1][j] = arr[i][j];
			arr[i][j] = 0;
		}
	}
}

bool checkFinished()
{
	bool isFinished = true;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 1)
			{
				isFinished = false;
			}
		}
	}
	return isFinished;
}

void simulate()
{
	while (true)
	{
		attack();
		move();
		if (checkFinished() == true)
		{
			break;
		}
	}
}

void copy()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = original[i][j];
		}
	}
}

void backTracking(int depth, int index)
{
	if (depth == 3)
	{
		currentSimulationEnemies = 0;
		copy();
		simulate();
		maxEliminateEnemies = max(maxEliminateEnemies, currentSimulationEnemies);
	}
	else
	{
		for (int i = index; i < M; i++)
		{
			if (isAllocated[i] == false)
			{
				positions[depth] = i;
				isAllocated[i] = true;
				backTracking(depth + 1, i+1);
				isAllocated[i] = false;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> D;
	original = new int* [N];
	arr = new int*[N];
	isAllocated = new bool[M];
	for (int i = 0; i < M; i++)
	{
		isAllocated[i] = false;
	}
	for (int i = 0; i < N; i++)
	{
		original[i] = new int[M];
		arr[i] = new int[M];
		for (int j = 0; j < M; j++)
		{
			cin >> original[i][j];
		}
	}
	backTracking(0, 0);
	cout << maxEliminateEnemies << "\n";
	return 0;
}