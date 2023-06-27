#include <iostream>
using namespace std;

bool* isVisited;
int N, M;
int* permutation;


void dfs(int depth)
{
	if (depth == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << permutation[i]<<" ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (isVisited[i] == false)
		{
			isVisited[i] = true;
			permutation[depth] = i + 1;
			dfs(depth + 1);
			isVisited[i] = false;
		}
	}


}

int main()
{

	cin >> N >> M;
	isVisited = new bool[N];
	permutation = new int[M];
	for (int i = 0; i < N; i++)
	{
		isVisited[i] = false;
	}
	dfs(0);
	return 0;
}