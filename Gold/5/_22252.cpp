#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int num;
	string name;
	int k, information;
	map<string, priority_queue<int>> m;
	map<string, priority_queue<int>>::iterator it;
	long long answer = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> num >> name;
		if (num == 1)
		{
			it = m.find(name);
			if (it == m.end())
			{
				cin >> k;
				priority_queue<int> pq;
				for (int j = 0; j < k; j++)
				{
					cin >> information;
					pq.push(information);
				}
				m.insert({ name, pq });
			}
			else
			{
				cin >> k;
				for (int j = 0; j < k; j++)
				{
					cin >> information;
					it->second.push(information);
				}
			}
		}
		else
		{
			it = m.find(name);
			if (it == m.end())
			{
				cin >> k;
			}
			else
			{
				cin >> k;
				int transCount = 0;
				while (!it->second.empty())
				{
					answer += (long long) (it->second.top());
					it->second.pop();
					transCount++;
					if (transCount == k)
					{
						break;
					}
				}
			}
		}
	}
	cout << answer << "\n";
	return 0;
}