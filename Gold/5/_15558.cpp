#include <iostream>
#include <queue>
using namespace std;
int* leftArr;
int* rightArr;
bool* isVisitedLeft;
bool* isVisitedRight;
int N, K;

struct info
{
	string pos;
	int index;
	int time;
	info(string a, int b, int c)
	{
		pos = a;
		index = b;
		time = c;
	}
};
queue<info> bfsQueue;

void bfs()
{
	bool canClear = false;
	bfsQueue.push(info("left", 0, 0));
	isVisitedLeft[0] = true;
	while (!bfsQueue.empty())
	{
		info current = bfsQueue.front();
		if (current.index >= N - K)
		{
			canClear = true;
			break;
		}
		if (current.pos == "left")
		{
			if (isVisitedLeft[current.index + 1] == false && leftArr[current.index+1] == 1)
			{
				isVisitedLeft[current.index + 1] = true;
				bfsQueue.push(info("left", current.index + 1, current.time + 1));
			}
			if (isVisitedLeft[current.index - 1] == false && current.time+1 <= current.index-1 &&leftArr[current.index - 1] == 1)
			{
				isVisitedLeft[current.index - 1] = true;
				bfsQueue.push(info("left", current.index - 1, current.time + 1));
			}
			if (isVisitedRight[current.index + K] == false && rightArr[current.index + K] == 1)
			{
				isVisitedRight[current.index + K] = true;
				bfsQueue.push(info("right", current.index + K, current.time + 1));
			}
		}
		else
		{
			if (isVisitedRight[current.index + 1] == false && rightArr[current.index + 1] == 1)
			{
				isVisitedRight[current.index + 1] = true;
				bfsQueue.push(info("right", current.index + 1, current.time + 1));
			}
			if (isVisitedRight[current.index - 1] == false && current.time + 1 <= current.index - 1 && rightArr[current.index - 1] == 1)
			{
				isVisitedRight[current.index - 1] = true;
				bfsQueue.push(info("right", current.index - 1, current.time + 1));
			}
			if (isVisitedLeft[current.index + K] == false && leftArr[current.index + K] == 1)
			{
				isVisitedLeft[current.index + K] = true;
				bfsQueue.push(info("left", current.index + K, current.time + 1));
			}
		}
		bfsQueue.pop();
	}
	if (canClear == true)
	{
		cout << 1 << "\n";
	}
	else
	{
		cout << 0 << "\n";
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> N >> K;
	leftArr = new int[N];
	rightArr = new int[N];
	isVisitedLeft = new bool[N];
	isVisitedRight = new bool[N];
	cin >> str;
	for (int i = 0; i < N; i++)
	{
		leftArr[i] = str.at(i) - 48;
		isVisitedLeft[i] = false;
	}
	cin >> str;
	for (int i = 0; i < N; i++)
	{
		rightArr[i] = str.at(i) - 48;
		isVisitedRight[i] = false;
	}
	bfs();
	return 0;
}