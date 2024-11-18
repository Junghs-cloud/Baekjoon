#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int fileSize;
	cin >> N;
	int* arr = new int[N];
	long long answer = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> fileSize;
		arr[i] = 10 * fileSize;
	}
	sort(arr, arr + N);
	for (int i = N-1; i >= 0; i--)
	{
		int counts = i - (lower_bound(arr, arr + N, arr[i] * 0.9) - arr);
		answer += counts;
	}
	cout << answer << "\n";
	return 0;
}