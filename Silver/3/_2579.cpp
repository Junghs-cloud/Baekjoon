#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int* stairs = new int[N + 1];
	int** gamePoint = new int*[N + 1];
	for (int i = 1; i < N + 1; i++)
	{
		cin >> stairs[i];
	}
	for (int i = 0; i < N + 1; i++)
	{
		gamePoint[i] = new int[3];
		for (int j = 0; j < 3; j++)
		{
			gamePoint[i][j] = 0;
		}
	}
	if (N >= 1)
	{
		gamePoint[1][1] = stairs[1];
		gamePoint[1][2] = 0;
	}
	if (N >= 2)
	{
		gamePoint[2][1] = stairs[2];
		gamePoint[2][2] = gamePoint[1][1] + stairs[2];
	}
	for (int i = 3; i < N + 1; i++)
	{
		gamePoint[i][1] = max(gamePoint[i - 2][2], gamePoint[i - 2][1]) +stairs[i];
		gamePoint[i][2] = gamePoint[i-1][1] + stairs[i];
	}
	cout << max(gamePoint[N][1], gamePoint[N][2])<<"\n";
	return 0;
}