#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
set<int> clockNums;

int calc(int a, int b, int c, int d)
{
	return a * 1000 + b * 100 + c * 10 + d;
}

int getClockNum(int a, int b, int c, int d)
{
	int A = calc(a, b, c, d);
	int B = calc(b, c, d, a);
	int C = calc(c, d, a, b);
	int D = calc(d, a, b, c);
	return min({ A, B, C, D });
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b, c, d;
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			for (int k = 1; k <= 9; k++)
			{
				for (int l = 1; l <= 9; l++)
				{
					clockNums.insert(getClockNum(i, j, k, l));
				}
			}
		}
	}
	cin >> a >> b >> c >> d;
	int findClockNum = getClockNum(a, b, c, d);
	int index = distance(clockNums.begin(), lower_bound(clockNums.begin(), clockNums.end(), findClockNum));
	cout << index+1 << "\n";
	return 0;
}