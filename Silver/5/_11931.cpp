#include <iostream>
#include <algorithm>
using namespace std;

bool compare(const long long& e1, const long long& e2)
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
	int N;
	cin >> N;
	long long* arr = new long long[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N, compare);
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << "\n";
	}
	return 0;
}