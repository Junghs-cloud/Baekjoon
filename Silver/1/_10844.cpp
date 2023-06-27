#include <iostream>
using namespace std;

int main()
{
	int N;
	int sum = 0;
	cin >> N;
	int** arr = new int*[N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		arr[i] = new int[10];
		for (int j = 0; j < 10; j++)
		{
			arr[i][j] = 0;
		}
	}
	for (int i = 1; i < 10; i++)
	{
		arr[1][i] = 1;
	}
	for (int i = 2; i < N + 1; i++)
	{
		arr[i][0] = arr[i - 1][1];
		for (int j = 1; j <= 8; j++)
		{
			arr[i][j] = (arr[i - 1][j - 1]% 1000000000) + (arr[i - 1][j + 1]% 1000000000);
		}
		arr[i][9] = arr[i - 1][8];
	}
	for (int i = 0; i < 10; i++)
	{
		sum = (sum % 1000000000) + (arr[N][i] % 1000000000);
	}
	cout << sum % 1000000000 << "\n";
	return 0;
}