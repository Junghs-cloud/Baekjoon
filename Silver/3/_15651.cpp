#include <iostream>
using namespace std;

int N, M;
int* arr;
bool* isVisited;

void dfs(int depth)
{
	if (depth == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i]<<" ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++)
	{
		arr[depth] = i + 1;
		dfs(depth + 1);
	}
}

int main()
{
	cin >> N >> M;
	arr = new int[M];
	isVisited = new bool[N];
	for (int i = 0; i < N; i++)
	{
		isVisited[i] = false;
	}
	dfs(0);
	return 0;
}