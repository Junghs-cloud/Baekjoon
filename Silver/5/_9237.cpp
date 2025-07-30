#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N+1];
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	sort(arr + 1, arr + N+1, greater<int>());
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		answer = max(answer, arr[i] + i);
	}
	cout << answer + 1 << "\n";
	return 0;
}