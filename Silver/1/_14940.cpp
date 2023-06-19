#include <iostream>
#include <queue>
using namespace std;
int** arr;
bool** isVisited;
int N, M;
struct info
{
	int x;
	int y;
	int length;
	info(int a, int b, int c)
	{
		x = a;
		y = b;
		length = c;
	}
};
queue<info> bfsQueue;

void bfs(int i, int j)
{
	bfsQueue.push(info(i, j, 0));
	isVisited[i][j] = true;
	arr[i][j] = 0;
	while (!bfsQueue.empty())
	{
		info currentFront = bfsQueue.front();
		int currentX = currentFront.x;
		int currentY = currentFront.y;
		int currentLength = currentFront.length;
		bool isAdjacent = false;
		if (currentX > 0 && isVisited[currentX - 1][currentY] == false && arr[currentX - 1][currentY] == 1)
		{
			isAdjacent = true;
			isVisited[currentX - 1][currentY] = true;
			arr[currentX - 1][currentY] = currentLength + 1;
			bfsQueue.push(info(currentX-1, currentY, currentLength + 1));
		}
		if (currentX < N-1 && isVisited[currentX + 1][currentY] == false && arr[currentX + 1][currentY] == 1)
		{
			isAdjacent = true;
			isVisited[currentX + 1][currentY] = true;
			arr[currentX + 1][currentY] = currentLength + 1;
			bfsQueue.push(info(currentX + 1, currentY, currentLength + 1));
		}
		if (currentY > 0 && isVisited[currentX][currentY - 1] == false && arr[currentX][currentY - 1] == 1)
		{
			isAdjacent = true;
			isVisited[currentX][currentY - 1] = true;
			arr[currentX][currentY - 1] = currentLength + 1;
			bfsQueue.push(info(currentX, currentY - 1, currentLength + 1));
		}
		if (currentY < M - 1 && isVisited[currentX][currentY + 1] == false && arr[currentX][currentY + 1] == 1)
		{
			isAdjacent = true;
			isVisited[currentX][currentY + 1] = true;
			arr[currentX][currentY + 1] = currentLength + 1;
			bfsQueue.push(info(currentX, currentY + 1, currentLength + 1));
		}
		if (isAdjacent == false)
		{
			bfsQueue.pop();
		}
	}

}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int startX = 0;
	int startY = 0;
	cin >> N >> M;
	arr = new int*[N];
	isVisited = new bool* [N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
		isVisited[i] = new bool[M];
		for (int j = 0; j < M; j++)
		{
			isVisited[i][j] = false;
			cin >> arr[i][j];
			if (arr[i][j] == 2)
			{
				startX = i;
				startY = j;
			}
		}
	}
	bfs(startX, startY);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (isVisited[i][j] == false && arr[i][j] == 1)
			{
				cout << "-1" << " ";
			}
			else
			{
				cout << arr[i][j] << " ";
			}
			
		}
		cout << "\n";
	}
	return 0;
}