#include <iostream>
#include <queue>
using namespace std;
int N, M;
int*** arr;
bool*** isVisited;

struct info
{
	int x;
	int y;
	int length;
	bool isBreak;
	info(int a, int b,int c, bool d)
	{
		x = a;
		y = b;
		length = c;
		isBreak = d;
	}
};

queue<info> bfsQueue;

void bfs()
{
	bfsQueue.push(info(0, 0, 1, false));
	bool findRoute = false;
	isVisited[0][0][0] = true;

	while (!bfsQueue.empty())
	{
		info currentInfo = bfsQueue.front();
		if (currentInfo.x == N - 1 && currentInfo.y == M - 1)
		{
			findRoute = true;
			cout << currentInfo.length<<"\n";
			break;
		}
		if (currentInfo.isBreak == false)
		{
			if (currentInfo.x > 0 && arr[currentInfo.x - 1][currentInfo.y][0] == 0 && isVisited[currentInfo.x - 1][currentInfo.y][0] == false)
			{
				isVisited[currentInfo.x - 1][currentInfo.y][0] = true;
				bfsQueue.push(info(currentInfo.x - 1, currentInfo.y, currentInfo.length + 1, false));
			}
			if (currentInfo.x < N - 1 && arr[currentInfo.x + 1][currentInfo.y][0] == 0 && isVisited[currentInfo.x + 1][currentInfo.y][0] == false)
			{
				isVisited[currentInfo.x + 1][currentInfo.y][0] = true;
				bfsQueue.push(info(currentInfo.x + 1, currentInfo.y, currentInfo.length + 1, false));
			}
			if (currentInfo.y > 0 && arr[currentInfo.x][currentInfo.y - 1][0] == 0 && isVisited[currentInfo.x][currentInfo.y - 1][0] == false)
			{
				isVisited[currentInfo.x][currentInfo.y - 1][0] = true;
				bfsQueue.push(info(currentInfo.x, currentInfo.y - 1, currentInfo.length + 1, false));
			}
			if (currentInfo.y < M - 1 && arr[currentInfo.x][currentInfo.y + 1][0] == 0 && isVisited[currentInfo.x][currentInfo.y + 1][0] == false)
			{
				isVisited[currentInfo.x][currentInfo.y + 1][0] = true;
				bfsQueue.push(info(currentInfo.x, currentInfo.y + 1, currentInfo.length + 1, false));
			}

			if (currentInfo.x > 0 && arr[currentInfo.x - 1][currentInfo.y][0] == 1 && isVisited[currentInfo.x - 1][currentInfo.y][1] == false)
			{
				isVisited[currentInfo.x - 1][currentInfo.y][1] = true;
				bfsQueue.push(info(currentInfo.x - 1, currentInfo.y, currentInfo.length + 1, true));
			}
			if (currentInfo.x < N - 1 && arr[currentInfo.x + 1][currentInfo.y][0] == 1 && isVisited[currentInfo.x + 1][currentInfo.y][1] == false)
			{
				isVisited[currentInfo.x + 1][currentInfo.y][1] = true;
				bfsQueue.push(info(currentInfo.x + 1, currentInfo.y, currentInfo.length + 1, true));
			}
			if (currentInfo.y > 0 && arr[currentInfo.x][currentInfo.y - 1][0] == 1 && isVisited[currentInfo.x][currentInfo.y - 1][1] == false)
			{
				isVisited[currentInfo.x][currentInfo.y - 1][1] = true;
				bfsQueue.push(info(currentInfo.x, currentInfo.y - 1, currentInfo.length + 1, true));
			}
			if (currentInfo.y < M - 1 && arr[currentInfo.x][currentInfo.y + 1][0] == 1 && isVisited[currentInfo.x][currentInfo.y + 1][1] == false)
			{
				isVisited[currentInfo.x][currentInfo.y + 1][1] = true;
				bfsQueue.push(info(currentInfo.x, currentInfo.y + 1, currentInfo.length + 1, true));
			}
		}
		else
		{
			if (currentInfo.x > 0 && arr[currentInfo.x - 1][currentInfo.y][1] == 0 && isVisited[currentInfo.x - 1][currentInfo.y][1] == false)
			{
				isVisited[currentInfo.x - 1][currentInfo.y][1] = true;
				bfsQueue.push(info(currentInfo.x - 1, currentInfo.y, currentInfo.length + 1, true));
			}
			if (currentInfo.x < N - 1 && arr[currentInfo.x + 1][currentInfo.y][1] == 0 && isVisited[currentInfo.x + 1][currentInfo.y][1] == false)
			{
				isVisited[currentInfo.x + 1][currentInfo.y][1] = true;
				bfsQueue.push(info(currentInfo.x + 1, currentInfo.y, currentInfo.length + 1, true));
			}
			if (currentInfo.y > 0 && arr[currentInfo.x][currentInfo.y - 1][1] == 0 && isVisited[currentInfo.x][currentInfo.y - 1][1] == false)
			{
				isVisited[currentInfo.x][currentInfo.y - 1][1] = true;
				bfsQueue.push(info(currentInfo.x, currentInfo.y - 1, currentInfo.length + 1, true));
			}
			if (currentInfo.y < M - 1 && arr[currentInfo.x][currentInfo.y + 1][1] == 0 && isVisited[currentInfo.x][currentInfo.y + 1][1] == false)
			{
				isVisited[currentInfo.x][currentInfo.y + 1][1] = true;
				bfsQueue.push(info(currentInfo.x, currentInfo.y + 1, currentInfo.length + 1, true));
			}
		}

		bfsQueue.pop();
	}
	if (findRoute == false)
	{
		cout << "-1" << "\n";
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> N >> M;
	arr = new int**[N];
	isVisited = new bool** [N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int*[M];
		isVisited[i] = new bool*[M];
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = new int[2];
			isVisited[i][j] = new bool[2];
			arr[i][j][0] = (int)str.at(j) - 48;
			arr[i][j][1] = (int)str.at(j) - 48;
			isVisited[i][j][0] = false;
			isVisited[i][j][1] = false;
		}
	}
	bfs();
	return 0;
}