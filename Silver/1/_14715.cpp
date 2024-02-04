#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int N;

int divide(int N, int slimeCount)
{
	int a = 0;
	int b = 0;
	int smallestSlimeCount = 987654321;
	bool canDivide = false;
	for (int i = 2; i <= sqrt(N); i++)
	{
		if (N % i == 0)
		{
			int Q = N / i;
			a = divide(i, slimeCount + 1);
			b = divide(Q, slimeCount + 1);
			canDivide = true;
			if (max(a, b) < smallestSlimeCount)
			{
				smallestSlimeCount = max(a, b);
			}
		}
	}
	if (canDivide == false)
	{
		return slimeCount;
	}
	else
	{
		return smallestSlimeCount;
	}
}

int main()
{
	cin >> N;
	cout<<divide(N, 0)<<"\n";
	return 0;
}