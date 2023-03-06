#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	int* packages;
	int* single;
	int money = 0;
	cin >> N >> M;
	packages = new int[M];
	single = new int[M];
	for (int i = 0; i < M; i++)
	{
		cin >> packages[i] >> single[i];
	}
	sort(packages, packages + M);
	sort(single, single + M);
	if (6 * single[0] <= packages[0])
	{
		money =  N * single[0];
	}
	else
	{
		int money1= 0;
		if (N < 6)
		{
			money = N * single[0];
			money1 = packages[0];
		}
		else
		{
			int maxPackage = N / 6;
			int singleNum = maxPackage * 6;
			money = maxPackage * packages[0] + (N - singleNum)*single[0];
			money1 = (maxPackage + 1) * packages[0];
		}
		money = min(money, money1);
	}
	cout << money<<"\n";
	return 0;
}