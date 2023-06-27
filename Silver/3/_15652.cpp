#include <iostream>
using namespace std;
int N, M;
int* arr;
void dfs(int depth, int index)
{
	if (depth == M)
	{
		for (int i = 0; i < depth; i++)
		{
			cout << arr[i]<<" ";
		}
		cout << "\n";
		return;
	}
	else
	{
		for (int i = index; i <= N; i++)
		{
			arr[depth] = i;
			dfs(depth + 1, i);
		}
	}
}

int main()
{

	cin >> N >> M;
	arr = new int[M];
	dfs(0, 1);
	return 0;
}