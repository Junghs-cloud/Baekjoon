#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct conf
{
	int startTime;
	int endTime;
	conf(int a, int b)
	{
		startTime = a;
		endTime = b;
	}
};



bool compare(const conf& c1, const conf& c2)
{
	if (c1.startTime < c2.startTime)
	{
		return true;
	}
	else if (c1.startTime == c2.startTime)
	{
		return c1.endTime < c2.endTime;
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

	int N;
	int num, start, end;
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<conf> v;
	cin >> N;
	int minConference = 1;
	for (int i = 0; i < N; i++)
	{
		cin >> num >> start >> end;
		v.push_back(conf(start, end));
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < N; i++)
	{
		if (pq.empty())
		{
			pq.push(v.at(i).endTime);
		}
		else
		{
			if (v.at(i).startTime < pq.top())
			{
				minConference++;
			}
			else
			{
				pq.pop();
			}
			pq.push(v.at(i).endTime);
		}
	}
	cout << minConference << "\n";
	return 0;
}