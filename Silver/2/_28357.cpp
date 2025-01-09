#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
long long* arr;
long long N, M;
long long answer;

void binarySearch(long long start, long long end)
{
	long long left = start;
	long long right = end;
	while (left <= right)
	{
		long long standard = (left + right) / 2;
		long long candySum = 0;
		for (int i = 0; i < N; i++)
		{
			if (arr[i] < standard)
			{
				continue;
			}
			else
			{
				candySum += arr[i] - standard;
			}
		}
		if (candySum <= M)
		{
			answer = min(answer, standard);
			right = standard - 1;
		}
		else
		{
			left = standard + 1;
		}
	}
}

int main()
{	
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	answer = LLONG_MAX;
	cin >> N >> M;
	arr = new long long[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	binarySearch(0, 1000000000001);
	cout << answer << "\n";
	return 0;
}