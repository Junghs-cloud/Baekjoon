#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int* arr;
int N;
int a, b;
bool* isVisited;

void search()
{
	if (a == b)
	{
		cout << 0 << "\n";
		return;
	}
	queue<pair<int, int>> bfsQueue;
	bfsQueue.push(make_pair(a - 1, 0));
	isVisited[a - 1] = true;
	while (!bfsQueue.empty())
	{
		int currentPos = bfsQueue.front().first;
		if (currentPos == b - 1)
		{
			cout << bfsQueue.front().second << "\n";
			return;
		}
		else
		{
			int jump = arr[currentPos];
			int mod = currentPos % jump;
			for (int i = mod; i < N; i += jump)
			{
				if (isVisited[i] == false)
				{
					isVisited[i] = true;
					bfsQueue.push(make_pair(i, bfsQueue.front().second + 1));
				}
			}
		}
		bfsQueue.pop();
	}
	cout << -1 << "\n";
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	arr = new int[N];
	isVisited = new bool[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		isVisited[i] = false;
	}
	cin >> a >> b;
	search();
	return 0;
}