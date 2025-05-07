#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, weight;
	int time = 0;
	cin >> N;
	int* cranes = new int[N];
	vector<int> boxes;
	for (int i = 0; i < N; i++)
	{
		cin >> cranes[i];
	}
	sort(cranes, cranes + N, greater());
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> weight;
		boxes.push_back(weight);
	}
	sort(boxes.begin(), boxes.end());
	if (cranes[0] < boxes.back())
	{
		cout << -1 << "\n";
	}
	else
	{
		while (true)
		{
			time++;
			for (int i = 0; i < N; i++)
			{
				int index = upper_bound(boxes.begin(), boxes.end(), cranes[i]) - boxes.begin() - 1;
				if (index >= 0)
				{
					boxes.erase(boxes.begin() + index);
				}
			}
			if (boxes.size() == 0)
			{
				break;
			}
		}
		cout << time << "\n";
	}
	return 0;
}