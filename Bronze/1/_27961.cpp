#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long catCount = 0;
	int magicCount = 0;
	long long N;
	cin >> N;
	if (N != 0)
	{
		catCount++;
		magicCount++;
		while (N != catCount)
		{
			if (2 * catCount <= N)
			{
				catCount *= 2;
				magicCount++;
			}
			else
			{
				catCount += N - catCount;
				magicCount++;
			}
		}
	}
	cout << magicCount << "\n";
	return 0;
}