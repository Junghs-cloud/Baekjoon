#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int* arr;
int* answer;

void backTracking(int depth)
{
	if (depth == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << answer[i] << " ";
		}
		cout << "\n";
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			answer[depth] = arr[i];
			backTracking(depth + 1);
		}
	}
}

int main()
{
	cin >> N >> M;
	arr = new int[N];
	answer = new int[M];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	backTracking(0);
	return 0;
}