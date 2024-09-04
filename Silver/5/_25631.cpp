#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int answer = 0;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		int count = upper_bound(arr, arr + N, arr[i]) - lower_bound(arr, arr + N, arr[i]);
		answer = max(answer, count);
	}
	cout << answer << "\n";
	return 0;
}