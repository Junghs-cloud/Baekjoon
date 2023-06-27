#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int* arr;
int* inputs;
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
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (isVisited[i] == false)
			{
				isVisited[i] = true;
				arr[depth] = inputs[i];
				dfs(depth + 1);
				isVisited[i] = false;
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	inputs = new int[N];
	arr = new int[M];
	isVisited = new bool[N];
	for (int i = 0; i < N; i++)
	{
		isVisited[i] = false;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> inputs[i];
	}
	sort(inputs, inputs + N);
	dfs(0);
	return 0;
}