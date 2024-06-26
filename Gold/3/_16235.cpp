#include <iostream>
#include <algorithm>
#include <vector>
int N, M, K;
using namespace std;
int** currentFoods;
int** winterFoods;
vector<int>** trees;
vector<int>** alive;
vector<int>** dead;
int dx[] = {- 1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void spring()
{
	for (int i = 0; i< N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			sort(trees[i][j].begin(), trees[i][j].end());
			for (int k = 0; k < trees[i][j].size(); k++)
			{
				int currentTree = trees[i][j].at(k);
				if (currentTree <= currentFoods[i][j])
				{
					alive[i][j].push_back(currentTree+1);
					currentFoods[i][j] -= currentTree;
				}
				else
				{
					dead[i][j].push_back(currentTree);
				}
			}
		}
	}
}

void summer()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < dead[i][j].size(); k++)
			{
				int currentTree = dead[i][j].at(k);
				currentFoods[i][j] += (currentTree / 2);
			}
			trees[i][j] = alive[i][j];
			alive[i][j].clear();
			dead[i][j].clear();
		}
	}
}

void addTree(int x, int y)
{
	for (int i = 0; i < 8; i++)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N)
		{
			trees[nextX][nextY].push_back(1);
		}
	}
}

void autumn()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < trees[i][j].size(); k++)
			{
				int currentTree = trees[i][j].at(k);
				if (currentTree % 5 == 0)
				{
					addTree(i, j);
				}
			}
		}
	}
}

void winter()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			currentFoods[i][j] += winterFoods[i][j];
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int x, y, age;
	int answer = 0;
	cin >> N >> M >> K;
	currentFoods = new int* [N];
	winterFoods = new int*[N];
	trees = new vector<int>* [N];
	alive = new vector<int>*[N];
	dead = new vector<int>*[N];
	for (int i = 0; i < N; i++)
	{
		currentFoods[i] = new int[N];
		winterFoods[i] = new int[N];
		trees[i] = new vector<int>[N];
		alive[i] = new vector<int>[N];
		dead[i] = new vector<int>[N];
		for (int j = 0; j < N; j++)
		{
			currentFoods[i][j] = 5;
			cin>>winterFoods[i][j];
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y >> age;
		trees[x - 1][y - 1].push_back(age);
	}
	for (int i = 1; i <= K; i++)
	{
		spring();
		summer();
		autumn();
		winter();
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			answer += trees[i][j].size();
		}
	}
	cout << answer << "\n";
	return 0;
}