#include <iostream>
using namespace std;

int main()
{
	int K;
	cin >> K;
	long long** arr = new long long*[K + 1];
	for (int i = 0; i < K + 1; i++)
	{
		arr[i] = new long long[2];
	}
	arr[0][0] = 1;
	arr[0][1] = 0;
	for (int i = 1; i < K + 1; i++)
	{
		arr[i][0] = arr[i - 1][1];
		arr[i][1] = arr[i - 1][0] + arr[i-1][1];
	}
	cout << arr[K][0] <<" "<< arr[K][1] << "\n";
	return 0;
}