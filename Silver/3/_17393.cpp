#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	long long* arr = new long long[N];
	long long* viscocity = new long long[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> viscocity[i];
	}
	for (int i = 0; i < N; i++)
	{
		int index = upper_bound(viscocity, viscocity + N, arr[i]) - viscocity;
		cout << max(index - i - 1, 0) << " ";
	}
	return 0;
}