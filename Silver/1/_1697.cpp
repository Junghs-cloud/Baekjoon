#include <iostream>
#include <queue>
using namespace std;

struct information
{
	int pos;
	int time;
	information(int x, int y)
	{
		pos = x;
		time = y;
	}
};

queue<information> bfsQueue;
bool isVisited[100001];
int N, K;

void bfs(int N)
{
	int currentPos;
	int currentTime;
	bfsQueue.push(information(N, 0));
	while (!bfsQueue.empty())
	{
		information currentFront = bfsQueue.front();
		currentPos = currentFront.pos;
		currentTime = currentFront.time;
		if (currentPos == K)
		{
			cout << currentTime<<"\n";
			break;
		}
		if (currentPos >= 0 && currentPos <= 100000 && isVisited[currentPos] == false)
		{
			isVisited[currentPos] = true;
			bfsQueue.push(information(currentPos + 1, currentTime + 1));
			bfsQueue.push(information(currentPos - 1, currentTime + 1));
			bfsQueue.push(information(2 * currentPos, currentTime + 1));
		}
		bfsQueue.pop();
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < 100001; i++)
	{
		isVisited[i] = false;
	}
	bfs(N);
	return 0;
}