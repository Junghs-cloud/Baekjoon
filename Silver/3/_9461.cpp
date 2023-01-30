#include <iostream>
using namespace std;

int main()
{
	int T, N;
	long long * arr = new long long[101];
	arr[1] = arr[2] = arr[3] = 1;
	arr[4] = arr[5] = 2;
	for (int i = 6; i < 101; i++)
	{
		arr[i] = arr[i-1] + arr[i - 5];
	}
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> N;
		cout << arr[N]<<"\n";
	}


	return 0;
}