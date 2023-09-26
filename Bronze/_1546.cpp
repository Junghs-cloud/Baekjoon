#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	double* arr = new double[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	double M = arr[N - 1];
	double sum = 0;
	for (int i = 0; i < N; i++)
	{
		arr[i] = arr[i] / M * 100;
		sum += arr[i];
	}
	double answer = sum / (double) N;
	cout.precision(9);
	cout << fixed;
	cout << answer << "\n";
	return 0;
}