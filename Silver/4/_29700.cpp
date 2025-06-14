#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int answer = 0;
	int N, M, K;
	cin >> N >> M >> K;
	char** sits = new char*[N];
	for (int i = 0; i < N; i++)
	{
		sits[i] = new char[M];
		for (int j = 0; j < M; j++)
		{
			cin >> sits[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int start = 0; start < M; start++)
		{
			if (sits[i][start] == '0')
			{
				int continueCount = 0;
				for (int j = start; j < min(start + K, M); j++)
				{
					if (sits[i][j] == '0')
					{
						continueCount++;
					}
					else
					{
						break;
					}
				}
				if (continueCount == K)
				{
					answer++;
				}
			}
		}
	}
	cout << answer << "\n";
	return 0;
}