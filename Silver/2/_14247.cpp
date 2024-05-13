#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	pair<int, int>* arr = new pair<int, int>[N];
	long long answer = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].second;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first;
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		answer += arr[i].first * i + arr[i].second;
	}
	cout << answer << "\n";
	return 0;
}