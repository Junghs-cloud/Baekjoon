#include <iostream>
using namespace std;
int N, M;
int** board;
int sum = 0;

void fourBlockGaro(int i, int j)
{
	int partialSum = 0;
	for (int startIndex = 0; startIndex < 4; startIndex++)
	{
		partialSum += board[i][j + startIndex];
	}
	if (partialSum > sum)
	{
		sum = partialSum;
	}
}

void fourBlockSero(int i, int j)
{
	int partialSum = 0;
	for (int startIndex = 0; startIndex < 4; startIndex++)
	{
		partialSum += board[i + startIndex][j];
	}
	if (partialSum > sum)
	{
		sum = partialSum;
	}
}

void twoBlock(int i, int j)
{
	int twoPartialSum = 0;
	int partialSum = 0;
	twoPartialSum += board[i][j];
	twoPartialSum += board[i][j + 1];
	twoPartialSum += board[i + 1][j];
	twoPartialSum += board[i + 1][j + 1];
	partialSum = twoPartialSum;
	if (i < N - 2)
	{
		partialSum = max(partialSum, twoPartialSum - board[i][j] + board[i+2][j]);
		partialSum = max(partialSum, twoPartialSum - board[i][j + 1] + board[i + 2][j + 1]);
	}
	if (j < M - 2)
	{
		partialSum = max(partialSum, twoPartialSum - board[i][j] + board[i][j + 2]);
		partialSum = max(partialSum, twoPartialSum - board[i + 1][j] + board[i + 1][j + 2]);
	}
	if (partialSum > sum)
	{
		sum = partialSum;
	}
}

void threeBlockSero(int i, int j)
{
	int threePartialSum = 0;
	int partialSum = 0;
	for (int index = 0; index < 3; index++)
	{
		threePartialSum += board[i + index][j];
	}
	if (j > 0)
	{
		partialSum = max(partialSum, threePartialSum + board[i][j - 1]);
		partialSum = max(partialSum, threePartialSum + board[i + 1][j - 1]);
		partialSum = max(partialSum, threePartialSum + board[i + 2][j - 1]);
	}
	if (j < M - 1)
	{
		partialSum = max(partialSum, threePartialSum + board[i][j + 1]);
		partialSum = max(partialSum, threePartialSum + board[i + 1][j + 1]);
		partialSum = max(partialSum, threePartialSum + board[i + 2][j + 1]);
	}
	if (partialSum > sum)
	{
		sum = partialSum;
	}
}

void threeBlockGaro(int i, int j)
{
	int threePartialSum = 0;
	int partialSum = 0;
	for (int index = 0; index < 3; index++)
	{
		threePartialSum += board[i][j + index];
	}
	if (i > 0)
	{
		partialSum = max(partialSum, threePartialSum + board[i - 1][j]);
		partialSum = max(partialSum, threePartialSum + board[i - 1][j + 1]);
		partialSum = max(partialSum, threePartialSum + board[i - 1][j + 2]);
	}
	if (i < N - 1)
	{
		partialSum = max(partialSum, threePartialSum + board[i + 1][j]);
		partialSum = max(partialSum, threePartialSum + board[i + 1][j + 1]);
		partialSum = max(partialSum, threePartialSum + board[i + 1][j + 2]);
	}
	if (partialSum > sum)
	{
		sum = partialSum;
	}
}

int main()
{
	cin >> N >> M;
	board = new int* [N];
	for (int i = 0; i < N; i++)
	{
		board[i] = new int[M];
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			threeBlockGaro(i, j);
		}
	}
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M; j++)
		{
			threeBlockSero(i, j);
		}
	}
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			twoBlock(i, j);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M - 3; j++)
		{
			fourBlockGaro(i, j);
		}
	}
	for (int i = 0; i < N - 3; i++)
	{
		for (int j = 0; j < M; j++)
		{
			fourBlockSero(i, j);
		}
	}
	cout << sum << "\n";
	return 0;
}