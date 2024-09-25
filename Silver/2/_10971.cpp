#include <iostream>
using namespace std;
int** map;
bool* isVisited;
int N;
int answer = 987654321;
void backTracking(int depth, int start, int current, int sum)
{
	if (depth == N-1)
	{
		if (map[current][start] != 0)
		{
			answer = min(answer, sum+map[current][start]);
		}
	}
	else
	{
		for (int next = 0; next < N; next++)
		{
			if (next!=start && map[current][next] != 0 && isVisited[next] == false)
			{
				isVisited[next] = true;
				backTracking(depth + 1, start, next, sum + map[current][next]);
				isVisited[next] = false;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	map = new int* [N];
	isVisited = new bool[N];
	for (int i = 0; i < N; i++)
	{
		isVisited[i] = false;
		map[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		backTracking(0, i, i, 0);
	}
	cout << answer << "\n";
	return 0;
}