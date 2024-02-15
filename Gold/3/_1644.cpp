#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	bool* isPrime = new bool[N + 1];
	vector<int> primes;
	int start = 0;
	int end = 0;
	int sum = 0;
	int answerCount = 0;
	for (int i = 0; i < N + 1; i++)
	{
		isPrime[i] = true;
	}
	isPrime[1] = false;
	for (int i = 2; i <= sqrt(N); i++)
	{
		for (int j = 2 * i; j < N + 1; j += i)
		{
			isPrime[j] = false;
		}
	}
	for (int i = 2; i < N + 1; i++)
	{
		if (isPrime[i] == true)
		{
			primes.push_back(i);
		}
	}
	while (start != primes.size())
	{
		if (sum > N)
		{
			sum -= primes.at(start);
			start++;
		}
		else if (sum == N)
		{
			sum -= primes.at(start);
			start++;
			answerCount++;
		}
		else
		{
			if (end == primes.size())
			{
				break;
			}
			sum += primes.at(end);
			end++;
		}
	}
	cout << answerCount << "\n";
	return 0;
}