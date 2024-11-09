#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

bool cmp(pair<int, int>& p1, pair<int, int>& p2)
{
	int diff1 = p1.first - p1.second;
	int diff2 = p2.first - p2.second;
	if (diff1 > diff2)
	{
		return true;
	}
	else if (diff1 == diff2)
	{
		if (p1.first > p2.first)
		{
			return true;
		}
		else if (p1.first == p2.first)
		{
			return p1.second > p1.second;
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

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, X;
	int answer = 0;
	cin >> N>> X;
	pair<int, int>* arr = new pair<int, int>[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	int maxAMenuSelect = (X - N * 1000) / 4000;
	sort(arr, arr + N, cmp);
	for (int i = 0; i < N; i++)
	{
		if (i < maxAMenuSelect)
		{
			if (arr[i].first >= arr[i].second)
			{
				answer += arr[i].first;
			}
			else
			{
				answer += arr[i].second;
			}
		}
		else
		{
			answer += arr[i].second;
		}
	}
	cout << answer << "\n";
	return 0;
}