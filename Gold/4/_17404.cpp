#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int** rgb = new int*[N];
	int** sum = new int* [N];
	int answer = 1000000;
	for (int i = 0;  i < N;  i++)
	{
		rgb[i] = new int[3];
		sum[i] = new int[3];
		for (int j = 0; j < 3; j++)
		{
			sum[i][j] = 0;
			cin >> rgb[i][j];
		}
	}
	sum[0][0] = rgb[0][0];
	sum[0][1] = 1000001;
	sum[0][2] = 1000001;
	for (int i = 1; i < N-1; i++)
	{
		sum[i][0] = min(sum[i - 1][1], sum[i - 1][2]) + rgb[i][0];
		sum[i][1] = min(sum[i - 1][0], sum[i - 1][2]) + rgb[i][1];
		sum[i][2] = min(sum[i - 1][0], sum[i - 1][1]) + rgb[i][2];
	}
	sum[N - 1][0] = 1000001;
	sum[N - 1][1] = min(sum[N - 2][0], sum[N - 2][2]) + rgb[N - 1][1];
	sum[N - 1][2] = min(sum[N - 2][0], sum[N - 2][1]) + rgb[N - 1][2];
	for (int i = 0; i < 3; i++)
	{
		if (sum[N - 1][i] < answer)
		{
			answer = sum[N - 1][i];
		}
	}
	sum[0][0] = 1000001;
	sum[0][1] = rgb[0][1];
	sum[0][2] = 1000001;
	for (int i = 1; i < N - 1; i++)
	{
		sum[i][0] = min(sum[i - 1][1], sum[i - 1][2]) + rgb[i][0];
		sum[i][1] = min(sum[i - 1][0], sum[i - 1][2]) + rgb[i][1];
		sum[i][2] = min(sum[i - 1][0], sum[i - 1][1]) + rgb[i][2];
	}
	sum[N - 1][0] = min(sum[N - 2][1], sum[N - 2][2]) + rgb[N - 1][0];
	sum[N - 1][1] = 1000001;
	sum[N - 1][2] = min(sum[N - 2][0], sum[N - 2][1]) + rgb[N - 1][2];
	for (int i = 0; i < 3; i++)
	{
		if (sum[N - 1][i] < answer)
		{
			answer = sum[N - 1][i];
		}
	}
	sum[0][0] = 1000001;
	sum[0][1] = 1000001;
	sum[0][2] = rgb[0][2];
	for (int i = 1; i < N - 1; i++)
	{
		sum[i][0] = min(sum[i - 1][1], sum[i - 1][2]) + rgb[i][0];
		sum[i][1] = min(sum[i - 1][0], sum[i - 1][2]) + rgb[i][1];
		sum[i][2] = min(sum[i - 1][0], sum[i - 1][1]) + rgb[i][2];
	}
	sum[N - 1][0] = min(sum[N - 2][1], sum[N - 2][2]) + rgb[N - 1][0];
	sum[N - 1][1] = min(sum[N - 2][0], sum[N - 2][2]) + rgb[N - 1][1];
	sum[N - 1][2] = 1000001;
	for (int i = 0; i < 3; i++)
	{
		if (sum[N - 1][i] < answer)
		{
			answer = sum[N - 1][i];
		}
	}
	cout << answer << "\n";
	return 0;
}