#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, S, M;
	cin >> N >> S >> M;
	int* v = new int[N];
	bool** volumes = new bool*[N+1];
	int answer = -1;
	for (int i = 0; i < N + 1; i++)
	{
		volumes[i] = new bool[M + 1];
		for (int j = 0; j < M + 1; j++)
		{
			volumes[i][j] = false;
		}
	}
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	volumes[0][S] = true;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M+1; j++)
		{
			if (volumes[i][j]==true && j + v[i] <= M)
			{
				volumes[i+1][j + v[i]] = true;
			}
			if (volumes[i][j] == true && j - v[i] >= 0)
			{
				volumes[i+1][j - v[i]] = true;
			}
		}
	}
	for (int i = 0; i < M + 1; i++)
	{
		if (volumes[N][i] == true)
		{
			answer = i;
		}
	}
	cout << answer << "\n";
	return 0;
}