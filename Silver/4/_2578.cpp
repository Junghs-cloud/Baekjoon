#include <iostream>
#include <vector>
using namespace std;
int** arr;
bool checkBingo()
{
	int bingo = 0;
	for (int i = 0; i < 5; i++)
	{
		int minusOneCount = 0;
		for (int j = 0; j < 5; j++)
		{
			if (arr[i][j] == -1)
			{
				minusOneCount++;
			}
		}
		if (minusOneCount == 5)
		{
			bingo++;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		int minusOneCount = 0;
		for (int j = 0; j < 5; j++)
		{
			if (arr[j][i] == -1)
			{
				minusOneCount++;
			}
		}
		if (minusOneCount == 5)
		{
			bingo++;
		}
	}
	if (arr[0][0] == -1 && arr[1][1] == -1 && arr[2][2] == -1 && arr[3][3] == -1 && arr[4][4] == -1)
	{
		bingo++;
	}
	if (arr[0][4] == -1 && arr[1][3] == -1 && arr[2][2] == -1 && arr[3][1] == -1 && arr[4][0] == -1)
	{
		bingo++;
	}
	if (bingo >= 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void eraseNum(int num)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (arr[i][j] == num)
			{
				arr[i][j] = -1;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	arr = new int*[5];
	int* numbers = new int[25];
	for (int i = 0; i < 5; i++)
	{
		arr[i] = new int[5];
		for (int j = 0; j < 5; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 25; i++)
	{
		cin >> numbers[i];
	}
	for (int i = 0; i < 25; i++)
	{
		eraseNum(numbers[i]);
		if (checkBingo() == true)
		{
			cout << i + 1 << "\n";
			break;
		}
	}
	return 0;
}