#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int* answers;
int* arr;
bool* isVisited;

void backTracking(int depth)
{
	int lastNum = 0;
	if (depth == M)
	{
		string str="\0";
		for (int i = 0; i < M; i++)
		{
			cout << answers[i] << " ";
		}
		cout << "\n";
		return;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (isVisited[i] == false && lastNum != arr[i])
			{
				isVisited[i] = true;
				answers[depth] = arr[i];
				lastNum = arr[i];
				backTracking(depth + 1);
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
	answers = new int[M];
	isVisited = new bool[N];
	for (int i = 0; i < N; i++)
	{
		isVisited[i] = false;
		cin >> arr[i];
	}
	sort(arr, arr + N);
	backTracking(0);
	return 0;
}