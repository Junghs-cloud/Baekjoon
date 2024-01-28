#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int start, end;
	cin >> N;
	vector<pair<int, int>> classes;
	priority_queue<int, vector<int>, greater<int>> pq;
	int answer = 1;
	for (int i = 0; i < N; i++)
	{
		cin >> start >> end;
		classes.push_back(make_pair(start, end));
	}
	sort(classes.begin(), classes.end());
	for (int i = 0; i < N; i++)
	{
		if (pq.empty())
		{
			pq.push(classes.at(i).second);
		}
		else
		{
			if (pq.top() <= classes.at(i).first)
			{
				pq.pop();
				pq.push(classes.at(i).second);
			}
			else
			{
				pq.push(classes.at(i).second);
				answer++;
			}
		}
	}
	cout << answer << "\n";
	return 0;
}