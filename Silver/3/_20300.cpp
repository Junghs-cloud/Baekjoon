#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	long long answer = -1;
	cin >> N;
	long long* arr = new long long[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	if (N % 2 == 0)
	{
		for (int i = 0; i < N / 2; i++)
		{
			int j = N - 1 - i;
			answer = max(answer, arr[i] + arr[j]);
		}
	}
	else
	{
		answer = arr[N - 1];
		for (int i = 0; i < N / 2; i++)
		{
			int j = N - 2 - i;
			answer = max(answer, arr[i] + arr[j]);
		}
	}
	cout << answer << "\n";
	return 0;
}