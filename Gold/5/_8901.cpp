#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int A, B, C;
		int costAB, costBC, costCA;
		long long maxCost = 0;
		int currentSelectCost = 0;
		cin >> A >> B >> C;
		cin >> costAB >> costBC >> costCA;
		for (int i = 0; i <= min(A, B); i++)
		{
			currentSelectCost = costAB * i;
			int leftA = A - i;
			int leftB = B - i;
			for (int j = 0; j <= min(leftB, C); j++)
			{
				currentSelectCost += costBC * j;
				int leftC = C - j;
				currentSelectCost += costCA * min(leftC, leftA);
				if (currentSelectCost > maxCost)
				{
					maxCost = currentSelectCost;
				}
				currentSelectCost -= costCA * min(leftC, leftA);
				currentSelectCost -= costBC * j;
			}
		}
		cout << maxCost << "\n";
	}
	return 0;
}