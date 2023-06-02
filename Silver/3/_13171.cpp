#include <iostream>
using namespace std;

int main()
{
	long long N;
	long long x;
	cin >> N>>x;
	long long AX = 1;
	N = N % 1000000007;
	while (x > 0)
	{
		if ((x & 1) == 1)
		{
			AX = AX * N % 1000000007;
			AX = AX % 1000000007;
		}
		x = (x >> 1);
		N =  N * N % 1000000007;
	}
	cout << AX<<"\n";
	return 0;
}