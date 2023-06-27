#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	long long** arr = new long long*[N]; //0: left, 1: right, 2: empty
	for (int i = 0; i < N; i++)
	{
		arr[i] = new long long[3];
		for (int j = 0; j < 3; j++)
		{
			arr[i][j] = 0;
		}
	}
	arr[0][0] = arr[0][1] = arr[0][2] = 1;
	for (int i = 1; i < N; i++)
	{
		arr[i][0] = (arr[i - 1][1] % 9901) + (arr[i - 1][2] % 9901);
		arr[i][1]= (arr[i - 1][0] % 9901) + (arr[i - 1][2] % 9901);
		arr[i][2] = (arr[i - 1][0] % 9901) + (arr[i - 1][1] % 9901) + (arr[i-1][2] % 9901);
	}
	long long sum = arr[N - 1][0] % 9901 + arr[N - 1][1] % 9901 + arr[N - 1][2] % 9901;
	cout << sum % 9901 << "\n";
	return 0;
}