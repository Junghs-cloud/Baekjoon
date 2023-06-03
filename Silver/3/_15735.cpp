#include <iostream>
using namespace std;

int main()
{
	long long N;
	cin >> N;
	long long* test = new long long[N + 1];
	test[0] = 0;
	test[1] = 1;
	for (long long i = 2; i < N + 1; i++)
	{
		test[i] = test[i - 1] + i;
	}
	long long up = 0;
	for (int i=0; i < N + 1; i++)
	{
		up += test[i];
	}
	long long down = 0;
	for (long long i = N - 1; i >= 0; i-=2)
	{
		down += test[i];
	}
	cout << up + down << "\n";
	return 0;
}