#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int start = 0;
	int end = 0;
	cin >> N >> M;
	pair<int, int>* arr = new pair<int, int>[N * M];
	map<int, int> m;
	map<int, int>::iterator it;
	int answer = 1000000000;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[M * i + j].first;
			arr[M * i + j].second = i+1;
		}
	}
	sort(arr, arr + N * M);
	while (end < N * M)
	{
		it = m.find(arr[end].second);
		if (it == m.end())
		{
			m.insert({ arr[end].second, 1 });
		}
		else
		{
			it->second++;
		}
		while (m.size() == N)
		{
			answer = min(answer, arr[end].first - arr[start].first);
			it = m.find(arr[start].second);
			if (it->second == 1)
			{
				m.erase(it);
			}
			else
			{
				it->second--;
			}
			start++;
		}
		end++;
	}
	cout << answer << "\n";
	return 0;
}