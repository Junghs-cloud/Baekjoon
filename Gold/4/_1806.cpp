#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, S;
	cin >> N >> S;
	long long sum = 0;
	int* arr = new int[N];
	int first = 0;
	int last = 0;
	int answer = 100001;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	if (sum < S)
	{
		cout << 0 << "\n";
	}
	else
	{
		sum = 0;
		while (sum < S && last < N)
		{
			sum += arr[last];
			last++;
		}
		last--;
		if (last - first + 1 < answer)
		{
			answer = last - first+1;
		}
		for (int i = 1; i < N; i++)
		{
			first++;
			sum -= arr[i-1];
			while (sum < S && last < N-1)
			{
				last++;
				sum += arr[last];
			}
			if (sum < S)
			{
				continue;
			}
			if (last - first + 1 < answer)
			{
				answer = last - first +1 ;
			}
		}
		cout << answer << "\n";
	}
	return 0;
}