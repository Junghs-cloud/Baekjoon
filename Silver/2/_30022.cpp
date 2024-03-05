#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int>& p1, pair<int, int>& p2)
{
	int diff1 = p1.second - p1.first;
	int diff2 = p2.second - p2.first;
	if (diff1 > diff2)
	{
		return true;
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

	int N, A, B;
	int p, q;
	cin >> N >> A >> B;
	pair<int, int>* arr = new pair<int, int>[N];
	long long answer = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> p >> q;
		arr[i] = make_pair(p, q);
	}
	sort(arr, arr + N, cmp);
	for (int i = 0; i < A; i++)
	{
		answer += arr[i].first;
	}
	for (int i = A; i < N;i++)
	{
		answer += arr[i].second;
	}
	cout << answer << "\n";
	return 0;
}