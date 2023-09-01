#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	long long* arr = new long long[N + 1];
	if (N == 1)
	{
		cout << 0 << "\n";
	}
	else
	{
		arr[0] = 0;
		arr[1] = 0;
		arr[2] = 2;
		for (int i = 3; i < N + 1; i++)
		{
			arr[i] = (3 * arr[i - 1]) % 1000000009;
		}
		cout << arr[N] << "\n";
	}
	return 0;
}