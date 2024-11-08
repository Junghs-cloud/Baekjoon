#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	int** arr = new int*[N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		arr[i] = new int[N+1];
		for (int j = 0; j < N+1; j++)
		{
			arr[i][j] = 1;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		arr[i][0] = 1;
		arr[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			arr[i][j] %= 10007;
		}
	}
	cout << arr[N][K] << "\n";
	return 0;
}