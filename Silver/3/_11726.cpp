#include <iostream>
using namespace std;

int main()
{
	int sum = 0;
	int N;
	cin >> N;
	int** nCr = new int*[N + 2];
	for (int i = 0; i < N + 2; i++)
	{
		nCr[i] = new int[N + 2];
		for (int j = 0; j < N + 2; j++)
		{
			nCr[i][j] = 0;
		}
	}
	nCr[0][0] = 1;
	for (int i = 1; i < N + 2; i++)
	{
		nCr[i][1] = 1;
		nCr[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % 10007;
		}
	}
	int oneCount = N;
	int twoCount = 0;
	while (twoCount <= N / 2)
	{
		int n = oneCount + twoCount;
		int r = oneCount;
		sum += nCr[n + 1][r + 1];
		oneCount -= 2;
		twoCount++;
	}
	cout << sum % 10007 << "\n";
	return 0;
}