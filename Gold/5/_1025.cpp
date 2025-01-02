#include <iostream>
#include <string>
#include <cmath>
using namespace std;
char** arr;
bool** isVisited;

int N, M;
int answer = -1;

void find(int startRow, int startCol, int rowD, int colD)
{
	string str = "";
	int i = startRow;
	int j = startCol;
	while (true)
	{
		if (i >= 0 && i < N && j >= 0 && j < M)
		{
			if (isVisited[i][j] == false)
			{
				str += arr[i][j];
				isVisited[i][j] = true;
				i += rowD;
				j += colD;
			}
			else
			{
				return;
			}
		}
		else
		{
			break;
		}
	}
	for (int i = 1; i <= str.length(); i++)
	{
		int num = stoi(str.substr(0, i));
		int sqrtNum = sqrt(num);
		if (sqrtNum * sqrtNum == num)
		{
			answer = max(answer, num);
		}
	}
}

void reset()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			isVisited[i][j] = false;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	arr = new char* [N];
	isVisited = new bool*[N];
	for (int i = 0; i < N; i++)
	{
		isVisited[i] = new bool[M];
		arr[i] = new char[M];
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			isVisited[i][j] = false;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int rowD = -N; rowD <= N; rowD++)
			{
				for (int colD = -M; colD <= M; colD++)
				{
					reset();
					find(i, j, rowD, colD);
				}
			}
		}
	}
	cout << answer << "\n";
	return 0;
}