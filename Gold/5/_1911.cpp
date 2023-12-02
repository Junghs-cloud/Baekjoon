#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, L;
	cin >> N >> L;
	long long answer = 0;
	pair<int, int>* arr = new pair<int, int>[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + N);
	int used = (arr[0].second - arr[0].first) / L;
	if ((arr[0].second - arr[0].first) % L!= 0)
	{
		used++;
	}
	int right = arr[0].first + used * L;
	answer += used;
	for (int i = 1; i < N; i++)
	{
		if (arr[i].second <= right)
		{
			continue;
		}
		if (arr[i].first < right)
		{
			used = (arr[i].second - right) / L;
			if ((arr[i].second - right) % L != 0)
			{
				used++;
			}
			answer += used;
			right = right + used*L;
		}
		else
		{
			used= (arr[i].second - arr[i].first) / L;
			if ((arr[i].second - arr[i].first) % L != 0)
			{
				used++;
			}
			answer += used;
			right = arr[i].first + used*L;
		}
	}
	cout << answer << "\n";
	return 0;
}