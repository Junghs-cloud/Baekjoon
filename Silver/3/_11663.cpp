#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, X, Y;
	cin >> N >> M;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int i = 0; i < M; i++)
	{
		cin >> X >> Y;
		cout << upper_bound(arr, arr + N, Y) - lower_bound(arr, arr + N, X) << "\n";
	}
	return 0;
}