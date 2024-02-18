#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, D;
	long long answer = 0;
	cin >> N >> D;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int currentHeight = arr[N - 1];
	if (currentHeight == 0)
	{
		cout << 0 << "\n";
	}
	else
	{
		for (int i = 0; i < D; i++)
		{
			int index = lower_bound(arr, arr + N, currentHeight) - arr;
			answer += N - index;
			currentHeight--;
			if (currentHeight == 0)
			{
				break;
			}
		}
		cout << answer << "\n";
	}
	return 0;
}