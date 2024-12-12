#include <iostream>
using namespace std;

long long fac(int N)
{
	if (N <= 1)
	{
		return 1;
	}
	else return N * fac(N - 1);
}

int main()
{
	int N;
	cin >> N;
	cout << fac(N);
	return 0;
}