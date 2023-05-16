#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int* arr;
int* storage;

void backtracking(int depth, int index)
{
	if (depth == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout<<storage[i]<<" ";
		}
		cout << "\n";
		return;
	}
	else
	{
		for (int i = index; i < N; i++)
		{
			storage[depth] = arr[i];
			backtracking(depth + 1, i + 1);
		}
	}
}

int main()
{
	cin >> N>>M;
	arr = new int[N];
	storage = new int[M];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	backtracking(0, 0);
	return 0;
}