#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N>>M;
	char** map = new char*[N];
	int** answer = new int*[N];
	vector<pair<int, int>> clouds;
	for (int i = 0; i < N; i++)
	{
		map[i] = new char[M];
		answer[i] = new int[M];
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'c')
			{
				clouds.push_back(pair(i, j));
			}
			answer[i][j] = -1;
		}
	}
	for (int i = 0; i < clouds.size(); i++)
	{
		int posX = clouds[i].first;
		int posY = clouds[i].second;
		for (int j = posY; j < M; j++)
		{
			answer[posX][j] = j - posY;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}