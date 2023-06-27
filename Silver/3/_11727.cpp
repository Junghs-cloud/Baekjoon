#include <iostream>
using namespace std;

int main()
{
	int N;
	int sum = 0;
	int twoSum = 0;
	cin >> N;
	int** nCr = new int*[N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		nCr[i] = new int[N + 1];
	}
	nCr[0][0] = 0;
	for (int i = 1; i < N + 1; i++)
	{
		nCr[i][0] = 1;
		nCr[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			nCr[i][j] = (nCr[i - 1][j - 1] % 10007) + (nCr[i-1][j] % 10007);
		}
	}
	int oneCount = N;
	int twoCount = 0;
	while (twoCount <= N / 2)
	{
		int n = oneCount + twoCount;
		int r = oneCount;
		int twoA = twoCount;
		int twoB = 0;
		twoSum = 0;
		if (twoCount != 0)
		{
			while (twoB <= twoCount)
			{
				twoSum = (twoSum % 10007) + (nCr[twoCount][twoA] % 10007);
				twoA--;
				twoB++;
			}
			sum = sum + (twoSum * nCr[n][r]) % 10007;
			sum = sum % 10007;
		}
		else
		{
			sum = (sum % 10007) + (nCr[n][r] % 10007);
		}
		oneCount -= 2;
		twoCount++;
	}
	cout << sum % 10007 << "\n";
	return 0;
}