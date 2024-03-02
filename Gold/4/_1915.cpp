#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	string str;
	cin >> N >> M;
	int** arr = new int*[N];
	int** left = new int* [N];
	int** up = new int* [N];
	int** maxLength = new int*[N];
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
		left[i] = new int[M];
		up[i] = new int[M];
		maxLength[i] = new int[M];
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = str.at(j) - 48;
			left[i][j] = 0;
			up[i][j] = 0;
			maxLength[i][j] = 0;
		}
	}
	if (arr[0][0] == 1)
	{
		maxLength[0][0] = 1;
		left[0][0] = 1;
		up[0][0] = 1;
	}
	for (int i = 1; i < M; i++)
	{
		if (arr[0][i] == 1)
		{
			left[0][i] = left[0][i - 1] + 1;
			up[0][i] = 1;
			maxLength[0][i] = 1;
		}
	}
	for (int i = 1; i < N; i++)
	{
		if (arr[i][0] == 1)
		{
			up[i][0] = up[i - 1][0] + 1;
			left[i][0] = 1;
			maxLength[i][0] = 1;
		}
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < M; j++)
		{
			if (arr[i][j] == 1)
			{
				int fromLeft = left[i][j-1];
				int fromUp = up[i - 1][j];
				left[i][j] = fromLeft + 1;
				up[i][j] = fromUp + 1;
				int length = min(fromLeft, fromUp);
				if (length >= 1)
				{
					if (maxLength[i - 1][j - 1] < length)
					{
						maxLength[i][j] = maxLength[i - 1][j - 1] + 1;
					}
					else
					{
						maxLength[i][j] = length + 1;
					}
				}
				else
				{
					maxLength[i][j] = 1;
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			answer = max(answer, maxLength[i][j] * maxLength[i][j]);
		}
	}
	cout << answer << "\n";
	return 0;
}