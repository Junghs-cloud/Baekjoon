#include <iostream>
using namespace std;
int** arr;
int N, nextUse;
bool isChanged;

void checkGaro(int i)
{
	int on = 0;
	int off = 0;
	for (int j = 0; j < N; j++)
	{
		if (arr[i][j] == 1)
		{
			on++;
		}
		else
		{
			off++;
		}
	}
	if (nextUse == 1 && on > off)
	{
		if (on == N)
		{
			return;
		}
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = 1;
		}
		isChanged = true;
	}
	if (nextUse == 0 && on < off)
	{
		if (off == N)
		{
			return;
		}
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = 0;
		}
		isChanged = true;
	}
}

void checkSero(int i)
{
	int on = 0;
	int off = 0;
	for (int j = 0; j < N; j++)
	{
		if (arr[j][i] == 1)
		{
			on++;
		}
		else
		{
			off++;
		}
	}
	if (nextUse == 1 && on > off)
	{
		if (on == N)
		{
			return;
		}
		for (int j = 0; j < N; j++)
		{
			arr[j][i] = 1;
		}
		isChanged = true;
	}
	if (nextUse == 0 && on < off)
	{
		if (off == N)
		{
			return;
		}
		for (int j = 0; j < N; j++)
		{
			arr[j][i] = 0;
		}
		isChanged = true;
	}
}

bool checkAllSame()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] != nextUse)
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> nextUse;
	arr = new int*[N];
	bool canMake = false;
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	while (true)
	{
		isChanged = false;
		for (int i = 0; i < N; i++)
		{
			checkGaro(i);
		}
		for (int i = 0; i < N; i++)
		{
			checkSero(i);
		}
		if (checkAllSame() == true)
		{
			canMake = true;
			break;
		}
		if (isChanged == false)
		{
			canMake = false;
			break;
		}
	}
	if (canMake == true)
	{
		cout << "1" << "\n";
	}
	else
	{
		cout << "0" << "\n";
	}
	return 0;
}