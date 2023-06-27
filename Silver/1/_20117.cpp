#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	int* arr = new int[N];
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int i = 0; i < N / 2; i++)
	{

		sum = sum + (2 * (long long)arr[N - 1 - i]);
	}
	if (N % 2 == 1)
	{
		int midIndex = N / 2;
		sum += (long long)arr[midIndex];
	}
	cout << sum << "\n";
	return 0;
}