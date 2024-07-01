#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	long long answer = 0;
	long long prevSums = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		prevSums += abs(arr[i] - arr[0]);
	}
	answer += prevSums;
	for (int i = 1; i < N; i++)
	{
		long long diff = arr[i] - arr[i - 1];
		answer += prevSums + (diff * i) - (diff * (N - i));
		prevSums = prevSums + (diff * i) - (diff * (N - i));
	}
	cout << answer << "\n";
	return 0;
}