#include <iostream>
#include <set>
#include <string>
using namespace std;

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0, -1, 1, 0 };
char** arr;
set<string> s;

void find(int x, int y, string str)
{
	if (str.length() == 6)
	{
		s.insert(str);
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (nextX >= 0 && nextX < 5 && nextY >= 0 && nextY < 5)
			{
				string newStr = str + arr[nextX][nextY];
				find(nextX, nextY, newStr);
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	arr = new char*[5];
	for (int i = 0; i < 5; i++)
	{
		arr[i] = new char[5];
		for (int j = 0; j < 5; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			find(i, j, to_string(arr[i][j] - 48));
		}
	}
	cout << s.size() << "\n";
	return 0;
}