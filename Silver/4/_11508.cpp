#include <iostream>
#include <algorithm>
using namespace std;

bool compare(const int& e1, const int& e2)
{
	if (e1 > e2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long sum = 0;
	int N;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N, compare);
	for (int i = 0; i < N; i++)
	{
		if (i % 3 == 2)
		{
			continue;
		}
		else
		{
			sum += arr[i];
		}
	}
	cout << sum << "\n";
	return 0;
}