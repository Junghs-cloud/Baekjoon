#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, num;
	bool isFind = false;
	cin >> N>> num;
	int* dp = new int[N];
	int phase = N / 2;
	if (N % 2 == 0)
	{
		phase--;
	}
	phase = pow(phase, 2);
	int maxSecondNum = num / phase;
	for (int A = 1; A <= maxSecondNum; A++)
	{
		if (isFind == true)
		{
			break;
		}
		for (int B = A; B <= maxSecondNum; B++)
		{
			dp[0] = A;
			dp[1] = B;
			for (int i = 2; i < N; i++)
			{
				dp[i] = dp[i - 2] + dp[i - 1];
			}
			if (dp[N - 1] == num)
			{
				isFind = true;
				cout << A << "\n";
				cout << B << "\n";
				break;
			}
		}
	}

	return 0;
}