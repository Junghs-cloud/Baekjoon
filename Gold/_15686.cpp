#include <iostream>
#include <vector>

using namespace std;
int N, M;

struct pos
{
	int x;
	int y;
	pos(int a, int b)
	{
		x = a;
		y = b;
	}
};

struct chickenPos
{
	int x;
	int y;
	bool isClosed;
	chickenPos(int a, int b, bool c)
	{
		x = a;
		y = b;
		isClosed = c;
	}
};

vector<pos> homes;
vector<chickenPos> chicken;
long long minChickenDistance = 99999999999999;

void calcChickenDistance()
{
	long long chickenDistance = 0;
	for (int i = 0; i < (signed) homes.size(); i++)
	{
		pos currentHome = homes.at(i);
		long long minDistanceWithNearestChicken = 999999999999;
		for (int j = 0; j < (signed) chicken.size(); j++)
		{
			chickenPos currentChicken = chicken.at(j);
			if (currentChicken.isClosed == false)
			{
				long long distance = (long long)abs(currentHome.x - currentChicken.x) + (long long)abs(currentHome.y - currentChicken.y);
				if (distance < minDistanceWithNearestChicken)
				{
					minDistanceWithNearestChicken = distance;
				}
			}
		}
		chickenDistance += minDistanceWithNearestChicken;
	}
	if (chickenDistance < minChickenDistance)
	{
		minChickenDistance = chickenDistance;
	}
}

void dfs(int depth, int index)
{
	if (depth == M)
	{
		calcChickenDistance();
		return;
	}
	else
	{
		for (int i = index; i < (signed) chicken.size(); i++)
		{
			chicken. at(i).isClosed = false;
			dfs(depth + 1, i + 1);
			chicken.at(i).isClosed = true;
		}
	}
}


int main()
{
	int input;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> input;
			if (input == 1)
			{
				homes.push_back(pos(i, j));
			}
			else if (input == 2)
			{
				chicken.push_back(chickenPos(i, j, true));
			}
		}
	}
	dfs(0, 0);
	cout << minChickenDistance<<"\n";
	return 0;
}