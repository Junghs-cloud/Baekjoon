#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;
		long long** arr = new long long* [N];
		for (int i = 0; i < N; i++)
		{
			arr[i] = new long long[10];
		}
		arr[0][1] = 1;
		arr[0][2] = 1;
		arr[0][3] = 1;
		arr[0][4] = 1;
		arr[0][5] = 1;
		arr[0][6] = 1;
		arr[0][7] = 1;
		arr[0][8] = 1;
		arr[0][9] = 1;
		arr[0][0] = 1;
		for (int i = 1; i < N; i++)
		{
			arr[i][1] = arr[i - 1][2] % 1234567 + arr[i - 1][4] % 1234567;
			arr[i][2] = arr[i - 1][1] % 1234567 + arr[i - 1][3] % 1234567 + arr[i - 1][5] % 1234567;
			arr[i][3] = arr[i - 1][2] % 1234567 + arr[i - 1][6] % 1234567;
			arr[i][4] = arr[i - 1][1] % 1234567 + arr[i - 1][5] % 1234567 + arr[i - 1][7] % 1234567;
			arr[i][5] = arr[i - 1][2] % 1234567 + arr[i - 1][4] % 1234567 + arr[i - 1][6] % 1234567 + arr[i - 1][8] % 1234567;
			arr[i][6] = arr[i - 1][3] % 1234567 + arr[i - 1][5] % 1234567 + arr[i - 1][9] % 1234567;
			arr[i][7] = arr[i - 1][4] % 1234567 + arr[i - 1][8] % 1234567 + arr[i - 1][0] % 1234567;
			arr[i][8] = arr[i - 1][5] % 1234567 + arr[i - 1][7] % 1234567 + arr[i - 1][9] % 1234567;
			arr[i][9] = arr[i - 1][6] % 1234567 + arr[i - 1][8] % 1234567;
			arr[i][0] = arr[i - 1][7];
			for (int j = 0; j < 10; j++)
			{
				arr[i][j] = arr[i][j] % 1234567;
			}
		}
		long long answer = 0;
		for (int i = 0; i < 10; i++)
		{
			answer += (arr[N - 1][i] % 1234567);
		}
		cout << answer % 1234567 << "\n";
	}
	return 0;
}