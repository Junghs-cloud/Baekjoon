#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int L;
	cin >> L;
	int* arr = new int[L + 1];
	int d = 0;
	long long maxSum = 0;
	arr[0] = 0;
	for (int i = 1; i < L + 1; i++)
	{
		cin >> arr[i];
	}
	for (int depth = 1; depth < L+1; depth++)
	{
		long long sum = 0;
		for (int i = depth; i < L + 1; i+=depth)
		{
			sum += arr[i];
		}
		if (sum > maxSum)
		{
			maxSum = sum;
			d = depth;
		}
	}
	cout << d << " "<<maxSum << "\n";
	return 0;
}