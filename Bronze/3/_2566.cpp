#include <iostream>
using namespace std;

int main()
{
	int** arr = new int*[9];
	for (int i = 0; i < 9; i++)
	{
		arr[i] = new int[9];
		for (int j = 0; j < 9; j++)
		{
			cin >> arr[i][j];
		}
	}
	int max = -1;
	int row = -1;
	int col = -1;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] > max)
			{
				max = arr[i][j];
				row = i + 1;
				col = j + 1;
			}
		}
	}
	cout << max << "\n";
	cout << row << " " << col << "\n";
	return 0;
}