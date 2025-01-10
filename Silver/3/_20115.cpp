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
	float answer = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int i = 0; i < N - 1; i++)
	{
		answer += (float) arr[i] / 2;
	}
	answer += arr[N-1];
	cout << answer << "\n";
	return 0;
}