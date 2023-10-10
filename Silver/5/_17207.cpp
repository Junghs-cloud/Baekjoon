#include <iostream>
#define MAX 1e9;
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int** difficulty = new int*[5];
	int** time = new int* [5];
	int** anticipation = new int*[5];
	for (int i = 0; i < 5; i++)
	{
		difficulty[i] = new int[5];
		time[i] = new int[5];
		anticipation[i] = new int[5];
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> difficulty[i][j];
			anticipation[i][j] = 0;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> time[i][j];
		}
	}
	int min = MAX;
	int index = 0;
	for (int i = 0; i < 5; i++)
	{
		int sum = 0;
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				anticipation[i][j] += difficulty[i][k] * time[k][j];
			}
			sum += anticipation[i][j];
		}
		if (sum <= min)
		{
			index = i;
			min = sum;
		}
	}
	if (index == 0)
	{
		cout << "Inseo" << "\n";
	}
	else if (index == 1)
	{
		cout << "Junsuk" << "\n";
	}
	else if (index == 2)
	{
		cout << "Jungwoo" << "\n";
	}
	else if (index == 3)
	{
		cout << "Jinwoo" << "\n";
	}
	else
	{
		cout << "Youngki" << "\n";
	}
	return 0;
}