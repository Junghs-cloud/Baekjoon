#include <iostream>
#include <queue>
using namespace std;

int A, K;
bool* isVisited;
int calcCount = 0;
struct info
{
	int currentPos;
	int currentCount;
	info(int a, int b)
	{
		currentPos = a;
		currentCount = b;
	}
};
queue<info> pos;

void bfs()
{
	isVisited[A] = true;
	pos.push(info(A, 0));
	while (!pos.empty())
	{
		int currentPos = pos.front().currentPos;
		int currentCalcCount = pos.front().currentCount;
		if (currentPos == K)
		{
			calcCount = currentCalcCount;
			break;
		}
		if (currentPos + 1 <= 1000000 && isVisited[currentPos + 1] == false)
		{
			isVisited[currentPos+1] = true;
			pos.push(info(currentPos+1, currentCalcCount+1));
		}
		if (2*currentPos <= 1000000 && isVisited[2* currentPos] == false)
		{
			isVisited[2 * currentPos] = true;
			pos.push(info(2 * currentPos, currentCalcCount + 1));
		}
		pos.pop();
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	isVisited = new bool[1000001];
	for (int i = 0; i < 1000001; i++)
	{
		isVisited[i] = false;
	}
	cin >> A >> K;
	bfs();
	cout << calcCount << "\n";
	return 0;
}