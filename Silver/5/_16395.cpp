#include <iostream>

using namespace std;

int main()
{
	int N, K;
	cin >> N >>K;
	int arr[31][31];
	arr[0][0] = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (j == 0 || j == i - 1)
			{
				arr[i][j] = 1;
			}
			else
			{
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
			}
		}
	}
	cout << arr[N][K-1]<<"\n";
	return 0;
}