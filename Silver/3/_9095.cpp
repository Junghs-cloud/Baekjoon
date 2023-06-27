#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		int* arr = new int[N + 1];
		if (N >= 1)
		{
			arr[0] = 0;
			arr[1] = 1;
		}
		if (N >= 2)
		{
			arr[2] = 1 + arr[1];
		}
		if (N >= 3)
		{
			arr[3] = 1 + arr[1] + arr[2];
		}
		for (int i = 4; i < N + 1; i++)
		{
			arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
		}
		cout << arr[N] << "\n";
	}

	return 0;
}