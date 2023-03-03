#include <iostream>
using namespace std;

struct bomb
{
	bool isSet;
	int time;
};
int R, C, N;
bomb** arr;
int bombTime = 0;

void print()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (arr[i][j].isSet == true)
			{
				cout << "O";
			}
			else
			{
				cout << ".";
			}
		}
		cout << "\n";
	}
}

void explode(int i, int j)
{

	arr[i][j].isSet = false;
	arr[i][j].time = 0;
	if (i > 0 && arr[i - 1][j].time != 3)
	{
		arr[i - 1][j].isSet = false;
		arr[i - 1][j].time = 0;
	}
	if (i < R - 1 && arr[i + 1][j].time != 3)
	{
		arr[i + 1][j].isSet = false;
		arr[i + 1][j].time = 0;
	}
	if (j > 0 && arr[i][j-1].time != 3)
	{
		arr[i][j - 1].isSet = false;
		arr[i][j - 1].time = 0;
	}
	if (j < C - 1 && arr[i][j+1].time != 3)
	{
		arr[i][j + 1].isSet = false;
		arr[i][j + 1].time = 0;
	}
}

void act()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (arr[i][j].isSet == true)
			{
				arr[i][j].time++;
			}
		}
	}
	bombTime++;
	while (bombTime != N )
	{
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (arr[i][j].isSet == false)
				{
					arr[i][j].isSet = true;
					arr[i][j].time = 0;
				}
				else
				{
					arr[i][j].time++;
				}
			}
		}
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (arr[i][j].time == 3)
				{
					explode(i, j);
				}
			}
		}
		bombTime++;
		if (bombTime == N)
		{
			break;
		}
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				arr[i][j].time++;
			}
		}
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (arr[i][j].time == 3)
				{
					explode(i, j);
				}
			}
		}
		bombTime++;
		if (bombTime == N)
		{
			break;
		}
	}
}


int main()
{
	string str;
	cin >> R >> C >> N;
	arr = new bomb* [R];
	for (int i = 0; i < R; i++)
	{
		arr[i] = new bomb[C];
	}
	for (int i = 0; i < R; i++)
	{
		cin >> str;
		for (int j = 0; j < C; j++)
		{
			arr[i][j].time = 0;
			if (str[j] == '.')
			{
				arr[i][j].isSet = false;
			}
			else
			{
				arr[i][j].isSet = true;
			}
		}
	}
	act();
	print();
	return 0;
}