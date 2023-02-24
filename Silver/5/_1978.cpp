#include <iostream>
using namespace std;

int main()
{
	int N;
	int num;
	int arr[1001];
	bool isPrime[1001];
	int primeCount = 0;
	cin >> N;
	for (int i = 0; i < 1001; i++)
	{
		arr[i] = i;
		isPrime[i] = true;
	}
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i < 1001; i++)
	{
		if (isPrime[i] == true)
		{
			for (int j = 2*i; j < 1001; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (isPrime[num] == true)
		{
			primeCount++;
		}
	}
	cout << primeCount << "\n";
	return 0;
}