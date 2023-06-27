#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct usingTime
{
	int start;
	int end;
	usingTime(int a, int b)
	{
		start = a;
		end = b;
	}
};

vector<usingTime> table;

bool compare(const usingTime& t1, const usingTime& t2)
{
	if (t1.end < t2.end)
	{
		return true;
	}
	else if (t1.end == t2.end)
	{
		return t1.start < t2.start;
	}
	else
	{
		return false;
	}
}

int main()
{
	int N;
	int start, end;
	int maxConference = 1;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> start >> end;
		table.push_back(usingTime(start, end));
	}
	sort(table.begin(), table.end(), compare);
	int endTime = table.at(0).end;
	for (int i = 1; i < (signed) table.size(); i++)
	{
		if (table.at(i).start >= endTime)
		{
			maxConference++;
			endTime = table.at(i).end;
		}
	}
	cout << maxConference << "\n";
	return 0;
}