#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int>& p1, pair<int, int>& p2)
{
	if (p1.second > p2.second)
	{
		return true;
	}
	else if (p1.second == p2.second)
	{
		return p1.first < p2.first;
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
	cin >> N;
	pair<int, int>* arr = new pair<int, int>[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + N, cmp);
	int answer = arr[0].second - arr[0].first;
	for (int i = 1; i < N; i++)
	{
		if (answer > arr[i].second)
		{
			answer = arr[i].second - arr[i].first;
		}
		else
		{
			answer -= arr[i].first;
		}
	}
	if (answer < 0)
	{
		answer = -1;
	}
	cout << answer<< "\n";
	return 0;
}