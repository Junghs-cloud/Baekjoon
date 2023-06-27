#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	long long atk;
	bool canWin = true;
	cin >> N;
	long long* arr = new long long[N-1];
	cin >> atk;
	for (int i = 1; i < N; i++)
	{
		cin >> arr[i-1];
	}
	sort(arr, arr + N - 1);
	for (int i = 0; i < N - 1; i++)
	{
		if (atk <= arr[i])
		{
			canWin = false;
			break;
		}
		else
		{
			atk += arr[i];
		}
	}
	if (canWin == true)
	{
		cout << "Yes" << "\n";
	}
	else
	{
		cout << "No" << "\n";
	}
	return 0;
}