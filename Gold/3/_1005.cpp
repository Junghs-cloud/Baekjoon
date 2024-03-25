#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	int N, K, W;
	int a, b;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> K;
		long long* buildingTime = new long long[N];
		int* inDegree = new int[N];
		vector<int>* rules = new vector<int>[N];
		long long* totalBuildingTime = new long long[N];
		queue<int> q;
		for (int i = 0; i < N; i++)
		{
			cin >> buildingTime[i];
			inDegree[i] = 0;
			totalBuildingTime[i] = 0;
		}
		for (int i = 0; i < K; i++)
		{
			cin >> a >> b;
			rules[a - 1].push_back(b - 1);
			inDegree[b - 1]++;
		}
		for (int i = 0; i < N; i++)
		{
			if (inDegree[i] == 0)
			{
				q.push(i);
				totalBuildingTime[i] = buildingTime[i];
			}
		}
		while (!q.empty())
		{
			int currentBuilding = q.front();
			for (int i = 0; i < rules[currentBuilding].size(); i++)
			{
				int nextBuilding = rules[currentBuilding].at(i);
				totalBuildingTime[nextBuilding] = max(totalBuildingTime[nextBuilding], totalBuildingTime[currentBuilding]);
				inDegree[nextBuilding]--;
				if (inDegree[nextBuilding] == 0)
				{
					q.push(nextBuilding);
					totalBuildingTime[nextBuilding] += buildingTime[nextBuilding];
				}
			}
			q.pop();
		}
		cin >> W;
		cout << totalBuildingTime[W - 1] << "\n";
	}
	return 0;
}