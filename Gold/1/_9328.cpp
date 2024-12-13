#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <set>
using namespace std;
int N, M;
string keyStr;
char** map;
bool** isVisited;
vector<pair<int, int>>* doorPos;
vector<pair<int, int>>* visitedDoorButCanNotOpen;
set<char> keys;

queue<pair<int, int>> bfsQueue;
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

int answer = 0;

void openDoor(char c)
{
	int index = c - 97;
	for (int j = 0; j < doorPos[index].size(); j++)
	{
		int doorPosX = doorPos[index].at(j).first;
		int doorPosY = doorPos[index].at(j).second;
		map[doorPosX][doorPosY] = '.';
	}
	for (int j = 0; j < visitedDoorButCanNotOpen[index].size(); j++) // 방문했지만 열지 못하는 문에 다시 방문.
	{
		int doorPosX = visitedDoorButCanNotOpen[index].at(j).first;
		int doorPosY = visitedDoorButCanNotOpen[index].at(j).second;
		bfsQueue.push(pair(doorPosX, doorPosY));
	}
	visitedDoorButCanNotOpen[index].clear();
}

void pushToQueue(int xPos, int yPos)
{
	isVisited[xPos][yPos] = true;
	if (map[xPos][yPos] == '$')
	{
		answer++;
	}
	bfsQueue.push(pair(xPos, yPos));
}

void bfs()
{
	while (!bfsQueue.empty())
	{
		pair<int, int> current = bfsQueue.front();
		for (int i = 0; i < 4; i++)
		{
			int nextX = current.first + dx[i];
			int nextY = current.second + dy[i];
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M && isVisited[nextX][nextY] == false && map[nextX][nextY] == '$')
			{
				answer++;
				isVisited[nextX][nextY] = true;
				bfsQueue.push(pair(nextX, nextY));
			}
			else if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M && isVisited[nextX][nextY] == false && map[nextX][nextY] == '.')
			{
				isVisited[nextX][nextY] = true;
				bfsQueue.push(pair(nextX, nextY));
			}
			else if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M && isVisited[nextX][nextY] == false && map[nextX][nextY] >= 97) //열쇠가 있는 곳 방문
			{
				bfsQueue.push(pair(nextX, nextY));
				isVisited[nextX][nextY] = true;
				if (keys.find(map[nextX][nextY]) == keys.end()) // 새 열쇠
				{
					keys.insert(map[nextX][nextY]);
					int index = map[nextX][nextY] - 97;
					for (int j = 0; j < visitedDoorButCanNotOpen[index].size(); j++) // 방문했지만 열지 못하는 문에 다시 방문.
					{
						int doorPosX = visitedDoorButCanNotOpen[index].at(j).first;
						int doorPosY = visitedDoorButCanNotOpen[index].at(j).second;
						bfsQueue.push(pair(doorPosX, doorPosY));
					}
					visitedDoorButCanNotOpen[index].clear();
					for (int j = 0; j < doorPos[index].size(); j++)
					{
						int doorPosX = doorPos[index].at(j).first;
						int doorPosY = doorPos[index].at(j).second;
						map[doorPosX][doorPosY] = '.';
					}
				}
			}
			else if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M && isVisited[nextX][nextY] == false && map[nextX][nextY] >= 65 && map[nextX][nextY] < 97) //아직 열지 못하는 문
			{
				isVisited[nextX][nextY] = true;
				int index = map[nextX][nextY] + 32 - 97;
				visitedDoorButCanNotOpen[index].push_back(pair(nextX, nextY));
			}
		}
		bfsQueue.pop();
	}
}

void findStartPointSero(int yPos)
{
	for (int i = 0; i < N; i++)
	{
		if (isVisited[i][yPos] == false)
		{
			if (map[i][yPos] == '.' || map[i][yPos] == '$')
			{
				pushToQueue(i, yPos);
			}
			else if (map[i][yPos] >= 97)
			{
				openDoor(map[i][yPos]);
				pushToQueue(i, yPos);
			}
			else if (map[i][yPos] >= 65 && map[i][yPos] < 97)
			{
				isVisited[i][yPos] = true;
				int index = map[i][yPos] + 32 - 97;
				visitedDoorButCanNotOpen[index].push_back(pair(i, yPos));
			}
		}
	}
}

void findStartPointGaro(int xPos)
{
	for (int j = 0; j < M; j++)
	{
		if (isVisited[xPos][j] == false)
		{
			if (map[xPos][j] == '.' || map[xPos][j] == '$')
			{
				pushToQueue(xPos, j);
			}
			else if (map[xPos][j] >= 97)
			{
				openDoor(map[xPos][j]);
				pushToQueue(xPos, j);
			}
			else if (map[xPos][j] >= 65 && map[xPos][j] < 97)
			{
				isVisited[xPos][j] = true;
				int index = map[xPos][j] + 32 - 97;
				visitedDoorButCanNotOpen[index].push_back(pair(xPos, j));
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		keys.clear();
		answer = 0;
		cin >> N >> M;
		map = new char* [N];
		isVisited = new bool* [N];
		doorPos = new vector<pair<int, int>>[26];
		visitedDoorButCanNotOpen = new vector<pair<int, int>>[26];
		for (int i = 0; i < N; i++)
		{
			map[i] = new char[M];
			isVisited[i] = new bool[M];
			for (int j = 0; j < M; j++)
			{
				isVisited[i][j] = false;
				cin >> map[i][j];
				if (map[i][j] >= 65 && map[i][j] < 97)
				{
					int index = map[i][j] - 65;
					doorPos[index].push_back(pair(i, j));
				}
			}
		}
		cin >> keyStr;
		if (keyStr == "0")
		{
			keyStr = "";
		}
		for (int i = 0; i < keyStr.size(); i++)
		{
			keys.insert(keyStr.at(i));
			openDoor(keyStr.at(i));
		}
		findStartPointSero(0);
		findStartPointSero(M - 1);
		findStartPointGaro(0);
		findStartPointGaro(N - 1);
		bfs();
		cout << answer << "\n";
	}
	return 0;
}