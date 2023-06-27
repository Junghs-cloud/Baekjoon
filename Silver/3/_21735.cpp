#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct info
{
	int size;
	int time;
	int pos;
	info(int a, int b, int c)
	{
		size = a;
		time = b;
		pos = c;
	}
};

queue<info> bfsQueue;
int N, M;
int* arr;
vector<int> snowSizeVector;

void bfs()
{
	bfsQueue.push(info(1, 0, 0));
	while (!bfsQueue.empty())
	{
		info currentTop = bfsQueue.front();
		int currentTime = currentTop.time;
		int currentSize = currentTop.size;
		int currentPos = currentTop.pos;
		if (currentPos >= N || currentTime == M)
		{
			snowSizeVector.push_back(currentSize);
		}
		else
		{
			if (currentPos <= N - 1)
			{
				bfsQueue.push(info(currentSize + arr[currentPos + 1], currentTime + 1, currentPos + 1));
			}
			if (currentPos <= N - 2)
			{
				bfsQueue.push(info(currentSize / 2 + arr[currentPos + 2], currentTime + 1, currentPos + 2));
			}
		}
		bfsQueue.pop();
	}

}

int main()
{
	cin >> N >> M;
	arr = new int[N + 1];
	arr[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		
	}
	bfs();
	sort(snowSizeVector.begin(), snowSizeVector.end());
	cout << snowSizeVector.at(snowSizeVector.size() - 1)<<"\n";
	return 0;
}