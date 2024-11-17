#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, b, a;
	cin >> N>>b>>a;
	int* arr = new int[N];
	long long* originalSum = new long long[N + 1];
	long long* halfSaleSum = new long long[N + 1];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	originalSum[0] = 0;
	halfSaleSum[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		originalSum[i] = originalSum[i - 1] + arr[i - 1];
	}
	for (int i = 1; i <= N; i++)
	{
		if (i <= a)
		{
			halfSaleSum[i] = originalSum[i] / 2;
		}
		else
		{
			long long halfSale = originalSum[i] - originalSum[i - a];
			halfSaleSum[i] = originalSum[i - a] + halfSale / 2;
		}
	}
	cout << upper_bound(halfSaleSum, halfSaleSum + N + 1, b) - halfSaleSum - 1<<"\n";
	return 0;
}