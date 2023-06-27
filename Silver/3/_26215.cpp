#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int height;
	int min = 0;
	bool over24Hours = false;
	priority_queue<int> pq;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> height;
		pq.push(height);
	}
	while (!pq.empty())
	{
		if (pq.size() >= 2)
		{
			int height1 = pq.top();
			pq.pop();
			int height2 = pq.top();
			pq.pop();
			if (height1 > 1)
			{
				pq.push(height1 - 1);
			}
			if (height2 > 1)
			{
				pq.push(height2 - 1);
			}
		}
		else
		{
			int height1 = pq.top();
			pq.pop();
			if (height1 > 1)
			{
				pq.push(height1 - 1);
			}
		}
		min++;
		if (min >= 1441)
		{
			over24Hours = true;
			break;
		}
	}
	if (over24Hours==true)
	{
		cout << "-1" << "\n";
	}
	else
	{
		cout << min << "\n";
	}
	return 0;
}