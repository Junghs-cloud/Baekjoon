#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int Ax;
	long long wantCandies;
	cin >> N >> M;
	long long* arr = new long long[M+1];
	arr[0] = 0;
	for (int i = 1; i < M+1; i++)
	{
		cin >> Ax;
		arr[i] = arr[i - 1] + Ax;

	}
	for (int i = 0; i < N; i++)
	{
		cin >> wantCandies;
		if (wantCandies > arr[M])
		{
			cout << "Go away!" << "\n";
		}
		else
		{
			long long index = lower_bound(arr, arr + M + 1, wantCandies) - arr;
			cout << index << "\n";
		}
	}
	return 0;
}