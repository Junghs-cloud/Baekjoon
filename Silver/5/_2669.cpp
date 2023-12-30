#include <iostream>
using namespace std;

int main()
{
	int** arr = new int*[102];
	for (int i = 0; i < 102; i++)
	{
		arr[i] = new int[102];
		for (int j = 0; j < 102; j++)
		{
			arr[i][j] = 0;
		}
	}
	int x1, x2, y1, y2;
	for (int i = 0; i < 4; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j < x2; j++)
		{
			for (int k = y1; k < y2; k++)
			{
				arr[j][k]=1;
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < 102; i++)
	{
		for (int j = 0; j < 102; j++)
		{
			if (arr[i][j] == 1)
			{
				answer++;
			}
		}
	}
	cout << answer << "\n";
	return 0;
}