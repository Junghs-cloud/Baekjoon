#include <iostream>
#include <map>
#include <utility>
using namespace std;
char** arr;
int N, M, K;
string findString;
long long answer = 0;
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void backTracking(int depth, int currentX, int currentY)
{
	if (depth == findString.length()-1)
	{
		answer++;
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			int nextX = currentX + dx[i];
			int nextY = currentY + dy[i];
			if (nextX == -1)
			{
				nextX = N - 1;
			}
			if (nextX == N)
			{
				nextX = 0;
			}
			if (nextY == -1)
			{
				nextY = M - 1;
			}
			if (nextY == M)
			{
				nextY = 0;
			}
			if (arr[nextX][nextY] == findString.at(depth + 1))
			{
				backTracking(depth + 1, nextX, nextY);
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> N >> M>>K;
	arr = new char*[N];
	map<string, long long> m;
	map<string, long long>::iterator it;
	for (int i = 0; i < N; i++)
	{
		arr[i] = new char[M];
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = str.at(j);
		}
	}
	for (int k = 0; k < K; k++)
	{
		answer = 0;
		cin >> findString;
		it = m.find(findString);
		if (it == m.end())
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					if (arr[i][j] == findString.at(0))
					{
						backTracking(0, i, j);
					}
				}
			}
			m.insert({ findString, answer });
			cout << answer << "\n";
		}
		else
		{
			cout << it->second << "\n";
		}
	}
	return 0;
}