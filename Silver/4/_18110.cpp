#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long N;
	double sum = 0;
	cin >> N;
	if (N == 0)
	{
		cout << 0 << "\n";
	}
	else
	{
		double cut = (double)N * (double) 0.15;
		long long roundedCut = round(cut);
		int* arr = new int[N];
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + N);
		for (int i = roundedCut; i < N - roundedCut; i++)
		{
			sum += arr[i];
		}
		double average = sum / (double)(N - 2 * roundedCut);
		long long answer = round(average);
		cout << answer << "\n";
	}
	return 0;
}