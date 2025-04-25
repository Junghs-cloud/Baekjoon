#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	long long* arr = new long long[N];
	long long answer = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		answer += arr[i];
	}
	sort(arr, arr + N);
	long long first = arr[0] * arr[1];
	long long second = arr[N - 2] * arr[N - 1];
	long long compare1 = (first - arr[0]) + (first - arr[1]) + answer;
	long long compare2 = (second - arr[N - 2]) + (second - arr[N - 1]) + answer;
	cout << max({ answer, compare1, compare2 })<<"\n";
	return 0;
}