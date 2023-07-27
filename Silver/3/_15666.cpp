#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int* arr;
int* answer;

void backTracking(int depth, int index)
{
	int temp = 0;
	if (depth == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << answer[i]<<" ";
		}
		cout << "\n";
		return;
	}
	else
	{
		for (int i = index; i < N; i++)
		{
			if (temp != arr[i])
			{
				temp = arr[i];
				answer[depth] = arr[i];
				backTracking(depth + 1, i);
			}
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
	backTracking(0, 0);
	return 0;
}