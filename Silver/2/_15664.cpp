#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int* arr;
int* answer;

bool* isVisited;
void backTracking(int depth, int index)
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
		int prevNum = -1;
		for (int i = index; i < N; i++)
		{
			if (isVisited[i]==false && prevNum != arr[i])
			{
				answer[depth] = arr[i];
				prevNum = arr[i];
				isVisited[i] = true;
				backTracking(depth + 1, i + 1);
				isVisited[i] = false;
			}
			
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	arr = new int[N];
	answer = new int[M];
	isVisited = new bool[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		isVisited[i] = false;
	}
	sort(arr, arr + N);
	backTracking(0, 0);
	return 0;
}