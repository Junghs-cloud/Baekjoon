#include <iostream>
#include <cmath>
using namespace std;
int QueenCount = 0;
int* board;
int N;

bool isPromising(int col)
{
	for (int i = 1; i < col; i++)
	{
		if (board[i] == board[col] || abs(board[col] - board[i]) == abs(col - i))
		{
			return false;
		}
	}
	return true;
}

void nQueens(int i)
{
	if (isPromising(i))
	{
		if (i == N)
		{
			QueenCount++;
		}
		else
		{
			for (int j = 1; j <= N; j++)
			{
				board[i + 1] = j;
				nQueens(i + 1);
			}
		}
	}
}

int main()
{
	cin >> N;
	board = new int[N + 1];
	nQueens(0);
	cout << QueenCount << "\n";
	return 0;
}