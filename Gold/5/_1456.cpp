#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
bool* isPrime;
vector<long long> primes;
long long A, B;

int getAlmostPrimeCount(long long B, long long prime)
{
	long long N = B;
	int count = 0;
	while (N >= prime)
	{
		N /= prime;
		count++;
	}
	return max(0, count - 1);
}

void getPrimes()
{
	for (long long i = 0; i <= sqrt(B); i++)
	{
		isPrime[i] = true;
	}
	isPrime[0] = false;
	isPrime[1] = false;
	for (long long i = 2; i <= sqrt(B); i++)
	{
		for (long long j = 2 * i; j <= sqrt(B); j += i)
		{
			isPrime[j] = false;
		}
	}
	for (long long i = 2; i <= sqrt(B); i++)
	{
		if (isPrime[i] == true)
		{
			primes.push_back(i);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long answer = 0;
	cin >> A >> B;
	isPrime = new bool[10000001];

	getPrimes();
	for (long long i = 0; i < primes.size(); i++)
	{
		int countToB = getAlmostPrimeCount(B, primes.at(i));
		int countToA = getAlmostPrimeCount(A-1, primes.at(i));
		answer += countToB - countToA;
	}
	cout << answer << "\n";
	return 0;
}