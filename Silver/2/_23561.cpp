#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[3 * N];
	for (int i = 0; i <3* N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + 3 * N);
	if (N == 1)
	{
		cout << 0 << "\n";
	}
	else
	{
		int startIndex = arr[N];
		int endIndex = arr[2 * N - 1];
		cout << endIndex - startIndex << "\n";
	}
	return 0;
}