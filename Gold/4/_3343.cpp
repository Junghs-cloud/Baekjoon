#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

void swap(long long& x, long long& y)
{
	long long temp = x;
	x = y;
	y = temp;
}

int main()
{
	long long N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	long long minCost = 1000000000000000000;
	if (B * C > A * D)
	{
		swap(A,  C);
		swap(B, D);
	}
	for (int y = 0; y < A; y++)
	{
		long long rest = N - C * y;
		long long minX = ceil((double)rest / (double)A);
		if (minX < 0)
		{
			minX = 0;
			minCost = min(minCost, minX * B + y * D);
			break;
		}
		minCost = min(minCost, minX * B + y * D);
	}
	cout << minCost << "\n";
	return 0;
}