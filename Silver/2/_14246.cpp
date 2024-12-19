#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	long long answer = 0;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	cin >> K;
	int start = 0;
	int end = -1;
	long long sum = 0;
	while (start < N)
	{
		while (true)
		{
			end++;
			if (end >= N)
			{
				break;
			}
			sum += arr[end];
			if (sum > K)
			{
				answer += N - end;
				break;
			}
		}
		if (end < N)
		{
			sum -= arr[end];
			end--;
		}
		sum -= arr[start];
		start++;
	}
	std::cout << answer << "\n";
	return 0;
}