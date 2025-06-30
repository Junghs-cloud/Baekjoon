#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* lengths = new int[N];
	long long* left = new long long[N];
	long long* right = new long long[N];
	long long* selected = new long long[N+1];
	long long minDistance = 1000000000000;
	int answer = 1;
	left[0] = 0;
	right[0] = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> lengths[i];
	}
	for (int i = 1; i < N; i++)
	{
		cin >> left[i];
		left[i] += left[i - 1];
	}
	for (int i = 1; i < N; i++)
	{
		cin >> right[i];
		right[i] += right[i - 1];
	}
	for (int i = 1; i <= N; i++)
	{
		selected[i] = left[i - 1] + right[N - 1] - right[i - 1] + lengths[i - 1];
		if (selected[i] < minDistance)
		{
			minDistance = selected[i];
			answer = i;
		}
	}
	cout << answer <<" "<<minDistance << "\n";
	return 0;
}