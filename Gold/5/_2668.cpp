#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int* arr;
vector<int>* dp;
vector<int>* input;

void check(int num, int max)
{
	if (arr[num] <= max)
	{
		if (find(dp[max].begin(), dp[max].end(), arr[num]) == dp[max].end())
		{
			dp[max].push_back(arr[num]);
			input[max].push_back(num);
			check(arr[num], max);
		}
		return;
	}
	else
	{
		dp[max].clear();
	}
}

int main()
{
	int N;
	cin >> N;
	arr = new int[N+1];
	dp = new vector<int>[N + 1];
	input = new vector<int>[N + 1];
	arr[0] = 0;
	for (int i = 1; i < N+1; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i < N + 1; i++)
	{
		if (i < arr[i])
		{
			continue;
		}
		else if (i > arr[i])
		{
			dp[i].push_back(arr[i]);
			input[i].push_back(i);
			check(arr[i], i);
			sort(dp[i].begin(), dp[i].end());
			sort(input[i].begin(), input[i].end());
			if (dp[i] != input[i])
			{
				dp[i].clear();
			}
			else
			{
				int maxSize = 0;
				int maxIndex = 0;
				for (int j = 0; j < i; j++)
				{
					if (dp[j].size() > maxSize)
					{
						maxSize++;
						maxIndex = j;
					}
				}
				if (maxSize != 0)
				{
					for (int j = 0; j < dp[maxIndex].size(); j++)
					{
						dp[i].push_back(dp[maxIndex].at(j));
					}
				}
			}
		}
		else
		{
			int maxSize = 0;
			int maxIndex = 0;
			for (int j=0; j < i; j ++ )
			{
				if (dp[j].size() > maxSize)
				{
					maxSize++;
					maxIndex = j;
				}
			}
			dp[i] = dp[maxIndex];
			dp[i].push_back(i);
		}
	}
	int maxSize = 0;
	int maxIndex = 0;
	for (int i = 1; i < N + 1; i++)
	{
		if (dp[i].size() >maxSize)
		{
			maxSize = dp[i].size();
			maxIndex = i;
		}
	}
	sort(dp[maxIndex].begin(), dp[maxIndex].end());
	cout << maxSize << "\n";
	for (int i = 0; i < maxSize; i++)
	{
		cout << dp[maxIndex].at(i) << "\n";
	}
	return 0;
}