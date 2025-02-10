#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	pair<int, int>* athlethes = new pair<int, int>[N];
	vector<pair<int, int>> answer;
	for (int i = 0; i < N; i++)
	{
		cin >> athlethes[i].first >> athlethes[i].second;
		answer.push_back(pair(0, i));
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			int A = athlethes[i].first + athlethes[j].first * athlethes[i].second;
			int B = athlethes[j].first + athlethes[i].first * athlethes[j].second;
			if (A > B)
			{
				answer.at(i).first++;
			}
			else
			{
				answer.at(j).first++;
			}
		}
	}
	sort(answer.begin(), answer.end(), greater<pair<int, int>>());
	for (int i = 0; i < N; i++)
	{
		cout << answer.at(i).second + 1 << "\n";
	}
	return 0;
}