#include <iostream>
using namespace std;
int** paper;
int minusOne = 0;
int zero = 0;
int plusOne = 0;

void check(int x, int y, int length)
{
	int nextLength = length / 3;
	int sample = paper[x][y];
	bool isAllSame = true;
	for (int i = x; i < x + length; i++)
	{
		for (int j = y; j < y + length; j++)
		{
			if (paper[i][j] != sample)
			{
				isAllSame = false;
				break;
			}
		}
	}
	if (isAllSame == false)
	{
		check(x, y, nextLength);
		check(x, y + nextLength, nextLength);
		check(x, y + 2 * nextLength, nextLength);
		check(x + nextLength, y, nextLength);
		check(x + nextLength, y + nextLength, nextLength);
		check(x + nextLength, y + 2 * nextLength, nextLength);
		check(x + 2 * nextLength, y, nextLength);
		check(x + 2 * nextLength, y + nextLength, nextLength);
		check(x + 2 * nextLength, y + 2 * nextLength, nextLength);
	}
	else
	{
		if (sample == -1)
		{
			minusOne++;
		}
		else if (sample == 0)
		{
			zero++;
		}
		else
		{
			plusOne++;
		}
	}
}

int main()
{
	int N;
	cin >> N;
	paper = new int*[N];
	for (int i = 0; i < N; i++)
	{
		paper[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			cin >> paper[i][j];
		}
	}
	check(0, 0, N);
	cout << minusOne << "\n";
	cout << zero << "\n";
	cout << plusOne << "\n";
	return 0;
}