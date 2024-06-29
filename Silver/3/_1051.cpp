#include <iostream>
#include <algorithm>
using namespace std;
int** arr;

bool isAllSame(int startX, int startY, int size)
{
	int leftUp = arr[startX][startY];
	int rightUp = arr[startX][startY + size - 1];
	int leftDown = arr[startX + size - 1][startY];
	int rightDown = arr[startX + size - 1][startY + size - 1];
	if (leftUp == rightUp && leftUp == leftDown && leftDown == rightDown)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	string str;
	cin >> N>>M;
	arr = new int*[N];
	int answer = 1;
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = str.at(j) - 48;
		}
	}
	for (int size = 2; size <= N; size++)
	{
		for (int i = 0; i <= N - size; i++)
		{
			for (int j = 0; j <= M - size; j++)
			{
				if (isAllSame(i, j, size))
				{
					answer = max(answer, size);
				}
			}
		}
	}
	cout << answer * answer << "\n";
	return 0;
}