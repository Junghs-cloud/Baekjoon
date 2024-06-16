#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

bool cmp(pair<int, int>& p1, pair<int, int>& p2)
{
	if (p1.second < p2.second)
	{
		return true;
	}
	else if (p1.second == p2.second)
	{
		return p1.first < p2.first;
	}
	else
	{
		return false;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, T;
	bool* canGive = new bool[1001];
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int answer = 0;
		cin >> N >> M;
		pair<int, int>* arr = new pair<int, int>[M];
		for (int i = 0; i < M; i++)
		{
			cin >> arr[i].first >> arr[i].second;
		}
		for (int i = 0; i < 1001; i++)
		{
			canGive[i] = false;
		}
		sort(arr, arr + M, cmp);
		for (int i = 0; i < M; i++)
		{
			for (int j = arr[i].first; j <= arr[i].second; j++)
			{
				if (canGive[j] == false)
				{
					canGive[j] = true;
					answer++;
					break;
				}
			}
		}
		cout << answer << "\n";
	}
	return 0;
}