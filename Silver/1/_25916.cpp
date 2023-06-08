#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int start = 0;
	int end = 0;
	long long partialSum = 0;
	long long answer = 0;
	for (start = 0; start < N; start++)
	{
		while (partialSum <= (long long)M && end < N)
		{
			if (partialSum + (long long) arr[end] > M)
			{
				break;
			}
			partialSum += (long long) arr[end];
			end++;
		}
		if (partialSum > answer)
		{
			answer = partialSum;
		}
		partialSum -= arr[start];

	}
	cout << answer << "\n";
	return 0;
}