#include <iostream>
#include <queue>
#include <climits>
#include <tuple>
using namespace std;
int N;
int** arr;
int** answer;
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>> pq;

void dijkstra()
{
	pq.push(tuple(0, 0, arr[0][0]));
	while (!pq.empty())
	{
		tuple<int, int, int> current = pq.top();
		pq.pop();
		int x = get<0>(current);
		int y = get<1>(current);
		int currentRupee = get<2>(current);
		if (currentRupee > answer[x][y])
		{
			continue;
		}
		for (int i = 0; i < 4; i++)
		{
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N)
			{
				int nextRupee = currentRupee + arr[nextX][nextY];
				if ( nextRupee < answer[nextX][nextY])
				{
					answer[nextX][nextY] = nextRupee;
					pq.push(tuple(nextX, nextY, nextRupee));
				}
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int testCase = 1;
	while (true)
	{
		cin >> N;
		if (N == 0)
		{
			break;
		}
		arr = new int* [N];
		answer = new int* [N];
		for (int i = 0; i < N; i++)
		{
			arr[i] = new int[N];
			answer[i] = new int[N];
			for (int j = 0; j < N; j++)
			{
				answer[i][j] = INT_MAX;
				cin >> arr[i][j];
			}
		}
		dijkstra();
		cout<<"Problem " << testCase << ": " << answer[N - 1][N - 1] << "\n";
		testCase++;
	}
	return 0;
}