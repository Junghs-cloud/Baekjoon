#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct robot
{
	int num;
	double sec;
	robot(int a, double b)
	{
		num = a;
		sec = b;
	}
};

bool compare(const robot& r1, const robot& r2)
{
	if (r1.sec < r2.sec)
	{
		return true;
	}
	else if (r1.sec == r2.sec)
	{
		return r1.num < r2.num;
	}
	else
	{
		return false;
	}
}

bool compare2(const robot& r1, const robot& r2)
{
	if (r1.num < r2.num)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<robot> robots;
	int N;
	double x, y, v;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y >> v;
		double distance = x * x + y * y;
		distance = sqrt(distance);
		distance = distance / v;
		robots.push_back(robot(i + 1, distance));
	}
	sort(robots.begin(), robots.end(), compare);
	for (int i = 0; i < (signed) robots.size(); i++)
	{
		cout << robots.at(i).num << "\n";
	}
	return 0;
}