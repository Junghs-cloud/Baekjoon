#include <iostream>
using namespace std;

int gcd(int x, int y)
{
	if (y == 0)
	{
		return x;
	}
	else
	{
		return gcd(y, x % y);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	long long answer = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int GCD = gcd(arr[1]-arr[0], arr[2]-arr[1]);
	for (int i = 3; i < N; i++)
	{
		GCD = gcd(GCD, arr[i] - arr[i-1]);
	}
	for (int i = 1; i < N; i++)
	{
		int diff = arr[i] - arr[i - 1];
		answer += diff / GCD;
		if (diff % GCD == 0)
		{
			answer--;
		}
	}
	cout << answer << "\n";
	return 0;
}