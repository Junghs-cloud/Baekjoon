#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	bool* prime = new bool[N+1];
	long long* dp = new long long[N + 1];
	vector<int> primes;
	for (int i = 0; i < N + 1; i++)
	{
		prime[i] = true;
		dp[i] = 0;
	}
	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i < N + 1; i++)
	{
		for (int j = 2 * i; j < N + 1; j += i)
		{
			prime[j] = false;
		}
	}

	for (int i = 2; i < N + 1; i++)
	{
		if (prime[i] == true)
		{
			primes.push_back(i);
		}
	}
	dp[0] = 1;
	for (int i = 0; i < primes.size(); i++)
	{
		int currentPrime = primes.at(i);
		for (int j = currentPrime; j < N + 1; j++)
		{
			dp[j] += dp[j - currentPrime] % 123456789;
			dp[j] = dp[j] % 123456789;
		}
	}
	cout << dp[N] << "\n";
	return 0;
}