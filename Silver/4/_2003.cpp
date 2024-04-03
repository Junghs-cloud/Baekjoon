#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	long long M;
	cin >> N>>M;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int start = 0;
	int end = 0;
	long long sum = 0;
	long long answer = 0;
	while (end < N)
	{
		sum += arr[end];
		while (sum >= M && start <= end )
		{
			if (sum == M)
			{
				answer++;
			}
			sum -= arr[start];
			start++;
		}
		end++;
	}
	cout << answer << "\n";
	return 0;
}