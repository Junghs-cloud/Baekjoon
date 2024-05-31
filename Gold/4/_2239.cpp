#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int** arr;
vector<pair<int, int>> shouldFill;
bool isMade;

bool canFillRowCol(int row, int col, int checkNum)
{
	bool canFill = true;
	for (int i = 0; i < 9; i++)
	{
		if (arr[i][col] == checkNum)
		{
			canFill = false;
			return canFill;
		}
		if (arr[row][i] == checkNum)
		{
			canFill = false;
			return canFill;
		}
	}
	return canFill;
}

bool canFill3x3Square(int row, int col, int checkNum)
{
	int startX = row / 3 * 3;
	int startY = col / 3 * 3;
	bool canFill = true;
	for (int i = startX; i < startX + 3; i++)
	{
		for (int j = startY; j < startY + 3; j++)
		{
			if (arr[i][j] == checkNum)
			{
				return false;
			}
		}
	}
	return true;
}

void backTracking(int depth)
{
	if (depth == shouldFill.size())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << arr[i][j];
			}
			cout << "\n";
		}
		isMade = true;
		return;
	}
	else
	{
		if (isMade == true)
		{
			return;
		}
		int row = shouldFill.at(depth).first;
		int col = shouldFill.at(depth).second;
		bool canFill = true;
		for (int num = 1; num <= 9; num++)
		{
			canFill = canFillRowCol(row, col, num) && canFill3x3Square(row, col, num);
			if (canFill == true)
			{
				arr[row][col] = num;
				backTracking(depth + 1);
				arr[row][col] = 0;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	arr = new int*[9];
	for (int i = 0; i < 9; i++)
	{
		arr[i] = new int[9];
		cin >> str;
		for (int j = 0; j < 9; j++)
		{
			arr[i][j] = str.at(j) - 48;
			if (str.at(j) == '0')
			{
				shouldFill.push_back(pair(i, j));
			}
		}
	}
	backTracking(0);
	return 0;
}