#include <iostream>
#include <algorithm>
using namespace std;
long long* arr;
long long A, B, C;
long long minDiff= 4000000000;

void binarySearch(int left, int right, int i, int j)
{
	long long sum = arr[i] + arr[j];
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (sum + arr[mid]== 0)
		{
			A = arr[i];
			B = arr[j];
			C = arr[mid];
			minDiff = abs(arr[mid] + sum);
			break;
		}
		else if (sum + arr[mid] < 0)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
		if (abs(arr[mid] + sum) < minDiff)
		{
			A = arr[i];
			B = arr[j];
			C = arr[mid];
			minDiff = abs(arr[mid] + sum);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	arr = new long long[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int i = 0; i < N-2; i++)
	{
		for (int j = i+1; j < N-1; j++)
		{
			binarySearch(j + 1, N - 1, i, j);
		}
	}
	cout << A << " " << B << " " << C << "\n";
	return 0;
}