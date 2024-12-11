#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	bool* isPrime = new bool[1000001];
	vector<int> primes;
	for (int i = 0; i < 1000001; i++)
	{
		isPrime[i] = true;
	}
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i <= sqrt(1000000); i++)
	{
		for (int j = 2 * i; j < 1000001; j += i)
		{
			isPrime[j] = false;
		}
	}
	for (int i = 3; i < 1000001; i+=2)
	{
		if (isPrime[i] == true)
		{
			primes.push_back(i);
		}
	}
	int N;
	while (true)
	{
		cin >> N;
		bool canMake = false;
		if (N == 0)
		{
			break;
		}
		for (int i = 0; i < primes.size(); i++)
		{
			int left = N - primes.at(i);
			if (left < 0)
			{
				break;
			}
			if (isPrime[left] == true)
			{
				cout << N << " = " << primes.at(i) << " + " << left << "\n";
				canMake = true;
				break;
			}
		}
		if (canMake == false)
		{
			cout << "Goldbach's conjecture is wrong.\n";
		}
	}

	return 0;
}