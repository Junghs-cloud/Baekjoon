#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int answer = 0;
	cin >> N;
	int** arr = new int*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[6];
		for (int j = 0; j < 6; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int k = 0; k < 6; k++)
	{
		int sum = 0;
		int topIndex = k;
		int buttomIndex = 0;
		switch (k)
		{
		case 0: buttomIndex = 5; break;
		case 1: buttomIndex = 3; break;
		case 2: buttomIndex = 4; break;
		case 3: buttomIndex = 1; break;
		case 4: buttomIndex = 2; break;
		case 5: buttomIndex = 0; break;
		}
		if (arr[0][topIndex] != 6 && arr[0][buttomIndex] != 6)
		{
			sum += 6;
		}
		else if ((arr[0][topIndex] == 6 && arr[0][buttomIndex] != 5) || (arr[0][topIndex] != 5 && arr[0][buttomIndex] == 6))
		{
			sum += 5;
		}
		else
		{
			sum += 4;
		}
		for (int i = 1; i < N; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (arr[i][j] == arr[i - 1][buttomIndex])
				{
					topIndex = j;
					switch (j)
					{
					case 0: buttomIndex = 5; break;
					case 1: buttomIndex = 3; break;
					case 2: buttomIndex = 4; break;
					case 3: buttomIndex = 1; break;
					case 4: buttomIndex = 2; break;
					case 5: buttomIndex = 0; break;
					}
					break;
				}
			}
			if (arr[i][topIndex] != 6 && arr[i][buttomIndex] != 6)
			{
				sum += 6;
			}
			else if ((arr[i][topIndex] == 6 && arr[i][buttomIndex] != 5) || (arr[i][topIndex] != 5 && arr[i][buttomIndex] == 6))
			{
				sum += 5;
			}
			else
			{
				sum += 4;
			}
		}
		if (sum > answer)
		{
			answer = sum;
		}
	}
	cout << answer << "\n";
	return 0;
}