#include <iostream>
#define INF 987654321
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	char c;
	cin >> N;
	bool** isFriends = new bool*[N];
	int** distances = new int*[N];
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		distances[i] = new int[N];
		isFriends[i] = new bool[N];
		for (int j = 0; j < N; j++)
		{
			cin >> c;
			if (c == 'Y')
			{
				isFriends[i][j] = true;
				distances[i][j] = 1;
			}
			else
			{
				isFriends[i][j] = false;
				distances[i][j] = INF;
			}
		}
	}
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int k = 0; k < N; k++)
			{
				if (i!=k && isFriends[i][j] == true && isFriends[j][k] == true && distances[i][j] + 1 < distances[i][k])
				{
					distances[i][k] = distances[i][j] + 1;
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		int count = 0;
		for (int j = 0; j < N; j++)
		{
			if (distances[i][j] <= 2)
			{
				count++;
			}
		}
		answer = max(answer, count);
	}
	cout << answer << "\n";
	return 0;
}