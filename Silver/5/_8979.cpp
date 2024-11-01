#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct country
{
	int countryNum;
	int gold;
	int silver;
	int bronze;
	country(int a, int b, int c, int d)
	{
		countryNum = a;
		gold = b;
		silver = c;
		bronze = d;
	}
};

bool cmp(country& c1, country& c2)
{
	if (c1.gold > c2.gold)
	{
		return true;
	}
	else if (c1.gold == c2.gold)
	{
		if (c1.silver > c2.silver)
		{
			return true;
		}
		else if (c1.silver == c2.silver)
		{
			return c1.bronze > c2.bronze;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool isSameRank(country& c1, country& c2)
{
	if ((c1.gold == c2.gold) && (c1.silver == c2.silver) && (c1.bronze == c2.bronze))
	{
		return true;
	}
	return false;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	int num, gold, silver, bronze;
	cin >> N >> K;
	vector<country> v;
	for (int i = 0; i < N; i++)
	{
		cin >> num >> gold >> silver >> bronze;
		v.push_back(country(num, gold, silver, bronze));
	}
	sort(v.begin(), v.end(), cmp);
	int lastRank = 1;
	if (K == v.at(0).countryNum)
	{
		cout << 1 << "\n";
	}
	else
	{
		for (int i = 1; i < N; i++)
		{
			if (isSameRank(v.at(i - 1), v.at(i)) == false)
			{
				lastRank = i + 1;
			}
			if (v.at(i).countryNum == K)
			{
				cout << lastRank << "\n";
				break;
			}
		}
	}
	return 0;
}