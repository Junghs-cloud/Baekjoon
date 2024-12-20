#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
char** arr;
int findCount = 0;
int N;
bool canMake = false;
vector<pair<int, int>> teacherPos;

int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

void checkOnePerson(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int nextX = x + j * dx[i];
			int nextY = y + j * dy[i];
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && arr[nextX][nextY] != 'O')
			{
				if (arr[nextX][nextY] == 'S')
				{
					findCount++;
				}
				continue;
			}
			else
			{
				break;
			}
		}
	}
}

void check()
{
	for (int i = 0; i < teacherPos.size(); i++)
	{
		int x = teacherPos.at(i).first;
		int y = teacherPos.at(i).second;
		checkOnePerson(x, y);
	}
	if (findCount == 0)
	{
		canMake = true;
	}
}

void set(int depth)
{
	if (depth == 3)
	{
		check();
		findCount = 0;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] == 'X')
				{
					arr[i][j] = 'O';
					set(depth + 1);
					arr[i][j] = 'X';
				}
			}
		}
	}

}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	arr = new char*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new char[N];
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'T')
			{
				teacherPos.push_back(pair(i, j));
			}
		}
	}
	set(0);
	if (canMake == true)
	{
		cout << "YES" << "\n";
	}
	else
	{
		cout << "NO" << "\n";
	}
	return 0;
}