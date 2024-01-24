#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N>>M;
	int* arr = new int[N];
	int end = 0;
	int answer = 2000000001;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int start = 0; start < N; start++)
	{
		while (end < N - 1 && abs(arr[end] - arr[start]) < M)
		{
			end++;
		}
		int diff = abs(arr[end] - arr[start]);
		if (diff >= M && diff < answer)
		{
			answer = diff;
		}
	}
	cout << answer << "\n";
	return 0;
}