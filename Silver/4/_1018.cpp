#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N>>M;
	char** arr = new char* [N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new char[M];
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	int answer = 65;
	for (int startX = 0; startX <= N - 8; startX++)
	{
		for (int startY = 0; startY <= M - 8; startY++)
		{
			char start = arr[startX][startY];
			int coloring = 0;
			for (int i = startX ; i <startX +  8; i++)
			{
				for (int j = startY; j< startY + 8; j++)
				{
					
					if ((i - startX) % 2 == 0 && (j - startY) % 2 == 0)
					{
						if (arr[i][j] != start)
						{
							coloring++;
						}
					}
					else if ((i - startX) % 2 == 0 && (j - startY) % 2 == 1)
					{
						if (arr[i][j] == start)
						{
							coloring++;
						}
					}
					else if ((i - startX) % 2 == 1 && (j - startY) % 2 == 0)
					{
						if (arr[i][j] == start)
						{
							coloring++;
						}
					}
					else
					{
						if (arr[i][j] != start)
						{
							coloring++;
						}
					}
				}
			}

			if (coloring > 32)
			{
				coloring = 64 - coloring;
			}
			if (coloring < answer)
			{
				answer = coloring;
			}
		}
	}
	cout << answer << "\n";
	return 0;
}