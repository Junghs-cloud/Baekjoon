#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int a, b, c;
	cin >> N;
	int** minData = new int* [2];
	int** maxData = new int*[2];
	for (int i = 0; i < 2; i++)
	{
		minData[i] = new int[3];
		maxData[i] = new int[3];
		for (int j = 0; j < 3; j++)
		{
			minData[i][j] = 0;
			maxData[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c;
		if (i == 0)
		{
			maxData[1][0] = a;
			maxData[1][1] = b;
			maxData[1][2] = c;

			minData[1][0] = a;
			minData[1][1] = b;
			minData[1][2] = c;
		}
		else
		{
			maxData[1][0] = a + max(maxData[0][0], maxData[0][1]);
			maxData[1][1] = b + max(maxData[0][2], max(maxData[0][0], maxData[0][1]));
			maxData[1][2] = c + max(maxData[0][1], maxData[0][2]);

			minData[1][0] = a + min(minData[0][0], minData[0][1]);
			minData[1][1] = b + min(minData[0][2], min(minData[0][0], minData[0][1]));
			minData[1][2] = c + min(minData[0][1], minData[0][2]);
		}
		for (int i = 0; i < 3; i++)
		{
			maxData[0][i] = maxData[1][i];
			minData[0][i] = minData[1][i];
		}
	}
	cout << max(max(maxData[1][0], maxData[1][1]), maxData[1][2])<<" "<< min(min(minData[1][0], minData[1][1]), minData[1][2]) << "\n";
	return 0;
}