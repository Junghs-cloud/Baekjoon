#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
int** arr;
bool** isVisited;
queue<pair<int, int>> bfsQueue;
vector<int> answer;

void find(int i, int j)
{
	int size = 0;
	isVisited[i][j] = true;
	bfsQueue.push(make_pair(i, j));
	while (!bfsQueue.empty())
	{
		pair<int, int> current = bfsQueue.front();
		size++;
		if (current.first > 0 && isVisited[current.first-1][current.second]==false && arr[current.first-1][current.second]==0)
		{
			isVisited[current.first - 1][current.second] = true;
			bfsQueue.push(make_pair(current.first - 1, current.second));
		}
		if (current.first < N-1 && isVisited[current.first + 1][current.second] == false && arr[current.first + 1][current.second] == 0)
		{
			isVisited[current.first + 1][current.second] = true;
			bfsQueue.push(make_pair(current.first + 1, current.second));
		}
		if (current.second > 0 && isVisited[current.first ][current.second - 1] == false && arr[current.first][current.second - 1] == 0)
		{
			isVisited[current.first][current.second-1] = true;
			bfsQueue.push(make_pair(current.first, current.second-1));
		}
		if (current.second < M-1 && isVisited[current.first][current.second + 1] == false && arr[current.first][current.second + 1] == 0)
		{
			isVisited[current.first][current.second + 1] = true;
			bfsQueue.push(make_pair(current.first, current.second + 1));
		}
		bfsQueue.pop();
	}
	answer.push_back(size);
}

int main()
{
	int  K;
	int x1, y1, x2, y2;
	cin >> N >> M >> K;
	arr = new int*[N];
	isVisited = new bool*[N];

	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
		isVisited[i] = new bool[M];
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = 0;
			isVisited[i][j] = false;
		}
	}
	for (int i = 0; i < K; i++)
	{
		cin >> y1 >> x1 >> y2 >> x2;
		for (int j = x1; j < x2; j++)
		{
			for (int k = y1; k < y2; k++)
			{
				arr[j][k] = 1;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0 && isVisited[i][j] == false)
			{
				find(i, j);
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer.at(i) << " ";
	}
	return 0;
}