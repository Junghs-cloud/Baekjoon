#include <iostream>
using namespace std;
long long* sum;

int getLineNum(int N)
{
	for (int i = 1; i < 100000; i++)
	{
		if (N > sum[i-1] && N <= sum[i])
		{
			return i;
		}
	}
	return 100000;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int current = 1;
	sum = new long long[100000];
	sum[0] = 0;
	for (int i = 1; i < 100000; i++)
	{
		sum[i] = sum[i - 1] + i;
	}
	int lineNum = getLineNum(N);
	if ((lineNum-1) % 2 != 0)
	{
		int bunja = 1;
		int bunmo = lineNum;
		for (int i = sum[lineNum - 1] + 2; i <= N; i++)
		{
			bunja++;
			bunmo--;
		}
		cout << bunja << "/" << bunmo << "\n";
	}
	else
	{
		int bunja = lineNum;
		int bunmo = 1;
		for (int i = sum[lineNum - 1] + 2; i <= N; i++)
		{
			bunja--;
			bunmo++;
		}
		cout << bunja << "/" << bunmo << "\n";
	}
	return 0;
}