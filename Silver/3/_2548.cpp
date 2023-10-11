#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	long long minSum = 900000000;
	int answer = 0;
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		long long current = 0;
		for (int j = 0; j < N; j++)
		{
			current += abs(arr[j] - arr[i]);
		}
		if (current < minSum)
		{
			minSum = current;
			answer = arr[i];
		}
	}
	cout << answer << "\n";
	return 0;
}