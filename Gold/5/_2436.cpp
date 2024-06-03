#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;


int GCD(int x, int y)
{
	if (y == 0)
	{
		return x;
	}
	else
	{
		return GCD(y, x % y);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long N, M;
	long long answerA = 100000000;
	long long answerB = 100000000;
	cin >> N >> M;
	vector<long long> v;
	for (int i = 1; i <= sqrt(M); i++)
	{
		if (M % i == 0)
		{
			if (M / i != i)
			{
				v.push_back(M / i);
			}
			v.push_back(i);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i ; j < v.size(); j++)
		{
			long long gcd = GCD(v.at(j), v.at(i));
			long long lcm = (long long) v.at(j) * (long long) v.at(i) / gcd;
			if (gcd == N && lcm == M && v.at(j) + v.at(i) < answerA + answerB)
			{
				answerA = v.at(i);
				answerB = v.at(j);
			}
		}
	}
	cout << answerA << " " << answerB << "\n";
	return 0;
}