#include <iostream>
using namespace std;

int main()
{
	long long N, T, P;
	long long clothesBundleCount = 0;
	long long penBundleCount = 0;
	long long penEA = 0;
	cin >> N;
	long long* arr = new long long[6];
	for (int i = 0; i < 6; i++)
	{
		cin >> arr[i];
	}
	cin >> T >> P;
	for (int i = 0; i < 6; i++)
	{
		clothesBundleCount += arr[i] / T;
		if (arr[i] % T != 0)
		{
			clothesBundleCount++;
		}
	}
	penBundleCount = N / P;
	penEA = N - P * penBundleCount;
	cout << clothesBundleCount << "\n";
	cout << penBundleCount << " " << penEA << "\n";
	return 0;
}