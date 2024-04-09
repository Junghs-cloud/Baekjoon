#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	long long* sums = new long long[N + 1];
	long long answer = 0;
	sums[0] = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sums[i + 1] = sums[i] + arr[i];
	}
	for (int i = 0; i < N - 1; i++)
	{
		answer += arr[i] * (sums[N] - sums[i + 1]);
	}
	cout << answer << "\n";
	return 0;
}