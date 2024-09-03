#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N;
		int index = 0;
		int answer = 0;
		cin >> N;
		int* arr = new int[N];
		int* order = new int[N];
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + N);
		for (int i = 0; i < N; i += 2)
		{
			order[index] = arr[i];
			index++;
		}
		if (N % 2 == 0)
		{
			for (int i = N - 1; i >= 0; i -= 2)
			{
				order[index] = arr[i];
				index++;
			}
		}
		else
		{
			for (int i = N - 2; i >= 0; i -= 2)
			{
				order[index] = arr[i];
				index++;
			}
		}
		for (int i = 1; i < N; i++)
		{
			answer = max(answer, abs(order[i] - order[i - 1]));
		}
		cout << answer << "\n";
	}
	return 0;
}