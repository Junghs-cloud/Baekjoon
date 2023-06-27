#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct cow
{
	int start;
	int duration;
	cow(int a, int b)
	{
		start = a;
		duration = b;
	}
};

bool compare(const cow& c1, const cow& c2)
{
	if (c1.start < c2.start)
	{
		return true;
	}
	else if (c1.start == c2.start)
	{
		return c1.duration < c2.duration;
	}
	else
	{
		return false;
	}
}

int main()
{
	int N;
	int arrival;
	int duration;
	vector<cow> cows;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arrival >> duration;
		cows.push_back(cow(arrival, duration));
	}
	sort(cows.begin(), cows.end(), compare);
	int sum = 0;
	for (int i = 0; i < (signed) cows.size(); i++)
	{
		if (sum < cows.at(i).start)
		{
			sum = cows.at(i).start;
		}
		sum += cows.at(i).duration;
	}
	cout << sum << "\n";
	return 0;
}