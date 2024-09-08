#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	bool* isPrime = new bool[1000001];
	set<int> primes;
	for (int i = 0; i < 1000001; i++)
	{
		isPrime[i] = true;
	}
	isPrime[1] = false;
	for (int i = 2; i <= sqrt(1000000); i++)
	{
		for (int j = 2 * i; j < 1000000; j += i)
		{
			isPrime[j] = false;
		}
	}
	for (int i = 2; i <= 1000000; i++)
	{
		if (isPrime[i] == true)
		{
			primes.insert(i);
		}
	}
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N;
		int count = 0;
		cin >> N;
		for (set<int>::iterator it = primes.begin(); it != primes.end(); it++)
		{
			if (*it > N / 2)
			{
				break;
			}
			if (primes.find(N - *it) != primes.end())
			{
				count++;
			}
		}
		cout << count << "\n";
	}
	return 0;
}