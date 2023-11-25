#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
map<int, int> m;
map<int, int>::iterator it;
long long answer = 0;
vector<int> v;
long long** dp;

void binarySearch(int left, int right, int index1, int index2)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int sum = v.at(index1) + v.at(index2) + v.at(mid);
		if (sum == 0)
		{
			if (mid == index1)
			{
				long long a = m.find(v.at(index1))->second;
				long long b = m.find(v.at(index2))->second;
				answer += dp[a][2] * b;
			}
			else if (mid == index2)
			{
				long long a = m.find(v.at(index1))->second;
				long long b = m.find(v.at(index2))->second;
				answer += a * dp[b][2];
			}
			else if (mid < index2)
			{
				return;
			}
			else
			{
				long long a = m.find(v.at(index1))->second;
				long long b = m.find(v.at(index2))->second;
				long long c = m.find(v.at(mid))->second;
				answer += a * b * c;
			}
			return;
		}
		else if (sum< 0)
		{
			left = mid + 1;
		}
		else if (sum > 0)
		{
			right = mid - 1;
		}
	}

}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, num;
	cin >> N;
	dp = new long long*[10001];
	for (int i = 0; i < 10001; i++)
	{
		dp[i] = new long long[4];
		for (int j = 0; j < 4; j++)
		{
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i < 10001; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			if (j == 1)
			{
				dp[i][j] = i;
			}
			else
			{
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		it = m.find(num);
		if (it == m.end())
		{
			m.insert({ num, 1 });
			v.push_back(num);
		}
		else
		{
			it->second++;
		}
	}
	sort(v.begin(), v.end());
	it = m.find(0);
	if (it != m.end() && it->second >= 3)
	{
		answer += dp[it->second][3];
	}
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			binarySearch(0, v.size()-1, i, j);
		}
	}
	cout << answer << "\n";
	return 0;
}