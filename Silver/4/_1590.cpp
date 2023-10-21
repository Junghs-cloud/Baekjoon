#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, T;
	int S, I, C;
	long long currentMin = 1000000000000;
	cin >> N >> T;
	vector<int>* bus = new vector<int>[N];
	for (int i = 0; i < N; i++)
	{
		cin >> S >> I >> C;
		for (int j = 0; j < C; j++)
		{
			bus[i].push_back(S + j * I);
		}
		if (T <= bus[i].at(C - 1))
		{
			int index = lower_bound(bus[i].begin(), bus[i].end(), T) - bus[i].begin();
			if (bus[i].at(index) < currentMin)
			{
				currentMin = bus[i].at(index);
			}
		}
	}
	if (currentMin == 1000000000000)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << currentMin - T << "\n";
	}
	return 0;
}