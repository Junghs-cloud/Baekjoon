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
	int pCount = 0;
	int sCount = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N, greater<>());
	for (int i = 0; i < (N+1)/2; i++)
	{
		pCount += arr[i];
	}
	for (int i = (N + 1) / 2; i < N; i++)
	{
		sCount += arr[i];
	}
	cout <<sCount<<" " << pCount << "\n";
	return 0;
}