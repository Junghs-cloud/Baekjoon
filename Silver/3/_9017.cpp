#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N;
		int team;
		cin >> N;
		int* arr = new int[N];
		int* teamMembers = new int[201];
		vector<int>* teams = new vector<int>[201];
		int minSum = 987654321;
		int answer = 0;
		int point = 1;
		for (int i = 0; i < 201; i++)
		{
			teamMembers[i] = 0;
		}
		for (int i = 0; i < N; i++)
		{
			cin >> team;
			teamMembers[team]++;
			arr[i] = team;
		}
		for (int i = 0; i < N; i++)
		{
			team = arr[i];
			if (teamMembers[team] == 6)
			{
				teams[team].push_back(point);
				point++;
			}
		}
		for (int i = 1; i < 201; i++)
		{
			int sum = 0;
			if (teams[i].size() == 6)
			{
				for (int j = 0; j < 4; j++)
				{
					sum += teams[i].at(j);
				}
				if (sum < minSum)
				{
					minSum = sum;
					answer = i;
				}
				else if (sum == minSum)
				{
					if (teams[i].at(4) < teams[answer].at(4))
					{
						answer = i;
					}
				}
			}
		}
		cout << answer << "\n";
	}
	return 0;
}