#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	int* arr = new int[N];
	int* sum = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sum[0] = arr[0];
	for (int i = 1; i < N; i++)
	{
		int maxSum = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && maxSum < sum[j])
			{
				maxSum = sum[j];
			}
		}
		maxSum += arr[i];
		sum[i] = maxSum;
	}
	int finalMax = 0;
	for (int i = 0; i < N; i++)
	{
		if (sum[i] > finalMax)
		{
			finalMax = sum[i];
		}
	}
	cout << finalMax << "\n";
	return 0;
}