#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int R, C, Q;
	int r1, c1, r2, c2;
	cin >> R >> C >> Q;
	int** photo = new int*[R];
	long long** sums = new long long*[R+1];
	for (int i = 0; i < R + 1; i++)
	{
		sums[i] = new long long[C + 1];
		for (int j = 0; j < C+1; j++)
		{
			sums[i][j] = 0;
		}
	}
	for (int i = 0; i < R; i++)
	{
		photo[i] = new int[C];
		for (int j = 0; j < C; j++)
		{
			cin >> photo[i][j];
		}
	}
	sums[1][1] = photo[0][0];
	for (int i = 1; i < R+1; i++)
	{
		sums[i][1] = sums[i - 1][1] + photo[i-1][0];
	}
	for (int j = 1; j < C+1; j++)
	{
		sums[1][j] = sums[1][j - 1] + photo[0][j-1];
	}
	for (int i = 2; i < R+1; i++)
	{
		for (int j = 2; j < C+1; j++)
		{
			sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1] + photo[i-1][j-1];
		}
	}
	for (int i = 0; i < Q; i++)
	{
		cin >> r1 >> c1 >> r2 >> c2;
		int pixelCount = (r2 - r1 + 1) * (c2 - c1+1);
		long long sum = sums[r2][c2] - sums[r2][c1 - 1] - sums[r1 - 1][c2] + sums[r1 - 1][c1 - 1];
		cout <<sum / pixelCount<<"\n";
	}
	return 0;
}