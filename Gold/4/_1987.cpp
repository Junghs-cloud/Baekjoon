#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
char** arr;
bool** isVisited;
bool* isVisitedAlphabet;
int maxLength = 0;
int dx[] = {0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void dfs(int x, int y, int length)
{
	int index = arr[x][y]-65;
	isVisited[x][y] = true;
	isVisitedAlphabet[index] = true;
	maxLength = max(length, maxLength);
	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX >= 0 && nextX <= N - 1 && nextY >= 0 && nextY <= M - 1)
		{
			if (isVisited[nextX][nextY] == false && isVisitedAlphabet[arr[nextX][nextY]-65] == false)
			{
				dfs(nextX, nextY, length+1);
				isVisited[nextX][nextY] = false;
				isVisitedAlphabet[arr[nextX][nextY] - 65] = false;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> N >> M;
	arr = new char* [N];
	isVisited = new bool* [N];
	isVisitedAlphabet = new bool[26];
	for (int i = 0; i < 26; i++)
	{
		isVisitedAlphabet[i] = false;
	}
	for (int i = 0; i < N; i++)
	{
		arr[i] = new char[M];
		isVisited[i] = new bool[M];
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = str.at(j);
			isVisited[i][j] = false;
		}
	}
	dfs(0, 0, 1);
	cout << maxLength << "\n";
	return 0;
}