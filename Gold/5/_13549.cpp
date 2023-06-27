#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, K;
bool* isVisited;

struct info
{
	int pos;
	int sec;
	info(int a, int b)
	{
		pos = a;
		sec = b;
	}
};

struct cmp
{
	bool operator()(info i1, info i2)
	{
		if (i1.sec < i2.sec)
		{
			return false;
		}
		else if (i1.sec == i2.sec)
		{
			return i1.pos > i2.pos;
		}
		else
		{
			return true;
		}
	}
};
priority_queue<info, vector<info>, cmp> pq;

void bfs()
{
	pq.push(info(N, 0));
	while (!pq.empty())
	{
		info currentTop = pq.top();
		int currentPos = currentTop.pos;
		if (currentPos == K)
		{
			cout << currentTop.sec << "\n";
			break;
		}
		pq.pop();
		if (currentPos > K && isVisited[currentTop.pos - 1] == false)
		{
			isVisited[currentTop.pos - 1] = true;
			pq.push(info(currentPos - 1, currentTop.sec + 1));
		}
		else
		{
			if (currentTop.pos <= 50000 && isVisited[currentTop.pos * 2] == false)
			{
				isVisited[currentTop.pos * 2] = true;
				pq.push(info(currentTop.pos * 2, currentTop.sec));
			}
			if (currentTop.pos >= 0 && currentTop.pos <= 99999 && isVisited[currentTop.pos + 1] == false)
			{
				isVisited[currentTop.pos + 1] = true;
				pq.push(info(currentTop.pos + 1, currentTop.sec + 1));
			}
			if (currentTop.pos >= 1 && currentTop.pos <= 100000 && isVisited[currentTop.pos - 1] == false)
			{
				isVisited[currentTop.pos - 1] = true;
				pq.push(info(currentTop.pos - 1, currentTop.sec + 1));
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	isVisited = new bool[100001];
	for (int i = 0; i < 100001; i++)
	{
		isVisited[i] = false;
	}
	bfs();
	return 0;
}