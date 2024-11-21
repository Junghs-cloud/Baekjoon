#include <iostream>
#include <algorithm>
using namespace std;
int** arr;
int N;
bool** isVisited;
int answer;

bool checkPosition(int i, int j)
{
	if (isVisited[i][j] == false && isVisited[i + 1][j] == false && isVisited[i - 1][j] == false && isVisited[i][j + 1] == false && isVisited[i][j - 1] == false)
	{
		return true;
	}
	return false;
}

void set(int i, int j, bool b)
{
	isVisited[i][j] = b;
	isVisited[i + 1][j] = b;
	isVisited[i - 1][j] = b;
	isVisited[i][j - 1] = b;
	isVisited[i][j + 1] = b;
}

void backTracking(int depth, int maxDepth)
{
	if (depth == maxDepth)
	{
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (isVisited[i][j] == true)
				{
					sum += arr[i][j];
				}
			}
		}
		answer = min(answer, sum);
	}
	else
	{
		for (int i = 1; i < N-1; i++)
		{
			for (int j = 1; j < N - 1; j++)
			{
				if (checkPosition(i, j) == true)
				{
					set(i, j, true);
					backTracking(depth + 1, maxDepth);
					set(i, j, false);
				}
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	arr = new int*[N];
	isVisited = new bool* [N];
	answer = 987654321;
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
		isVisited[i] = new bool[N];
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			isVisited[i][j] = false;
		}
	}
	backTracking(0, 3);
	cout << answer << "\n";
	return 0;
}