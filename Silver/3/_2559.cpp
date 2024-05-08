#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N>>K;
	int* arr = new int[N];
	int* sums = new int[N+1];
	int answer = -20000000;
	sums[0] = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sums[i + 1] = sums[i] + arr[i];
	}
	for (int i = K; i < N+1; i++)
	{
		if (sums[i] - sums[i - K] > answer)
		{
			answer = sums[i] - sums[i - K];
		}
	}
	cout << answer << "\n";
	return 0;
}