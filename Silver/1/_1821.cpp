#include <iostream>
using namespace std;
int N, F;
int** arr;
bool* isUsed;
bool isFound;

void dfs(int depth)
{
	if (depth == N)
	{
		for (int i = 1; i < N; i++)
		{
			for (int j = 0; j < N - i; j++)
			{
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j+1];
			}
		}
		if (arr[N - 1][0] == F)
		{
			for (int i = 0; i < N; i++)
			{
				cout << arr[0][i] << " ";
			}
			isFound = true;
		}
	}
	else
	{
		for (int i = 1; (i <= N && isFound == false); i++)
		{
			if (isUsed[i] == false)
			{
				arr[0][depth] = i;
				isUsed[i] = true;
				dfs(depth + 1);
				isUsed[i] = false;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	isFound = false;
	cin >> N >> F;
	arr = new int* [N];
	isUsed = new bool[N+1];
	for (int i = 0; i < N+1; i++)
	{
		isUsed[i] = false;
	}
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
	}
	dfs(0);
	return 0;
}