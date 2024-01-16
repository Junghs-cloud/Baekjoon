#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	int maxA = 0;
	int maxB = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int i = 1; i < N-1; i++)
	{
		maxA = max(maxA, arr[i - 1] + arr[N - 1] - (2 * arr[i]));
	}
	for (int i = 1; i < N-1; i++)
	{
		maxB = max(maxB, (2 * arr[i]) - arr[0] - arr[i + 1]);
	}
	cout << max(maxA, maxB)<< "\n";
	return 0;
}