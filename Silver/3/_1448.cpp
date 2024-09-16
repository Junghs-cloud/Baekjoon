#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	bool canMake = false;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int i = N - 1; i >= 2; i--)
	{
		if (arr[i] < arr[i - 1] + arr[i - 2])
		{
			canMake = true;
			cout << arr[i] + arr[i - 1] + arr[i - 2];
			break;
		}
	}
	if (canMake == false)
	{
		cout << -1 << "\n";
	}
	return 0;
}