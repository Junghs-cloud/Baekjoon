#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int x1, x2, y1, y2;
	cin >> N >> M;
	long long** arr = new long long*[N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		arr[i] = new long long[N + 1];
		if (i != 0)
		{
			arr[i][0] = 0;
			for (int j = 1; j < N + 1; j++)
			{
				cin >> arr[i][j];
			}
		}
		else
		{
			for (int j = 0; j < N + 1; j++)
			{
				arr[i][j]=0;
			}
		}

	}
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			arr[i][j] += arr[i][j - 1];
		}
	}
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			arr[i][j] += arr[i - 1][j];
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cout << arr[x2][y2] - arr[x1 - 1][y2]- arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1] << "\n";
	}
	return 0;
}