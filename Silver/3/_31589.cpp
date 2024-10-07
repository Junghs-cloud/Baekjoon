#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	int* arr = new int[N];
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int bigger = N - 1;
	int smaller = 0;
	for (int i = 0; i < M; i++)
	{
		if (i % 2 == 0)
		{
			v.push_back(arr[bigger]);
			bigger--;
		}
		else
		{
			v.push_back(arr[smaller]);
			smaller++;
		}
	}
	long long answer = v.at(0);
	for (int i = 1; i < M; i++)
	{
		if (v.at(i) > v.at(i - 1))
		{
			answer += v.at(i) - v.at(i - 1);
		}
	}
	cout << answer << "\n";
	return 0;
}