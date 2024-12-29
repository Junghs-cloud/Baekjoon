#include <iostream>
#include <utility>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	pair<long long, long long>* arr = new pair<long long, long long>[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].second;
	}
	long long time = max(arr[N - 1].first, arr[N - 1].second);
	for (int i = N - 2; i >= 0; i--)
	{
		long long distance = arr[i + 1].first - arr[i].first;
		if (time + distance <= arr[i].second)
		{
			time = arr[i].second;
		}
		else
		{
			time += distance;
		}
	}
	cout << time + arr[0].first << "\n";
	return 0;
}