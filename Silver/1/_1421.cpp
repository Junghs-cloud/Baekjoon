#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, C, W;
	int num;
	int cutCount = 0;
	int treeCount = 0;
	long long current = 0;
	long long maxCost = 0;
	cin >> N >> C >> W;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int length = 1; length <= v.at(N - 1); length++)
	{
		current = 0;
		for (int j = 0; j < N; j++)
		{
			cutCount = 0;
			treeCount = 0;
			if (v.at(j) >= length)
			{
				if (v.at(j) % length == 0)
				{
					cutCount = v.at(j) / length - 1;
				}
				else
				{
					cutCount = v.at(j) / length;
				}
				treeCount = v.at(j) / length;
				if (treeCount * length * W - cutCount * C > 0)
				{
					current += treeCount * length * W - cutCount * C;
				}
			}
		}
		if (current > maxCost)
		{
			maxCost = current;
		}
	}
	cout << maxCost << "\n";
	return 0;
}